# Smart Home System — Project Overview

This project implements a fully integrated smart home security and automation system. It combines fire detection, intrusion detection, gate control, lighting control, and multi-platform monitoring using a variety of sensors, actuators, communication interfaces, and user interfaces.

<img width="642" height="841" alt="smart_home_system_architecture" src="https://github.com/user-attachments/assets/072744fa-2e1a-43f0-8543-f463d0cbea6f" />

---

## Fire & Gas Detection System

The smart home system includes safety mechanisms to detect hazardous conditions:

- Over-temperature detector
- Gas detector (smoke/gas leak detection)
- Automatic alarm activation when fire/gas is detected:
  - Siren
  - Strobe light

---

## Intruder Detection

A motion sensor monitors unauthorized movements inside the home.

If an intruder is detected:

- The alarm system activates (siren + strobe)
- The event is recorded on the SD card
- System status is displayed on the LCD panel

---

## Alarm Control Panel

The alarm system can be controlled from the dedicated control panel.

### User Authentication

- The alarm can be turned off by entering a 4-digit code
- If the code is incorrect:
  - The *Incorrect Code* LED turns on
- After five incorrect attempts:
  - The system enters *blocked mode*
  - The *System Blocked* LED turns on

### LCD Display

The LCD shows:

- Current sensor readings
- Alarm status
- System warnings and messages

### SD Card Storage

- Stores logs of events such as alarms, sensor triggers, and user actions using SPI protocol

### Audio Playback

- Plays a welcome audio message on startup

---

## Gate Control Panel

The system includes a secondary control panel for managing the home’s gate:

- Open and close the gate
- Adjust decorative light intensity
- Automatic lighting adjustment using a light sensor
- Change the color of the decorative light from the alarm control panel

---

## PC Monitoring (USB Serial)

A PC can be connected via USB serial communication to:

- Monitor sensor values
- Configure system settings
- Check alarm status
- View stored events and logs

---

## Smartphone Application (Bluetooth Low Energy)

A smartphone app connected via BLE provides:

- System monitoring
- Access to sensor data
- Gate open/close control
- Alert and notification viewing

---

## Web Interface (Wi-Fi)

The smart home system includes a built-in web server accessible over Wi-Fi.

The web page allows users to:

- Monitor the system in real time
- Access key sensor readings
- Control the gate
- Check alarm status
- Modify configuration settings

The interface is accessible from:

- Smartphones
- PCs
- Tablets

---

## System Features Summary

### Sensors

- Temperature sensor  
- Gas/smoke sensor  
- Motion sensor  
- Light intensity sensor  

### Actuators

- Siren  
- Strobe light  
- Gate motor  
- Decorative RGB light  

### Interfaces

- LCD Display  
- SD Card  
- Audio Playback Module  
- USB Serial  
- Bluetooth Low Energy  
- Wi-Fi Web Server  

