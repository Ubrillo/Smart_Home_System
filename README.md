# Smart Home System — Project Overview

This project implements a fully integrated smart home security and automation system. It combines fire detection, intrusion detection, gate control, lighting control, and multi-platform monitoring using a variety of sensors, actuators, communication interfaces, and user interfaces.

<img width="627" height="831" alt="smart_home_system_file_structure" src="https://github.com/user-attachments/assets/bf983f69-9794-489b-be81-184dca558910" />

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

- Stores logs of events such as alarms, sensor triggers, and user actions using the SPI protocol  

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

Accessible via:

- Smartphones  
- PCs  
- Tablets
- <img width="612" height="414" alt="web_server" src="https://github.com/user-attachments/assets/721831b0-27fc-424e-ba54-7b95c4fb9b77" style="border:2px  solid black;" />



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


---

## Hardware Used  
*(Moved to Bottom)*

### Main Controller & Boards
- **LPC1768 Microcontroller**  
- **LPCXpresso App Board**  

### Sensors
- **MQ-2 Gas Sensor** (gas/smoke detection)  
- **Temperature Sensor (App Board)**  
- **LDR Light Sensor** (light intensity monitoring)  
- **PIR Motion Sensor Module** (intruder detection)  

### User Input
- **4x4 Matrix Keypad** (alarm code entry)  
- **App Board Potentiometer** (brightness control)
- **I2C I/O Expander**

### Displays & Indicators
- **Character-Based LCD Display**  
- **Incorrect Code LED**  
- **System Blocked LED**  

### Storage & Audio
- **SD Card Module (SPI)**  
- **App Board Speaker**  

### Wireless Communication
- **HM-10 Bluetooth Low Energy Module**  
- **ESP-01 (ESP8266) Wi-Fi Module**  

### Actuators
- **Siren**  
- **Strobe Light**  
- **Gate Motor**  
- **Decorative RGB Light**

---
![smart_home_hardware_connection](https://github.com/user-attachments/assets/7ddfd0e4-2229-4b6d-a731-d121db81b937)


