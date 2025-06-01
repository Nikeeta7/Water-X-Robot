#include <Servo.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Pin Definitions
#define ESC_PIN 9
#define MOTOR_PIN 3
#define SERVO_PIN 10
#define TRIG_PIN 2
#define ECHO_PIN 4
#define CAMERA_PIN 7
#define STRAINER_PIN 8

// GPS Pins
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// Servo objects
Servo esc;
Servo myServo;
Servo strainerServo;

// GPS objects
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);
  Serial.println(F("NEO-6M GPS Module Test"));

  esc.attach(ESC_PIN);
  myServo.attach(SERVO_PIN);
  strainerServo.attach(STRAINER_PIN);

  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(CAMERA_PIN, OUTPUT);

  analogWrite(MOTOR_PIN, 0);
  delay(2000); // ESC initialization
}

void loop() {
  controlMotorESC();
  long distance = measureDistance();
  controlPWMByDistance(distance);
  sweepServo();
  controlStrainer(distance);
  controlCamera();
  readGPSData();

  delay(1000);
}

// Control Brushless ESC motor
void controlMotorESC() {
  esc.write(90); delay(2000);
  esc.write(0); delay(2000);
  esc.write(180); delay(2000);
}

// Ultrasonic distance measurement
long measureDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration / 2) / 29.1;
  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");
  return distance;
}

// PWM speed control based on distance
void controlPWMByDistance(long distance) {
  if (distance < 20) {
    analogWrite(MOTOR_PIN, 255);
  } else {
    analogWrite(MOTOR_PIN, 0);
  }
}

// Servo sweep 0–180° and back
void sweepServo() {
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}

// Strainer servo logic
void controlStrainer(long distance) {
  if (distance < 10) {
    strainerServo.write(0);
  } else if (distance < 20) {
    strainerServo.write(90);
  } else {
    strainerServo.write(180);
  }
}

// Simulated camera trigger
void controlCamera() {
  digitalWrite(CAMERA_PIN, HIGH);
  delay(1000);
  digitalWrite(CAMERA_PIN, LOW);
}

// Read and print GPS data
void readGPSData() {
  while (ss.available() > 0) {
    char c = ss.read();
    Serial.print(c);
    if (gps.encode(c) && gps.location.isUpdated()) {
      Serial.println(F("\n--- GPS Data ---"));
      Serial.print(F("Latitude: ")); Serial.println(gps.location.lat(), 6);
      Serial.print(F("Longitude: ")); Serial.println(gps.location.lng(), 6);
      Serial.print(F("Satellites: ")); Serial.println(gps.satellites.value());
      Serial.print(F("HDOP: ")); Serial.println(gps.hdop.value());
    }
  }
}
