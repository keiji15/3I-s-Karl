
#include <Servo.h>

Servo armServo;

const int SERVO_PIN = 9;

int currentAngle = 60;
int targetAngle = 60;

// Safe initial limits
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

unsigned long lastStep = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);

  armServo.write(currentAngle);
  armServo.attach(SERVO_PIN);

  Serial.println("MG996R CALIBRATION");
  Serial.println("Start with rods disconnected.");
  Serial.println("Type angle: 80 to 100");
  Serial.println("Type 90 for center.");
}

void loop() {

  // Receive angle command
  if (Serial.available()) {

    int requested = Serial.parseInt();

    while (Serial.available()) {
      Serial.read();
    }

    if (requested >= MIN_ANGLE &&
        requested <= MAX_ANGLE) {

      targetAngle = requested;

      Serial.print("Target angle: ");
      Serial.println(targetAngle);
    }
    else {
      Serial.println("Angle outside limits.");
    }
  }

  // Move gradually
  if (millis() - lastStep >= 30) {

    lastStep = millis();

    if (currentAngle < targetAngle) {
      currentAngle++;
    }
    else if (currentAngle > targetAngle) {
      currentAngle--;
    }

    armServo.write(currentAngle);
  }
}
