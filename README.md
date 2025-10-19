# iRoom – Smart Occupancy Tracking System (IEEE SEACAS 2022)

The project was built for **THE 2022 SOUTH-EAST ASIA CIRCUIT AND SYSTEM SOCIETY HACKATHON (IEEE SEACAS 2022)** organized in Viet Nam.

> **Idea**: *iRoom* automatically monitors people entering/leaving a room, tracks **temperature** and **humidity**, and **turns off lights / closes door** when no one is inside. All telemetry (occupancy, temperature, humidity) is **pushed to Firebase** and displayed **real‑time** on a web dashboard.

---

##  Achievement
**🏅 Awarded “Fighting Spirit Prize” – IEEE SEACAS Hackathon 2022**  
> Recognized for outstanding teamwork, innovation, and practical implementation of IoT-based smart room technology among international teams from Vietnam, Thailand, and the Philippines.

---

## Contributors
1. **Long Nguyen Khac**, Vietnam National University, Viet Nam  
2. **Marcus Joseph L. Reyes**, University of the Philippines Diliman, Philippines  
3. **Wiphoothorn Sangangam**, Kasetsart University, Thailand


---

## Introduction
Manual switching often leaves lights and appliances **on in empty rooms**, wasting energy and reducing equipment lifespan. In smart campus scenarios (classrooms, labs, bathrooms, dorms), a **privacy‑preserving** occupancy tracker that also monitors environmental conditions can **reduce power consumption**, **improve comfort**, and **streamline facility management**.

---

## What is iRoom?
**iRoom** is an **automatic occupancy‑aware room controller** that:
- Detects **entry/exit** using **two IR sensors** mounted near the doorway (directional logic).  
- **Counts people** currently inside.  
- **Switches lights/door** according to occupancy.  
- Tracks **temperature/humidity** and **uploads** all data to **Firebase** for a **real-time web dashboard**.

---

## Objectives
1. **Enhance energy efficiency** via automatic light/door control.  
2. **Preserve privacy** by avoiding cameras; use IR beam/sensors instead.  
3. **Provide real-time monitoring** of occupancy, temperature, and humidity.  
4. **Enable scalability** for multiple rooms on a smart campus.  
5. **Offer a low bill of materials (BOM)** for practical deployment.

---

## Operation
1. Two IR sensors are placed at the entrance. The **trigger order** encodes **direction**:  
   - **Sensor A → Sensor B** → *Entering*  
   - **Sensor B → Sensor A** → *Leaving*  
2. The **ESP32‑C3** maintains a **people‑inside counter**.  
3. The **DHT11** sensor provides temperature/humidity.  
4. When **people‑inside = 0**, the system **turns off lights** and can **close door** (relay/servo).  
5. All metrics are **published to Firebase** (Realtime Database) and shown on the **web dashboard** in real time.

---

## Modules (Hardware)
- **ESP32‑C3‑32S** (Wi‑Fi + BLE)  
- **IR Sensors x2** (directional occupancy detection)  
- **DHT11** (temperature & humidity)  
- **LED / Relay** (simulate or control lights/door)  
- **TFT/LCD (I2C)** for local status display

> **Approx. cost** (prototype): ~ **$6.35** (ESP32‑C3, IR sensors x2, DHT11, LED)

---

## Data & Web (Firebase + Dashboard)
- **Firebase Realtime Database** stores:  
  ```json
  {
    "iroom": {
      "occupancy": 2,
      "temperature_c": 28.1,
      "humidity_pct": 72,
      "light_on": true,
      "updated_at": 1700000000
    }
  }
  ```
- **Web dashboard** subscribes to the database and renders **live occupancy**, **temperature**, **humidity**, and **light/door state**.

---

## File Structure
```
iRoom/
├── iRoom.ino                  # Main Arduino code (ESP32‑C3 + Firebase + IR + DHT11)
├── /images/                   # Prototype & demo images
├── SEACAS Hackathon 2022-TXT.pdf     # Hackathon background (agenda, rules) (IEEE SEACAS 2022)
├── iRooms_Slide.pdf  # Hackathon background # Project presentation slides
└── README.md                  # This file
```

> **Recommended code filename**: `iRoom.ino` (instead of `demo4.ino`).

---

## Setup & Configuration
1. **Hardware wiring**: mount two IR sensors at the doorway; connect DHT11 and LED/relay to ESP32‑C3 GPIOs.  
2. **Arduino IDE**: install ESP32 boards and required libraries (*WiFi*, *Firebase ESP Client*, *DHT*).  
3. **Firebase**: create a Realtime Database → get **Database URL** & **Auth/keys**.  
4. **Configure credentials** in code:
   ```cpp
   #define WIFI_SSID       "your_wifi_name"
   #define WIFI_PASSWORD   "your_wifi_password"
   #define FIREBASE_HOST   "your_project_id.firebaseio.com"
   #define FIREBASE_AUTH   "your_database_secret_or_token"
   ```
5. **Upload** code to the ESP32‑C3 and open the **web dashboard** to view real‑time data.

---

## Future Improvements
- Handle **simultaneous multi‑person** crossings (debounce, timing windows, ML filter).  
- **Calibration** tools for IR sensor spacing and thresholds.  
- Add **motion/CO₂** sensors and **HVAC control** logic.  
- **Multi‑room** deployment with per‑room namespaces in Firebase.  
- **Role‑based dashboard** (admin, facility manager, student).  

---

## Acknowledgements
Built for **IEEE SEACAS Hackathon 2022** (Hanoi, Viet Nam). Thanks to organizers, mentors, and volunteers for hardware kits and guidance.

---

## License
MIT License © 2022 iRoom Team 6  
Developed for educational and research purposes.

