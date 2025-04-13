// Define LED pins
int ledPins[] = {2, 3, 4, 5, 6,7};
int numLeds = 6;
// Optional: Potentiometer for speed control
int potPin = A5;
void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);}}
void loop() {
  int delayTime = analogRead(potPin) / 4; // Converts 0–1023 to 0–255 ms
  // Pattern: Left to Right
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);  }
  // Pattern: Right to Left
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);}}
