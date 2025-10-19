# 🏠 iRoom – Smart Occupancy Tracking System

## 🌟 Overview
**iRoom** is an IoT-based smart monitoring system designed for the **Smart Campus Challenge – IEEE SEACAS Hackathon 2022**.  
The system automatically **detects room occupancy** using **dual IR sensors**, measures **temperature and humidity**, and controls **lights and doors** intelligently. All collected data are **uploaded to Firebase** and displayed in **real-time** on a custom web dashboard.

> 🧠 The goal is to improve energy efficiency, comfort, and safety by automatically managing lights and appliances when no one is present.

---

## 🚀 Key Features
- 👥 **Occupancy tracking** without using cameras – based on two IR sensors to detect **entry and exit direction**.  
- 💡 **Smart automation** – automatically turns lights off or closes doors when no occupants are detected.  
- 🌡️ **Environmental monitoring** – continuously uploads temperature and humidity data.  
- ☁️ **Firebase integration** – all data are synced to Firebase for **real-time web visualization**.  
- 🧽 **Low-cost, scalable solution** – built using ESP32-C3 and basic sensors (~$6.35 total).

---

## ⚙️ Hardware Components
| Component | Description | Approx. Cost (USD) |
|------------|--------------|--------------------|
| ESP32-C3 | Wi-Fi + BLE microcontroller | 1.95 |
| IR Sensors (x2) | Directional occupancy detection | 2.88 |
| DHT11 Sensor | Temperature & humidity measurement | 1.42 |
| LED Light | Room light simulation | 0.10 |
| **Total** |  | **6.35** |

---

## 🔌 System Architecture
1. **IR Sensors** positioned at the entrance detect people entering or leaving.  
   - Sensor A → Sensor B → **Entering**
   - Sensor B → Sensor A → **Leaving**
2. **ESP32** counts the number of people in the room.  
3. **DHT11** measures the temperature and humidity.  
4. **Firebase Realtime Database** stores the data.  
5. **Web Dashboard** displays:
   - Number of people inside  
   - Temperature (°C)  
   - Humidity (%)  
   - Light ON/OFF status  

---

## 🧩 File Structure
```
iRoom/
├── iRoom.ino                  # Main Arduino source code (ESP32C3 + Firebase)
├── /images/                   # Prototype and demo pictures
├── iRoom_Presentation.pdf     # Project slides (IEEE SEACAS 2022)
├── SEACAS_Hackathon_Info.pdf  # Hackathon background
└── README.md                  # This file
```

> 🔠 Rename your code file as **`iRoom.ino`** (recommended) instead of `demo4.ino` for clarity.

---

## 🌐 Web Dashboard
The web interface is built to:
- Display **real-time data** from Firebase
- Show **number of occupants**, **temperature**, and **humidity**
- Update automatically when new sensor data are received

---

## 🔥 Firebase Setup
1. Create a Firebase Realtime Database project.
2. Add your **database URL**, **API key**, and **Wi-Fi credentials** in the code.
3. Upload the code to ESP32-C3.
4. Access the live dashboard to monitor updates.

Example configuration block:
```cpp
#define WIFI_SSID "your_wifi_name"
#define WIFI_PASSWORD "your_wifi_password"
#define FIREBASE_HOST "your_project_id.firebaseio.com"
#define FIREBASE_AUTH "your_database_secret"
```

---

## 🧠 Future Improvements
- Handle multiple people entering/exiting simultaneously.  
- Optimize IR distance calibration.  
- Add motion sensors and CO₂ monitoring.  
- Extend to hallways and dormitories for campus-wide integration.  

---

## 🌟 IEEE SEACAS Hackathon 2022
- **Team 6: “iRoom – Smart Campus Automation”**  
  - 🇻🇳 Long Nguyen Khac (Vietnam National University)  
  - 🇵🇭 Marcus Joseph Reyes (University of the Philippines Diliman)  
  - 🇹🇭 Wiphoothorn Sangangam (Kasetsart University, Thailand)  

- Category: *Smart Campus Automation*  
- Merit: *Energy Efficiency and Quality of Life Improvement*  

---

## 🖼️ Demo & Prototype
> 🔗 [Project Slides (PDF)](iRoom_Presentation.pdf)  
> 🔗 [Hackathon Info (PDF)](SEACAS_Hackathon_Info.pdf)

---

## 🛠️ Tools & Libraries
- Arduino IDE  
- Firebase ESP Client  
- DHT11 Sensor Library  
- ESP32 WiFi Library  

---

## 📜 License
MIT License © 2022 IEEE SEACAS Hackathon Team 6  
Developed for educational and research purposes.

