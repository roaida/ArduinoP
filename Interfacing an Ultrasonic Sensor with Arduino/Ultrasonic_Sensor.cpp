#define trigPin 10 // Define Trigger pin
#define echoPin 9 // Define Echo pin
long duration;
float distance;
void setup() {
pinMode(10, OUTPUT); // Set Trig pin as output
pinMode(9, INPUT); // Set Echo pin as input
Serial.begin(9600); // Start serial communication}
void loop() {
digitalWrite(10, LOW); // Clear the Trig pin
delayMicroseconds(2);
digitalWrite(10, HIGH); // Send ultrasonic pulse
delayMicroseconds(10);
digitalWrite(10, LOW); // Stop pulse transmission
duration = pulseIn(9, HIGH); // Measure time of flight
distance = (duration * 0.034) / 2; // Calculate distance
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
delay(500); // Small delay before next measurement}
