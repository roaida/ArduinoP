// Pin Definitions
#define TEMP_SENSOR A0 // Temperature Sensor connected to A1
#define GAS_SENSOR A1 // Gas Sensor connected to A0
#define LED_PIN 13 // LED connected to digital pin 13
#define PIEZO_PIN 7 // Piezo Buzzer connected to digital pin 7
// Threshold Values
#define TEMP_THRESHOLD 80 // Temperature threshold (°C)
#define GAS_THRESHOLD 100 // Gas concentration threshold
void setup() {
pinMode(A0, INPUT); // Temperature sensor as input
pinMode(A1, INPUT); // Gas sensor as input
pinMode(13, OUTPUT); // LED as output
pinMode(7, OUTPUT); // Piezo buzzer as output
Serial.begin(9600); // Start serial communication
}
void loop() {
// Read Temperature Sensor Value
int tempValue = analogRead(A0);
float voltage = (tempValue / 1023.0) * 5.0; // Convert to voltage
float temperature = voltage * 100; // Convert voltage to temperature
// Read Gas Sensor Value
int gasValue = analogRead(A1);
// Temperature Alert Condition
if (temperature >= 80) {
digitalWrite(13, HIGH); // Turn LED ON
} else {
digitalWrite(13, LOW); // Turn LED OFF }
// Gas Alert Condition
if (gasValue >= 100) {
digitalWrite(7, HIGH); // Turn Piezo ON
} else {
digitalWrite(7, LOW); // Turn Piezo OFF }
// Display values on Serial Monitor
Serial.print("Temperature (°C): ");
Serial.print(temperature);
Serial.print("\t Gas Sensor Value: ");
Serial.println(gasValue);
delay(1000); // Wait for 1 second before next reading}
