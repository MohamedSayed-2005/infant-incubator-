#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pulse Sensor Configuration
const int PULSE_SENSOR_PIN = A0;  
const int THRESHOLD = 550;
PulseSensorPlayground pulseSensor;

// BPM Variables
int bpm = 0;  
int lastBPM = -1; 
float smoothBPM = 0;
unsigned long lastBeatTime = 0; // To track the last heartbeat time

// Heart Rate Thresholds
#define HR_LOW 50    // Low heart rate alert
#define HR_HIGH 120  // High heart rate alert

// DHT Configuration
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Incubator control pins
#define FAN_PIN 9      // Fan (Motor Driver)
#define RELAY_PIN 8    // Lamp (Relay)
#define BUZZER_PIN 7   // Buzzer

float temp = 0.0;
float humidity = 0.0;
bool fanDelayed = false;

void setup() {
    Serial.begin(115200); // Start serial communication for pulse sensor
    dht.begin();          // Initialize DHT sensor for temperature and humidity

    // Initialize Pulse Sensor
    pulseSensor.analogInput(PULSE_SENSOR_PIN);
    pulseSensor.setThreshold(THRESHOLD);

    // Initialize OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("⚠ OLED allocation failed!");
        while (true);  // Halt execution if OLED initialization fails
    }
    display.clearDisplay();

    // Initialize Incubator Control Pins
    pinMode(FAN_PIN, OUTPUT);
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
    unsigned long currentMillis = millis();

    // Read heart rate from Pulse Sensor
    int currentBPM = pulseSensor.getBeatsPerMinute();

    if (currentBPM > 40 && currentBPM < 180) {  
        if (lastBPM == -1) {  
            smoothBPM = currentBPM;  
        } else if (abs(currentBPM - lastBPM) < 10) {  
            smoothBPM = (0.7 * smoothBPM) + (0.3 * currentBPM); 
        } else {
            smoothBPM = currentBPM; 
        }

        lastBPM = smoothBPM; 
        bpm = int(smoothBPM);
        lastBeatTime = currentMillis;
    }

    // Reset BPM to 0 if no pulse detected for more than 5 seconds
    if (currentMillis - lastBeatTime > 2000) {
        bpm = 0;
    }

    // Read temperature and humidity from DHT sensor
    temp = dht.readTemperature();
    humidity = dht.readHumidity();

    if (isnan(temp) || isnan(humidity)) {
        display.print("Failed to read from DHT sensor!");
        return;
    }

    // Incubator control logic
    if (temp < 36.5) {
        digitalWrite(RELAY_PIN, LOW);  // Turn on lamp
        digitalWrite(FAN_PIN, HIGH);    // Turn on fan
        fanDelayed = true;
    } 
    else if (temp > 37.5 ) {
        digitalWrite(RELAY_PIN, HIGH);   // Turn off lamp
        digitalWrite(FAN_PIN, HIGH);    // Keep fan on for cooling
        fanDelayed = false;
    } 
    else {
        digitalWrite(RELAY_PIN, HIGH);   // Keep lamp off
        digitalWrite(FAN_PIN, LOW);     // Keep fan off
        fanDelayed = false;
    }

    // Buzzer activation if temperature drops below 28°C
    if (temp < 33 ||temp > 37) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(200); 
        digitalWrite(BUZZER_PIN, LOW);
        delay(200); 

    }

    // Display heart rate and incubator status on OLED
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    
    // Heart rate display
    display.setCursor(0, 0);
    display.print("BPM: ");
    display.print(bpm);
    
    // Temperature and humidity display
    display.setCursor(0, 20);
    display.print("Temp: "); display.print(temp); display.println(" C");
    display.print("Humidity: "); display.print(humidity); display.println(" %");

    display.display();
    delay(100);  // Small delay to update sensor readings
}
