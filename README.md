# 🤖 WaterX - Autonomous Water Surface Cleaning Robot - presented at SIH 2024 - won 2nd position at college internal level

A smart Arduino-powered catamaran robot designed to autonomously clean water surfaces using a combination of brushless motors, servos, sensors, and real-time GPS tracking. This robot is a part of an ongoing hardware-software integration project and the code will be frequently updated.

## 🚀 Project Overview

WaterX is an autonomous robotic platform designed for waterbody maintenance and pollution control. It includes obstacle detection, variable strainer control, servo-based sweeping, camera activation, and GPS-based tracking, all controlled via an Arduino board. The robot uses sonar for proximity sensing, and servos to adapt its trash collection mechanism dynamically.

---

## 🎯 Features

| Feature                        | Description                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| 🌀 **BLDC Propulsion Control** | Controlled via ESCs for forward motion at adjustable speeds                 |
| 📡 **Ultrasonic Sensor**       | Real-time obstacle detection and motor response                             |
| 🔁 **Servo Sweeping**         | Bidirectional sweeping mechanism for trash gathering                        |
| 🧠 **Smart Strainer System**  | Dynamically adjusts based on object proximity                              |
| 🎥 **Camera Trigger Control** | Simulated activation of camera module                                      |
| 📍 **GPS Integration**        | NEO-6M GPS module for location logging, satellite count, HDOP               |
| 💾 **Modular Structure**       | Easily extendable and structured code using libraries and pin mapping       |
| 🔄 **Loop-based Execution**   | Responsive control flow with feedback from sensors and conditionals         |

---

## 🔧 Hardware Used

- Arduino Uno
- A2212/10T 1400KV Brushless Motor + 30A ESC
- SG90 & MG996R Servo Motors
- HC-SR04 Ultrasonic Sensor
- NEO-6M GPS Module
- OV Camera Module (simulated via pin)
- 18650 Li-ion Battery Pack
- Motor Driver Module
- Custom Varied Length Strainer Assembly
- Catamaran Base with Propeller Setup

---

## 📌 Future Plans

- Add wireless control (via ESP8266 or NRF24L01)
- Integrate cloud logging for GPS trails
- Connect camera module for real-time video feed
- Solar-based power optimization

---

## 🧪 Status

**🛠️ Under Active Development** – Check back for code and hardware improvements. Contributions are welcome!

---
## 🤝 Contributors

- **Nikeeta Jha**
- A.S. Susanna Grace
- Suhani Singh
- Pooja Sharma
- Sompriya Narayana Tiwary
  *HMR Institute of Technology & Management*

---

## Screenshots 

![image](https://github.com/user-attachments/assets/0f591726-f2b5-4a06-ae5c-11700bb2baaa)
![Screenshot 2024-09-10 004258](https://github.com/user-attachments/assets/39eab0b9-c627-4324-8d74-e0926bea0a2d)
![Screenshot 2024-09-10 001317](https://github.com/user-attachments/assets/bf39ad20-ed51-492c-909c-df671bc4441f)
![WhatsApp Image 2025-03-13 at 16 35 52_c4ea266c](https://github.com/user-attachments/assets/d75bc6c4-4342-45fc-b1f9-00924059b59a)
![WhatsApp Image 2025-03-13 at 16 35 55_03d55fa9](https://github.com/user-attachments/assets/06168a39-89d7-4307-994f-37669f6415a4)


### 📍 GPS Serial Output:
```plaintext
--- GPS Data ---
Latitude: 28.654321
Longitude: 77.123456
Satellites: 7
HDOP: 150


