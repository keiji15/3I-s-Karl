#include <WTV020SD16P.h>

// WTV020 connections
const int resetPin = 4;
const int clockPin = 5;
const int dataPin  = 6;
const int busyPin  = 7;

// Initialize module
WTV020SD16P soundModule(
  resetPin,
  clockPin,
  dataPin,
  busyPin
);

void setup() {

  Serial.begin(9600);

  Serial.println("WTV020 SOUND TEST");
  Serial.println("Initializing module...");

  // Reset the sound module
  soundModule.reset();

  delay(1000);

  Serial.println("System Ready!");
  Serial.println("Enter 1 to play sound.");
  Serial.println("Enter 0 to stop sound.");
}

void loop() {

  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command == '1') {

      Serial.println("Playing 0000.ad4");

      soundModule.asyncPlayVoice(0);
    }

    else if (command == '0') {

      Serial.println("Stopping sound");

      soundModule.stopVoice();
    }
  }
}
