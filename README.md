# ESP32 Web-Based Servo Motor Control

## Overview
This project demonstrates how to control a servo motor through a web page hosted on an ESP32 operating in Access Point (AP) mode. The ESP32 creates its own Wi-Fi network, allowing a user to connect directly and control the servo using a web browser.

When the Open button is pressed:
- The servo rotates to the open position (90°).
- The blue LED turns ON.
- The red LED turns OFF.

When the Close button is pressed:
- The servo returns to the closed position (0°).
- The red LED turns ON.
- The blue LED turns OFF.

---

## Features
- ESP32 configured as a Wi-Fi Access Point.
- Built-in web server hosted on the ESP32.
- Web interface with Open and Close buttons.
- Servo motor control through a browser.
- LED status indication for each state.

---

## Components Used
- ESP32 Development Board
- Servo Motor (SG90 or similar)
- Red LED
- Blue LED
- 2 × 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Servo Signal | GPIO 18 |
| Blue LED | GPIO 26 |
| Red LED | GPIO 27 |
| Servo VCC | 5V |
| Servo GND | GND |

---

## How It Works

1. The ESP32 starts in Access Point mode.
2. A web server runs on the ESP32.
3. Users connect to the ESP32 Wi-Fi network.
4. Opening the IP address (`192.168.4.1`) displays the control page.
5. Pressing Open or Close sends an HTTP request to the ESP32.
6. The ESP32 processes the request, moves the servo, and updates the LEDs.

---

## Wi-Fi Information

SSID
ESP32_Control

Password
12345678

Web Address
http://192.168.4.1

---

## Project Demonstration
The project was first simulated using Wokwi, then uploaded and tested successfully on a real ESP32 development board.

---

## Note
> The original project specification required a green LED. Since one was not available during hardware implementation, a blue LED was used instead. The blue LED performs exactly the same function as the intended green LED without affecting the project's operation.

---

## Future Improvements
- Display the current door status (Open / Closed).
- Add password authentication for the web page.
- Support controlling multiple servo motors.
- Improve the web interface with animations and responsive design.

---

## Simulation
https://wokwi.com/projects/471450526705915905
