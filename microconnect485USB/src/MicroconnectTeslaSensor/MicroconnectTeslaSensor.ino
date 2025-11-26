
#include <SimpleModbusSlave.h>     //Download : https://github.com/angeloc/simplemodbusng
#include <SoftwareSerial.h>        //Download : https://github.com/PaulStoffregen/SoftwareSerial
#include <DistanceSensor.h>
#define TePin 2                    //Pin zum Umschalten zwischen Senden und Empfangen
byte SlaveID = 4;                  //Geräte ID
SoftwareSerial DebugSerial(4, 3);  //Software Serielle schnitstelle zur kommunikation mit PC zu debiugging zwecken, da die eigentliche schnitstelle für den Modbus ist
unsigned int oldTest2;
unsigned int measurements;
unsigned int distanceAdded;
DistanceSensor<18,17> sensor;


enum {            //Modbus Register
  MB_SLAVEID,     //Adresse des Gerätes. Standardmäßig 230. Kann über Modbus umgestellt werden
  MB_FEHLERZAHL,  //Anzahl Fehler zur Fehlerdiagnose über den Modbus Master.
  //Start der Nutzerdefinierten Modbus Register, hier hinter einfügen
  MB_DISTANCE,
  MB_MEASUREMENTS,
  MB_DISTANCE_AVG,
  //Ende der Nutzerdefinierten Modbus Register
  MB_ANZAHL_REGISTER
  //Anzahl der Register. Dies ist kein Modbus register. Einfach im code lassen
};
unsigned int holdingRegs[MB_ANZAHL_REGISTER];  //Die Holding Register, aufgebaut wie oben spezifiziert
void setup() {
  DebugSerial.begin(9600);//SoftSerial zum Debuggen. Optional
  pinMode(5, INPUT);//Auslesen des Pin5 für den Taster SJ2 auf dem Board
  pinMode(4,OUTPUT);
  digitalWrite(4,0);
  holdingRegs[MB_SLAVEID] = SlaveID;
  SlaveID=4;
  modbus_configure(9600, SlaveID, TePin, MB_ANZAHL_REGISTER, 0);  //Modbus Kommunikation Konfigurieren und Starten
  sensor.begin();
}

void loop() {
  holdingRegs[MB_FEHLERZAHL] = modbus_update(holdingRegs);  //update the holding registers and store potential errors for further debugging

  unsigned int distance=sensor.tick();
  if(distance !=sensor.NREADY)DebugSerial.println(distance);
  if(distance!=sensor.NREADY&&distance!=sensor.ERR){
    holdingRegs[MB_DISTANCE]=distance;
    measurements+=1;
    distanceAdded+=distance;
    holdingRegs[MB_MEASUREMENTS]=measurements;
    if(measurements>10){
      holdingRegs[MB_DISTANCE_AVG]=distanceAdded/measurements;
      measurements=0;
      distanceAdded=0;
    }
  }
}
