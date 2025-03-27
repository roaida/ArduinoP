#include <LiquidCrystal.h>

// Define LCD pins connected to Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define resistor values for voltage divider
#define R1 90900  // 90.9kΩ resistor
#define R2 10000  // 10kΩ resistor

int analogPin = A0;  // Pin where voltage is measured
float analogValue = 0;
float voltage = 0;

void setup() {
    Serial.begin(9600);   // Start Serial Monitor with baud rate 9600
    lcd.begin(16, 2);     // Initialize the LCD with 16 columns and 2 rows
    lcd.setCursor(0, 0);
    lcd.print("Digital Voltmeter");
    delay(2000);
    lcd.clear();
}

void loop() {
    analogValue = analogRead(analogPin);  // Read the analog pin value
    float temp = (analogValue * 5.0) / 1023.0;  // Convert ADC value to voltage
    voltage = temp * ((R1 + R2) / R2);  // Apply voltage divider formula

    // Display voltage on LCD
    lcd.setCursor(0, 0);
    lcd.print("Voltage: ");
    lcd.setCursor(0, 1);
    lcd.print(voltage);
    lcd.print(" V");

    // Print voltage to Serial Monitor
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(300);  // Refresh display every 300ms
}

