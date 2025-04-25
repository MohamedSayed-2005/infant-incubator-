# Infant Incubator Monitoring System

An Arduino-based infant incubator monitoring and control system with heart rate detection, temperature/humidity monitoring, and automatic environmental regulation.

## Overview

This project creates a comprehensive monitoring system for infant incubators, focusing on:
- Heart rate (pulse) detection and monitoring
- Temperature and humidity sensing
- Automatic temperature regulation via heating lamp and cooling fan
- Alert system for abnormal conditions
- Real-time status display on OLED

## Hardware Components

- Arduino Uno/Nano/Mega
- Pulse Sensor
- DHT11 Temperature and Humidity Sensor
- SSD1306 OLED Display (128x64)
- Fan with Motor Driver
- Relay Module (for heating lamp control)
- Buzzer (for alerts)
- Jumper wires and breadboard
- Power supply

## Pin Configuration

| Component | Pin |
|-----------|-----|
| Pulse Sensor | A0 |
| DHT11 Sensor | D2 |
| Buzzer | D7 |
| Relay (Lamp) | D8 |
| Fan Control | D9 |
| OLED SDA | A4 |
| OLED SCL | A5 |

## Features

- **Heart Rate Monitoring**: Continuously monitors infant's heart rate with smoothing algorithm
- **Temperature Control**: Maintains optimal temperature between 36.5°C and 37.5°C
- **Humidity Monitoring**: Tracks humidity levels in the incubator
- **Automatic Environmental Control**:
  - Activates heating lamp when temperature falls below 36.5°C
  - Activates cooling fan when temperature rises above 37.5°C
- **Alarm System**: Buzzer alerts for temperature below 33°C or above 37°C
- **Real-time Display**: OLED shows heart rate, temperature, and humidity readings

## Installation and Setup

1. Connect all components according to the pin configuration
2. Install required libraries:
   - PulseSensorPlayground
   - Adafruit_GFX
   - Adafruit_SSD1306
   - DHT
   - Wire
3. Upload the code to your Arduino
4. Place the pulse sensor appropriately for heart rate detection
5. Position the DHT11 sensor inside the incubator
6. Connect and position fan and heating lamp safely

## Operation Instructions

The system operates with the following logic:
- **Normal Operation**: Maintains temperature between 36.5°C and 37.5°C
- **Low Temperature**: Activates heating lamp and fan for circulation
- **High Temperature**: Turns off lamp and activates fan for cooling
- **Heart Rate Display**: Shows current BPM with smoothing algorithm
- **Alerts**: Buzzer sounds when temperature falls below 33°C or exceeds 37°C

## Customization

You can modify these parameters in the code:
- `HR_LOW` and `HR_HIGH`: Heart rate threshold values (currently 50 and 120 BPM)
- Temperature thresholds for control system (currently 36.5°C and 37.5°C)
- Temperature alarm thresholds (currently <33°C or >37°C)
- `THRESHOLD`: Pulse sensor detection threshold (currently 550)

## Safety Considerations

- This system is designed for educational and demonstration purposes only
- Not intended for actual medical use without proper certification
- Ensure all electrical components are properly isolated from the infant
- Implement additional safety mechanisms before any real-world application

## Future Improvements

- Add SpO2 (oxygen saturation) monitoring
- Implement data logging capabilities
- Add Wi-Fi/Bluetooth connectivity for remote monitoring
- Create mobile app interface
- Add backup power system

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by principles of infant incubators used in NICUs
- Created for educational and demonstration purposes
