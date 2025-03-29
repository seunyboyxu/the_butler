#include <SoftwareSerial.h>

// Bluetooth Module Pins (SoftwareSerial)
#define BT_RX 2  // Arduino pin 2 → HC-05 TX
#define BT_TX 3  // Arduino pin 3 → HC-05 RX (with voltage divider if needed)
SoftwareSerial bluetooth(BT_RX, BT_TX);

// Motor Pins (L298N or similar)
#define IN1 13  // Left motor forward
#define IN2 12  // Left motor backward
#define IN3 11  // Right motor forward
#define IN4 10  // Right motor backward
#define ENA 5   // PWM for left motor speed (optional)
#define ENB 6   // PWM for right motor speed (optional)

// Function prototypes
void setupPins();
void forward(int duration);
void backward(int duration);
void stopMotors();

void setup() {
  Serial.begin(9600);    // Debugging (optional)
  bluetooth.begin(9600); // HC-05 default baud rate
  setupPins();
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    Serial.print("Received: ");  // Debug output
    Serial.println(command);
    
    switch (command) {
      case 'F': forward(1000); break;  // Move forward (1 sec)
      case 'B': backward(1000); break; // Move backward (1 sec)
      case 'S': stopMotors(); break;   // Stop
      case 'X': forward(2000); break;  // Custom distance X (2 sec)
      case 'Y': forward(500); break;   // Custom distance Y (0.5 sec)
    }
  }
}

// Initialize motor pins
void setupPins() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stopMotors(); // Ensure motors are off initially
}

// Move forward
void forward(int duration) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200); // Left motor speed (0-255)
  analogWrite(ENB, 200); // Right motor speed
  delay(duration);
  stopMotors();
}

// Move backward
void backward(int duration) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  delay(duration);
  stopMotors();
}

// Stop all motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}