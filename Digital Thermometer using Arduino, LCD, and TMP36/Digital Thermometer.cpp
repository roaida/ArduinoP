#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Initialize LCD
}

void loop() {
  int rawValue = analogRead(A0); // Read from TMP36
  float voltage = (rawValue / 1024.0) * 5.0; // Convert to voltage
  float tempC = (voltage - 0.5) * 100.0; // TMP36 formula
  float tempF = tempC * 9.0 / 5.0 + 32.0; // Convert to Fahrenheit

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.print((char)223);
  lcd.print("F");

  delay(1000);
}
