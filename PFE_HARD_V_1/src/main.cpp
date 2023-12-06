#include <Arduino.h>

// put function declarations here:
String Receive_order();

void vent();
void blinkLED();
void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  String order = Receive_order();
  // Now 'order' contains the received string from Serial
  if (order == "0x00") {
    vent();
    blinkLED();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
String Receive_order() {
  // Wait for a string to be received on Serial
  while (!Serial.available()) {
    // Wait for data
  }

  // Read the received string until a newline character is encountered
  String receivedString = Serial.readStringUntil('\n');

  // Optional: Print the received string to Serial for verification
  Serial.print("Received Order: ");
  Serial.println(receivedString);

  // Return the received string
  return receivedString;
}

void vent(){
  digitalWrite(2, HIGH);
}
void blinkLED() {
  // Faire clignoter la LED
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}