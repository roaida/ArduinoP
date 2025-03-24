#include <IRremote.h>  // Include the IRremote library (v2.6.0)

#define IR_RECEIVE_PIN 12  // Define the IR receiver pin

// Define LED pins
#define BLUE_LED 2
#define ORANGE_LED 3
#define GREEN_LED 4

IRrecv irrecv(IR_RECEIVE_PIN);  // Create an IR receiver object
decode_results results;  // Variable to store received IR data

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // Start the IR receiver

    // Set LED pins as OUTPUT
    pinMode(BLUE_LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
}

void loop() {
    if (irrecv.decode(&results)) {  // Check if an IR signal is received
        Serial.println(results.value, HEX);  // Print received value in HEX

        switch (results.value) {
            case 0xFFA25D:  // Button 1
                digitalWrite(BLUE_LED, HIGH);
                break;
            case 0xFF629D:  // Button 2
                digitalWrite(BLUE_LED, LOW);
                break;
            case 0xFFE21D:  // Button 3
                digitalWrite(ORANGE_LED, HIGH);
                break;
            case 0xFF22DD:  // Button 4
                digitalWrite(ORANGE_LED, LOW);
                break;
            case 0xFF02FD:  // Button 5
                digitalWrite(GREEN_LED, HIGH);
                break;
            case 0xFFC23D:  // Button 6
                digitalWrite(GREEN_LED, LOW);
                break;
        }

        irrecv.resume();  // Continue receiving the next IR signal
    }
}
