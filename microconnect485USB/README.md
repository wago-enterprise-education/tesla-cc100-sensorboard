# Microconnect 485 USB - Zusatzplatine für HC-SR04 Ultraschallsensor

Diese Zusatzplatine ermöglicht die Anbindung eines HC-SR04 Ultraschallsensors an die WAGO CC100 Steuerung über RS-485. Die Platine liest das 3,3V Signal des Sensors ein und stellt es über Modbus zur Verfügung um so eine Einbindung in die WAGO CC100 Steuerung zu ermöglichen.

## Verzeichnisstruktur

```
pcb/                     PCB-Dokumentation und Fertigungsunterlagen
├── bom.xlsx            Bill of Materials (Excel-Format)
├── positions.csv       Bestückungsdaten
├── MEGA485 PROJECT.zip KiCad Projektdateien
└── MEGA485GERBER.zip   Gerber-Dateien für die Platinenfertigung
src/                    Board-spezifische Dateien und Arduino-Projekt
├── Microconnect Boarddateien/
│   ├── boards.txt      Arduino Board-Definition
│   └── optiboot_Microconnect.hex  Bootloader-Datei
└── MicroconnectTeslaSensor/
    └── MicroconnectTeslaSensor.ino  Arduino Sketch für die Platine
```

## Installation der Board-Dateien

### Arduino Board-Definition installieren

Um die Platine als Arduino Board verwenden zu können, müssen die Board-Dateien in die Arduino IDE integriert werden:

1. **Board-Definition hinzufügen:**
   - Inhalt der Datei `src/Microconnect Boarddateien/boards.txt` kopieren
   - An das Ende der bestehenden `boards.txt` im Arduino Board-Paket einfügen
   - Pfad unter Windows: `C:\Users\<Nutzer>\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\boards.txt`

2. **Bootloader installieren:**
   - Bootloader-Datei in den entsprechenden Ordner kopieren
   - Pfad unter Windows: `C:\Users\<Nutzer>\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\bootloaders`

### Verwendung

Nach der Installation kann die Platine wie ein normaler Arduino verwendet werden:
- Board-Auswahl in der Arduino IDE möglich (vorausgesetzt der Bootloader ist installiert)
- COM-Port wird automatisch erkannt
- Programmierung erfolgt wie bei Standard-Arduinos

## PCB-Fertigung

### Bill of Materials (BOM)

Bei der Fertigung mit JLCPCB gab es zunächst Probleme mit dem BOM-Format:

**Problem:** JLCPCB konnte die ursprüngliche BOM nicht korrekt auslesen

**Lösung:** 
- Verwendung des **JLCPCB Fabrication Plugins** in KiCad für das korrekte BOM-Format
- Manuelle Komponentenauswahl erforderlich (Hersteller, Preis, Qualität, etc.)
- Diese Auswahl kann nicht direkt aus KiCad getroffen werden