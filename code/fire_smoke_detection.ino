/*
  Fire and Smoke Detection System
  ICT Workshop Project

  Components Used:
  - MQ2 Smoke Sensor
  - LM35 Temperature Sensor
  - Buzzer
  - LED Indicator
  - Arduino Uno
*/

const int smokeSensorPin = A0;
const int tempSensorPin = A1;

const int buzzerPin = 8;
const int ledPin = 7;

int smokeThreshold = 300;     // Adjust after calibration
float tempThreshold = 50.0;   // Temperature threshold in °C

void setup() {

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  Serial.println("Fire and Smoke Detection System Started...");
}

void loop() {

  int smokeValue = analogRead(smokeSensorPin);
  int tempValue = analogRead(tempSensorPin);

  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = voltage * 100;   // LM35 conversion

  Serial.print("Smoke Level: ");
  Serial.print(smokeValue);
  Serial.print(" | Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (smokeValue > smokeThreshold || temperature > tempThreshold) {

    Serial.println("WARNING: Fire or Smoke Detected!");

    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);

  } 
  else {

    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);

  }

  delay(1000);
}
