// Define pin connections
const int LDR_PIN = A0;    // LDR connected to Analog pin A0
const int LED_PIN = 9;     // LED connected to Digital pin 9
void setup() {
    pinMode(LDR_PIN, INPUT);  // LDR as input
    pinMode(LED_PIN, OUTPUT); // LED as output
    Serial.begin(9600);       // Initialize Serial Monitor}
void loop() {
    int sensorValue = analogRead(LDR_PIN); // Read LDR value
    Serial.print("LDR Sensor Value: ");
    Serial.println(sensorValue); // Print sensor value
    // Map the sensor value to LED brightness (0-255)
    int ledBrightness = map(sensorValue, 0, 1023, 0, 255);
    analogWrite(LED_PIN, ledBrightness); // Adjust LED brightness based on light intensity
    delay(100); // Delay for stability}

