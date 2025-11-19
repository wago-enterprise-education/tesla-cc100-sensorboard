# Tesla meets WAGO - WAGO CC100 Sensorboard Workshop

Dieses Repository enthält Unterlagen (Dokumentation, Folien, Code und Laboraufgaben) für den WAGO CC100 Sensorboard Workshop im Rahmen des Besuchs der Tesla Auszubildenden bei WAGO.

## Überblick
Der WAGO CC100 Sensorboard Workshop demonstriert die Anbindung eines [HC-SR04 Ultraschallsensors](https://www.reichelt.de/de/de/shop/produkt/entwicklerboards_-_ultraschall_abstandssensor_hc-sr04-161487) an die [WAGO CC100 Steuerung (751-9301)](https://www.wago.com/de/sps/compact-controller-100/p/751-9301#details) und die und Auswertung auf einem WAGO Anzeigemodul Das 3,3 Volt Signal des Ultraschallsensors wird durch eine [Zusatzplatine](./pcb/) per Modbus über die RS-485 Schnittstelle des WAGO CC100 eingelesen. 

## Verzeichnisstruktur
```
doc/                     Aufgabenstellung und Dokumentation
pcb/                     Dokumentation der Zusatzplatine für den Ultraschallsensor
src/                     CODESYS V3.5 Projekt mit Lösung
```

## Voraussetzungen
Folgende Versionen sind zwingend für Kompatibilität:
- [CODESYS: Version 3.5 SP19 Patch 7](https://downloadcenter.wago.com/wago/software/details/lxdbhtqg2gc6qfbb3mb)
- [WAGO CC100 Firmware: Version V28 (sollte bereits auf WAGO CC100 installiert)](https://downloadcenter.wago.com/wago/software/details/mhn5dlvhyyqb7mcf2y)
- [WAGO Geräte- & Bibliotheksbeschreibung: Version 2.0.6.8](https://downloadcenter.wago.com/wago/software/details/m4mtlydeyuapp4dhe3j)

## Installation des WAGO Device Package in CODESYS V3.5
1. CODESYS V3.5 SP19 Patch 7 installieren
2. CODESYS V3.5 mit Administratorrechten starten
3. Im Menü: Tools > CODESYS Installer > "Datei(en) installieren"
4. `WAGO_Devices_and_Libraries_2.0.6.8.package` Datei auswählen