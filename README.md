# 🌊 Ghost Net Detector – BrainChain Project

A smart, solar-powered floating marine device designed to **detect ghost fishing nets** and monitor **real-time water quality** using sensors. This project combines **hardware simulation (Wokwi)** and a **web-based dashboard** to provide actionable alerts for coast guards and marine conservation teams.

---

## 🧩 Problem Statement
create an wed where fisherman report plastic sightings or water quality issues, crowdsourcing pollution monitoring.


**Goal:** To develop a smart, low-cost, solar-powered marine monitoring device that automatically detects ghost nets and monitors pollution parameters like pH, turbidity, and TDS — providing real-time alerts and location tracking.

---

## 🛠️ Tech Stack

| Category       | Tools/Technologies                              |
|----------------|-------------------------------------------------|
| Hardware Sim   | [Wokwi ESP32 Simulator](https://wokwi.com)      |
| Microcontroller| ESP32                                           |
| Sensors        | pH, TDS, Turbidity, Magnetometer, Vibration     |
| Frontend       | HTML, CSS, JavaScript                           |
| Map View       | [Leaflet.js](https://leafletjs.com)             |
| Hosting        | GitHub Pages                                    |

---

## ⚙️ Installation & Setup Instructions
🧪 Requirements
VS Code

Live Server Extension

Internet connection

ThingSpeak Account

ThingSpeak Public Channel: https://thingspeak.com/channels/3011293

(Optional) Wokwi for simulation testing

🔌 For Simulation Setup (Wokwi)
Go to Wokwi.com

Upload the following:

sketch.ino

diagram.json

libraries.txt

Click "Start Simulation"

Add your ThingSpeak Write API Key in the code

Check if data is updating on your ThingSpeak channel

🌐 Website 1: Simulation-Connected Dashboard (web-dashboard)
Open the web-dashboard folder in VS Code

Right-click index.html → click “Open with Live Server”

Features:

📊 Live sensor readings (from ThingSpeak)

📍 Real-time device location (map)

🧠 Analytical reports

⚠️ Ghost net alerts

📝 Detection log

🔧 Future hardware control integration

🌐 Website 2: GhostNet Lite Dashboard (ghostnet-web)
Open the ghostnetdetect.html file in VS Code

Right-click → “Open with Live Server”

Features:

🌊 Displays marine data (Turbidity, TDS, pH, etc.)

🧾 Log of sensor data

📣 Voice alerts for detection (ghost net, animals, pollution)

🌙 Dark/Light mode toggle

📡 Pulls data from ThingSpeak channel 3011293








## ▶️ How to Run the Project

---

### 🧪 A. Hardware Simulation (Wokwi)

1. Go to the Wokwi simulation link:  
   🔗 [Run Device Simulation](https://wokwi.com/projects/436428149476432897)

2. Press the **Play ▶️ button** to start the simulation.

3. Monitor the **Serial Output Console** for:
   - Water quality readings (pH, TDS, Turbidity)
   - Ghost net detection alerts based on simulated sensor data

4. You can tweak sensor values in the code or UI to simulate different conditions (like dirty water or metallic nets).

---

### 🌐 B. Web App

The web interface is under development. Once live, the flow will be:

1. Open the web app in your browser
2. Log in using your credentials
3. View:
   - **Live water quality data**
   - **Ghost net detection alerts**
   - **Real-time map showing device location**

🔗 Web App Link integrates with Wokwi: 



🔗 Web App Link will be integrated with hardware:
(https://faisal-14.github.io/Marine/)
---

### 🛠️ Developer Testing 


1. Open the folder in Visual Studio Code
2. Right-click `index.html` → “Open with Live Server” *(or open it manually in any browser)*
3. Navigate to `dashboard.html` or `map.html` using the links

---

## 🌐 Live Deployment

### 🔌 Hardware Simulation
- [🔗 Wokwi ESP32 + Sensor Simulation](https://wokwi.com/projects/436428149476432897)

### 🖥️ Web Interface





## 📺 YouTube Demo

Watch our full project demo on YouTube:  
[🎥 Click to Watch]





## 👥 Team – BrainChain

| Name        | Role                                 |
|-------------|--------------------------------------|
| Nirmal      | Team Lead & Integration Architect    |
| Paisal      | Hardware Simulation & Sensor Logic   |
| Tamilselvi  | Frontend Development & Styling       |
| Udaya       | UI/UX Design & Map Integration       |

📍 **Institution:** St. Joseph's College of Engineering, Chennai











