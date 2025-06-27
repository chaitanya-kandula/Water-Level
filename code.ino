// Pin Definitions
#define SIGNAL_PIN 9  // SIG pin of ultrasonic sensor
#define BUZZER 8
#define RED_LED 6
#define YELLOW_LED 5
#define GREEN_LED 4

void setup() {
  pinMode(SIGNAL_PIN, OUTPUT);  // Will be used for TRIG
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);  // For debugging distance
}

void loop() {
  long duration;
  int distance;

  // Trigger the ultrasonic pulse
  pinMode(SIGNAL_PIN, OUTPUT);
  digitalWrite(SIGNAL_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SIGNAL_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SIGNAL_PIN, LOW);

  // Switch to input mode to read echo
  pinMode(SIGNAL_PIN, INPUT);
  duration = pulseIn(SIGNAL_PIN, HIGH);

  // Calculate distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control LEDs and buzzer based on distance
  if (distance > 25) {
    // Tank is nearly empty
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  else if (distance > 10 && distance <= 25) {
    // Tank is half-full
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  else {
    // Tank is full
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  delay(1000);  // Wait 1 second before next reading
}
