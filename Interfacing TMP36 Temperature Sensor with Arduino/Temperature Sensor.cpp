const int tempPin = A0;  // TMP36 connected to A0
float tempCelsius, tempFahrenheit;
void setup() {
  Serial.begin(9600);} // Start serial communication
void loop() {
    int analogReadings = analogRead(A0); // Read analog data
    float voltage = analogReadings * 5.0 / 1024.0; // Convert to voltage
    tempCelsius = (voltage - 0.5) * 100.0; // Convert voltage to Celsius
    tempFahrenheit = (tempCelsius * 9.0 / 5.0) + 32.0; // Convert Celsius to Fahrenheit
    Serial.print("Temperature: ");
    Serial.print(tempCelsius);
    Serial.print(" °C | ");
    Serial.print(tempFahrenheit);
    Serial.println(" °F");

  delay(3000); }// Update every 3 seconds
