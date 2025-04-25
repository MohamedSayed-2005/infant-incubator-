# Infant Incubator Monitoring System: Detailed Setup Guide

This guide provides step-by-step instructions for setting up your Arduino-based infant incubator monitoring system.

## Table of Contents
- [Hardware Assembly](#hardware-assembly)
- [Software Installation](#software-installation)
- [Testing the System](#testing-the-system)
- [Troubleshooting](#troubleshooting)
- [Safety Precautions](#safety-precautions)

## Hardware Assembly

### 1. Connect the Pulse Sensor
- Connect the signal pin to Arduino A0
- Connect VCC to Arduino 5V
- Connect GND to Arduino GND

### 2. Connect the DHT11 Temperature/Humidity Sensor
- Connect the data pin to Arduino D2
- Connect VCC to Arduino 5V (or 3.3V if your sensor requires)
- Connect GND to Arduino GND

### 3. Connect the OLED Display
- Connect SDA to Arduino A4
- Connect SCL to Arduino A5
- Connect VCC to Arduino 5V (or 3.3V if your display requires)
- Connect GND to Arduino GND

### 4. Connect the Fan Control Circuit
- Connect the fan control pin to Arduino D9
- If using a motor driver:
  - Connect IN1/IN2 pins as needed
  - Connect driver power and ground
  - Connect motor outputs to fan

### 5. Connect the Relay Module (for Lamp)
- Connect signal pin to Arduino D8
- Connect VCC to Arduino 5V
- Connect GND to Arduino GND
- Connect the lamp to the relay's normally open terminal
- Connect lamp power supply to relay's common terminal

### 6. Connect the Buzzer
- Connect positive pin to Arduino D7
- Connect negative pin to Arduino GND

### 7. Final Assembly Notes
- Ensure all connections are secure and properly insulated
- Mount temperature sensor inside the incubator area
- Position the fan and lamp for optimal airflow and heating
- Secure all components to prevent accidental disconnection
- Consider using a project box to house electronics away from the incubator area

## Software Installation

### 1. Install Required Libraries
Open Arduino IDE and install the following libraries through Library Manager (Tools > Manage Libraries):
- PulseSensorPlayground
- Adafruit_GFX
- Adafruit_SSD1306
- DHT Sensor Library (by Adafruit)

### 2. Upload the Code
- Connect your Arduino to your computer via USB
- Open the InfantIncubatorMonitor.ino file in Arduino IDE
- Select your Arduino board type (Tools > Board)
- Select the correct port (Tools > Port)
- Click Upload

## Testing the System

### 1. Initial Power-Up Test
- Connect Arduino to USB power (or external power supply)
- The OLED should initialize and display the interface
- Verify that temperature, humidity readings appear (even if not accurate yet)

### 2. Pulse Sensor Test
- Place your finger on the pulse sensor
- The BPM reading should update and show values between 60-100 BPM
- Verify that the BPM resets to 0 when no finger is detected for more than 2 seconds

### 3. Temperature and Humidity Sensor Test
- Verify readings change when you breathe on the sensor (both temp and humidity should increase)
- Check if the displayed values are reasonable for room conditions

### 4. Control System Test
- Monitor how the system responds to temperature changes:
  - Warm the DHT11 sensor slightly to >37.5°C (using your hand)
  - Verify fan activates and lamp relay turns off
  - Cool the DHT11 sensor slightly to <36.5°C
  - Verify lamp relay activates and fan operates for circulation
- Test alarm by cooling sensor below 33°C or heating above 37°C
  - Buzzer should sound intermittently

## Troubleshooting

### Pulse Sensor Issues
- No BPM readings:
  - Check analog pin connection
  - Adjust `THRESHOLD` value (lower if not detecting, higher if too sensitive)
  - Ensure adequate lighting (sensor works better in well-lit conditions)
  - Try repositioning the sensor

### Temperature/Humidity Sensor Issues
- "Failed to read from DHT sensor" message:
  - Check wiring, particularly the data pin
  - Try different DHT11 library if issues persist
  - Verify sensor isn't damaged (they are relatively fragile)

### OLED Display Not Working
- Check I2C address (default 0x3C, might be 0x3D on some displays)
- Verify Wire connections to A4/A5
- Confirm library installation

### Relay/Fan Control Issues
- Fan not activating:
  - Check PWM pin connection
  - Verify motor driver configuration
  - Ensure adequate power supply for the fan
- Relay not switching:
  - Listen for clicking sound when relay should activate
  - Check digital pin connection
  - Verify relay module is powered properly

### System Resets or Behaves Erratically
- Ensure adequate power supply for all components
- Add capacitors near power inputs to reduce noise
- Separate digital and analog grounds if possible

## Safety Precautions

### Electrical Safety
- Isolate mains voltage components (heating lamp) completely
- Use low-voltage DC power sources whenever possible
- Include fuses for overcurrent protection
- Double-check all wiring before powering on

### Thermal Safety
- Include secondary over-temperature protection mechanisms
- Position heating elements to prevent direct contact with any materials
- Monitor temperature from multiple points if possible

### General Safety
- This system is for educational purposes only
- Any real application would require significant additional safety mechanisms
- Never leave the system unattended during operation
- Consider adding battery backup for critical monitoring components
