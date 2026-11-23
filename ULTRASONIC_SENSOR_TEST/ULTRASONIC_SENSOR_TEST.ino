
#define TRIG_PIN 2
#define ECHO_PIN 3

const int detectionDistance = 50; // cm

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("HC-SR04 Sensor Test");
  Serial.println("System Ready!");
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Receive echo
  unsigned long duration =
    pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0) {
    Serial.println("No echo detected");
  }
  else {
    float distance = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Detection condition
    if (distance <= detectionDistance) {
      Serial.println("OBJECT DETECTED!");
      Serial.println("Scarecrow would activate.");
    }
    else {
      Serial.println("No object nearby.");
    }
  }

  Serial.println("----------------------");

  delay(500);
}
