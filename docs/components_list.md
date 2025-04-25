# Infant Incubator Monitoring System: Components List

This document provides detailed specifications for all components required to build the infant incubator monitoring system.

## Microcontroller

**Arduino Uno R3** (Recommended)
- Operating Voltage: 5V
- Digital I/O Pins: 14 (of which 6 provide PWM output)
- Analog Input Pins: 6
- DC Current per I/O Pin: 20 mA
- Flash Memory: 32 KB

**Alternatives:**
- Arduino Nano (smaller footprint)
- Arduino Mega (more I/O pins if expanding the project)

## Sensors

### Pulse Sensor
**Pulse Sensor Amped**
- Operating Voltage: 3.3V-5V
- Analog output
- Integrated amplification and noise cancellation
- LED and photodiode-based optical heart rate sensor

**Alternatives:**
- MAX30102 Pulse Oximeter and Heart Rate Sensor Module (more accurate but more complex)

### Temperature and Humidity Sensor
**DHT11 Digital Temperature & Humidity Sensor**
- Temperature Range: 0-50°C (±2°C accuracy)
- Humidity Range: 20-80% RH (±5% RH accuracy)
- Operating Voltage: 3.3V-5V
- One-wire digital interface
- Sampling rate: 1Hz (one reading every second)

**Alternatives:**
- DHT22 (better accuracy and range, slightly more expensive)
- SHT21/SHT31 (higher precision, I2C interface)

## Display

**SSD1306 OLED Display**
- Display Size: 0.96 inch
- Resolution: 128×64 pixels
- Interface: I2C
- Operating Voltage: 3.3-5V
- Color: Blue/White/Yellow+Blue
- I2C Address: 0x3C (or 0x3D)

**Alternatives:**
- Larger 1.3" SSD1306 OLED
- LCD 16x2 with I2C adapter (less graphical capability but simpler to use)

## Control Components

### Relay Module
**5V Single Channel Relay Module**
- Operating Voltage: 5V DC
- Trigger Current: 15-20mA
- Maximum Load: AC 250V/10A, DC 30V/10A
- With optocoupler isolation

**Alternatives:**
- Solid State Relay (silent operation, no moving parts)

### Fan Control
**L9110S H-Bridge Motor Driver Module**
- Operating Voltage: 2.5V-12V
- Maximum Continuous Current: 800mA
- For controlling DC motor fan speed with PWM

**Alternatives:**
- Transistor-based control circuit (simpler but less flexible)
- L298N Motor Driver (overkill but useful if higher current needed)

### DC Fan
**5V DC Cooling Fan**
- Operating Voltage: 5V
- Current: ~100-200mA
- Size: 40mm x 40mm x 10mm
- Airflow: ~4-5 CFM

**Alternatives:**
- 12V Fan with voltage regulator (more powerful)
- Computer case fan (larger, more airflow)

### Heating Element
**Ceramic Infrared Heat Lamp**
- Low wattage (20-40W)
- 110V/220V AC operation
- Connect via relay control

**Alternatives:**
- Nichrome wire heating element
- PTC heating element (self-regulating)

## Alert System

**Active Buzzer Module**
- Operating Voltage: 5V
- High sound output
- TTL level control

**Alternatives:**
- Piezo speaker
- LED indicators (for visual alerts)

## Miscellaneous

### Power Supply
- 5V 2A DC Adapter for Arduino and sensors
- Separate power source for heating element

### Connection Materials
- Breadboard (for prototyping)
- Jumper Wires (male-to-male, male-to-female, female-to-female)
- Project enclosure box
- Heat-resistant materials for incubator housing

### Optional Components for Expansion
- ESP8266/ESP32 WiFi module (for remote monitoring)
- SD card module (for data logging)
- RTC module (DS3231) for time tracking
- Backup battery power system

## Estimated Budget

| Component | Quantity | Est. Price (USD) |
|-----------|----------|------------------|
| Arduino Uno | 1 | $20-25 |
| Pulse Sensor | 1 | $15-25 |
| DHT11 Sensor | 1 | $3-5 |
| SSD1306 OLED | 1 | $5-8 |
| Relay Module | 1 | $3-5 |
| Motor Driver | 1 | $2-4 |
| DC Fan | 1 | $3-8 |
| Heat Lamp | 1 | $10-20 |
| Buzzer | 1 | $1-2 |
| Power Supplies | 2 | $10-15 |
| Breadboard & Wires | - | $10-15 |
| Project Box | 1 | $5-10 |
| **TOTAL** | | **$87-142** |

## Purchasing Resources

These components can be found at:
- Online: Amazon, eBay, AliExpress, Adafruit, SparkFun
- Local: Electronics stores, hardware stores, hobby shops

## Notes on Component Selection

1. **Sensor Quality**: For more accurate monitoring, consider investing in higher-quality sensors than the basic DHT11. The DHT22 offers better precision, or professional-grade sensors if budget allows.

2. **Safety First**: All heating elements should have multiple safety mechanisms, including thermal fuses and secondary temperature monitoring.

3. **Power Considerations**: Ensure adequate power supply for all components, especially the heating element. Consider separating digital/analog circuits from high-current components.

4. **Enclosure Design**: The enclosure should provide good ventilation while maintaining stable internal temperature. Consider transparent materials for visibility.

5. **Medical Considerations**: This project is for educational purposes only. Any medical application would require FDA-approved components and extensive safety testing.
