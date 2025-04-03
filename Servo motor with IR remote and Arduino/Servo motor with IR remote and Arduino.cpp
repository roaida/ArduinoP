#include <Servo.h>
#include <IRremote.h>

#define IR_RECEIVE_PIN 3
#define SERVO_PIN 9

Servo myServo;
IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    myServo.attach(SERVO_PIN);
    irrecv.enableIRIn();  // Start the IR receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);  // Print received IR code

        // Example: Change servo angle based on IR remote button
        if (results.value == 0xFFA25D) {  // Button 1
            myServo.write(0);  // Move to 0 degrees
        }
        else if (results.value == 0xFF629D) {  // Button 2
            myServo.write(90);  // Move to 90 degrees
        }
        else if (results.value == 0xFFE21D) {  // Button 3
            myServo.write(180);  // Move to 180 degrees
        }

        irrecv.resume();  // Receive next value
    }
}

