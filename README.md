# 📚 IoT-Based Library Management & Reservation System

This project presents an **IoT-based library management and reservation system** designed to solve common problems faced by students in libraries, such as finding available study space and managing seat reservations efficiently.

The system integrates **web, mobile, and hardware (IoT)** components to create a smart and automated environment for both students and library staff.

---

## 🚀 Overview

During exam periods, libraries become crowded, and students often struggle to find available seats. Additionally, some students occupy seats without using them, making it difficult for others to access space.

This project aims to solve these problems using:
- Real-time seat tracking
- Reservation system
- RFID-based authentication
- IoT hardware integration

---

## ❗ Problem Statement

- Students cannot easily find available seats in the library  
- Seats are occupied unfairly (left with belongings but unused)  
- Library staff cannot efficiently monitor seat usage  
- No real-time system exists to manage study spaces  

---

## 💡 Proposed Solution

We developed a **smart IoT-based system** that includes:

- A **web and mobile application** for reservations  
- A **real-time seat tracking system**  
- **RFID-based verification** for physical check-in  
- IoT devices to monitor and update seat status  

### Key Features:
- Reserve seats in advance  
- View available seats in real time  
- Authenticate using:
  - Email/Login  
  - Student ID  
  - RFID card  
- Walk-in usage with RFID (no reservation required)  
- Real-time updates using cloud database  

---

## 🧠 System Workflow

1. User registers or logs into the system  
2. User selects a seat from the library layout  
3. System checks availability in real time  
4. If available → reservation is created  
5. At the library:
   - User verifies identity (RFID / login / student ID)  
6. Session starts and seat is marked as occupied  
7. If no reservation:
   - User scans RFID at desk → system marks seat as occupied  

---

## 🛠️ Technologies Used

### 🌐 Web Application
- React.js  
- JSX components (Home, Login, Reservation, Timer, etc.)

### 📱 Mobile Application
- React Native (Expo)

### ☁️ Backend / Cloud
- Firebase:
  - Authentication  
  - Realtime Database  
  - Firestore  

### 🔌 Hardware (IoT)
- NodeMCU (ESP8266)  
- RFID-RC522 Module  
- RFID Cards/Tags  

### 💻 Development Tools
- Visual Studio Code  
- Arduino IDE  

---

## 🖼️ Screenshots & System Diagrams

<p align="center">
  <img src="https://raw.githubusercontent.com/MAHI-HAKIM/smart-RFID-library-system/main/screenshots/homepage.png" width="30%" />
  <img src="https://raw.githubusercontent.com/MAHI-HAKIM/smart-RFID-library-system/main/screenshots/reservation_page.png" width="30%" />
  <img src="https://raw.githubusercontent.com/MAHI-HAKIM/smart-RFID-library-system/main/screenshots/Firebase.png" width="30%" />
</p>

### 🔌 Hardware & Architecture

<p align="center">
  <img src="https://raw.githubusercontent.com/MAHI-HAKIM/smart-RFID-library-system/main/screenshots/RFID-MODEL.png" width="45%" />
  <img src="https://raw.githubusercontent.com/MAHI-HAKIM/smart-RFID-library-system/main/screenshots/connection_method.png" width="45%" />
</p>

---

## 🧱 System Architecture

- **Frontend (Web & Mobile)** → User interaction  
- **Firebase** → Real-time data + authentication  
- **IoT Devices** → Seat status detection  
- **RFID System** → Physical verification  

---

## 📊 Business Model

### Usage Scenarios:
1. **Reservation-Based Usage**
   - User books a seat in advance  
   - Verifies identity at the library  

2. **Walk-in Usage**
   - User finds a free seat  
   - Scans RFID → seat marked as occupied  

### Target Users:
- University students  
- Library staff  

### Value:
- Saves time for students  
- Improves seat utilization  
- Helps staff monitor space efficiently  

---

## 📈 Big Data Analysis Potential

This system can generate valuable insights such as:
- Peak library usage times  
- Most popular days/hours  
- Seat usage patterns  

Possible applications:
- Optimize cleaning schedules  
- Improve space management  
- Support research and analytics  

---

## 🔮 Future Improvements

- Advanced analytics dashboard  
- Multi-library support  
- AI-based seat prediction  
- Enhanced security & data monitoring  

---

## 🌟 Vision

This project aims to transform traditional libraries into **smart, efficient, and data-driven environments** using IoT and modern web technologies.
