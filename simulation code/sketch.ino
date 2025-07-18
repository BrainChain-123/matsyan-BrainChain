#include <WiFi.h>
#include "ThingSpeak.h"
#include <Wire.h>

// Simulated QMC5883L (Metal Detection)
int simulateMagneticField() {
  return random(300, 800); // Random value between 300–800 for High/Medium/Low
}

// Simulated Vibration Sensor
int simulateVibration() {
  return random(1000, 3000); // Random value between 1000–3000
}

// WiFi & ThingSpeak
const char* ssid = "Wokwi-GUEST";
const char* password = "";
WiFiClient client;

unsigned long channelID = 3011293;
const char* writeAPIKey = "97XO1HLU4U0BODHN";

// Sensor Pins
const int tdsPin = 34;
const int phPin = 35;
const int turbidityPin = 32;

// Simulated Vibration Pin (not needed but declared)
const int vibrationPin = 26;

// LEDs
const int yellowLED = 12; // Ghost net / metal
const int violetLED = 14; // Marine animal alert
const int blueLED = 27;   // Normal
const int redLED = 13;    // Pollution

// Buzzer
const int buzzer = 25;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\n✅ Connected to WiFi!");

  ThingSpeak.begin(client);

  // Sensor Pins
  pinMode(tdsPin, INPUT);
  pinMode(phPin, INPUT);
  pinMode(turbidityPin, INPUT);

  // Output Pins
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(violetLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int tdsValue = analogRead(tdsPin);
  int phValue = analogRead(phPin);
  int turbidityValue = analogRead(turbidityPin);
  int vibrationValue = simulateVibration(); // Random vibration
  int metalValue = simulateMagneticField(); // Random magnetic field

  // ALERT LOGIC
  bool waterPollution = (tdsValue > 700 || phValue < 4 || phValue > 10 || turbidityValue > 600);
  bool ghostNetDetected = (metalValue > 600);
  bool vibrationHigh = (vibrationValue > 2500);
  bool animalTrapped = (ghostNetDetected && vibrationHigh);


  // LED Indicator logic
  if (waterPollution) {
    digitalWrite(redLED, HIGH);      // Pollution Alert
    digitalWrite(blueLED, LOW);      // Normal off
    digitalWrite(yellowLED, LOW);    // Ghost net off
    digitalWrite(violetLED, LOW);    // Animal alert off
  } 
  else if (animalTrapped) {
    digitalWrite(violetLED, HIGH);   // Animal Trapped Alert
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  else if (ghostNetDetected) {
    digitalWrite(yellowLED, HIGH);   // Ghost net Alert
    digitalWrite(redLED, LOW);
    digitalWrite(violetLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  else {
    digitalWrite(blueLED, HIGH);     // Normal condition
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(violetLED, LOW);
  }
  
  // Buzzer
  if (waterPollution || ghostNetDetected || animalTrapped) {
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);
  }

  // Print Levels
  String vibrationLevel = (vibrationValue > 2500) ? "High" : (vibrationValue > 1500) ? "Medium" : "Low";
  String metalLevel = (metalValue > 600) ? "High" : (metalValue > 400) ? "Medium" : "Low";

  Serial.println("===== Sensor Readings =====");
  Serial.println("TDS (ppm): " + String(tdsValue));
  Serial.println("pH Value: " + String(phValue));
  Serial.println("Turbidity: " + String(turbidityValue));
  Serial.println("Vibration: " + String(vibrationValue) + " (" + vibrationLevel + ")");
  Serial.println("Magnetic Field: " + String(metalValue) + " (" + metalLevel + ")");
  if (waterPollution) Serial.println("⚠️ Water Pollution Detected!");
  if (ghostNetDetected) Serial.println("📢 Ghost Net / Metal Detected!");
  if (animalTrapped) Serial.println("⛑️Marine Animal Might Be Trapped!");
  if (!waterPollution && !ghostNetDetected && !animalTrapped) Serial.println("⛱️ All Looking Good!");
  Serial.println("===========================\n");

  // Upload to ThingSpeak
  ThingSpeak.setField(1, tdsValue);
  ThingSpeak.setField(2, phValue);
  ThingSpeak.setField(3, turbidityValue);
  ThingSpeak.setField(4, vibrationValue);
  ThingSpeak.setField(5, waterPollution ? 1 : 0);
  ThingSpeak.setField(6, ghostNetDetected ? 1 : 0);
  ThingSpeak.setField(7, animalTrapped ? 1 : 0);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (status == 200) {
    Serial.println("✅ Data sent to ThingSpeak");
  } else {
    Serial.println("❌ Error sending to ThingSpeak. Code: " + String(status));
  }

  delay(17000); // 15s minimum for ThingSpeak
}
