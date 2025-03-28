#include <Servo.h>

#define TRIG_PIN 7  // Trig pin of Ultrasonic Sensor
#define ECHO_PIN 6 // Echo pin of Ultrasonic Sensor
#define SERVO_PIN 5 // Servo motor pin

Servo myServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Initial position of the servo
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trigger the Ultrasonic Sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the Echo pin
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If a hand is detected within 10 cm
  if (distance > 0 && distance < 10) {
    myServo.write(90);  // Move servo to dispense sanitizer
    delay(1000);        // Wait for sanitizer to be dispensed
    myServo.write(0);   // Reset servo to initial position
    delay(2000);        // Delay before next detection
  }
}
