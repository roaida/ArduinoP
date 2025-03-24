#include <Keypad.h>
const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};   // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};   // Connect to the column pinouts
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
const String password = "1234";  // Set your password
String inputPassword = "";       // Store user input
const int greenLED = 10;  // Access Granted LED
const int redLED = 11;    // Access Denied LED
const int buzzer = 12;    // Optional buzzer
void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);}
void loop() {
  char key = keypad.getKey();
  if (key) {  // If a key is pressed
    Serial.print(key);
    if (key == '#') {  // '#' is used to enter the password
      if (inputPassword == password) {
        Serial.println("\nAccess Granted!");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        tone(buzzer, 1000, 500);  // Beep for success
        delay(2000);
        digitalWrite(greenLED, LOW);
      }
else {
        Serial.println("\nAccess Denied!");
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        tone(buzzer, 500, 500);  // Beep for failure
        delay(2000);
        digitalWrite(redLED, LOW); }
      inputPassword = "";  // Reset input
    }
else if (key == '*') {  // '*' is used to clear input
      Serial.println("\nInput Cleared");
      inputPassword = "";
    }
 else {
      inputPassword += key;  // Append pressed key to input    }}}

