int pirPin = 7;
int buzzer = 8;
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int relayPin = 6;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  if (motionDetected == HIGH) {
    // Alert Mode
    digitalWrite(buzzer, HIGH);
    digitalWrite(relayPin, HIGH);
    setColor(255, 0, 0); // Red - Alert
    Serial.println("Motion Detected!");
    delay(5000); // Alarm duration
  } else {
    // Safe Mode
    digitalWrite(buzzer, LOW);
    digitalWrite(relayPin, LOW);
    setColor(0, 255, 0); // Green - Safe
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
