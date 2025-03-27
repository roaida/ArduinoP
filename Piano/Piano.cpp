const int buzzer = 13;  // Buzzer connected to pin 8
const int buttonPins[] = {2, 3, 4, 5, 6, 7,8,9}; // Push button pins
const int notes[] = {262, 294, 330, 349, 392, 440, 500,550}; // Frequencies (C, D, E, F, G, A)

void setup() {
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Use internal pull-up resistors
  }
}

void loop() {
  for (int i = 0; i < 9; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Button pressed (LOW due to pull-up)
      tone(buzzer, notes[i]);  // Play corresponding note
      delay(200);  // Hold the note for a short duration
      noTone(buzzer); // Stop sound
    }
  }
}

