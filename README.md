# 🚰 Arduino Water Level Indicator using Ultrasonic Sensor (ThinkerCAD Project)

This project simulates a smart water level monitoring system using an ultrasonic sensor in ThinkerCAD. Based on the water level (measured by distance), it activates LEDs and a buzzer to show whether the tank is full, half-full, or empty.

---

## 📌 Features

- 🟥 **RED LED** – Water level is **low** (distance > 25 cm)
- 🟨 **YELLOW LED** – Water level is **medium** (10 cm < distance ≤ 25 cm)
- 🟩 **GREEN LED + Buzzer** – Water level is **high/full** (distance ≤ 10 cm)
- 📟 Real-time serial output for debugging

---

## 🧰 Components Used

- Arduino UNO
- Ultrasonic Sensor (HC-SR04 or single-wire in ThinkerCAD)
- 3 LEDs (Red, Yellow, Green)
- 1 Buzzer
- Resistors
- Jumper Wires
- Breadboard (optional)
- ThinkerCAD simulator

---

## 🧾 Code

```cpp
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
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
  } else if (distance > 10 && distance <= 25) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }

  delay(1000);  // Wait 1 second before next reading
}


📂 Project Structure
Water-Level/
├── code.ino               # Arduino code
├── screenshot.png         # Screenshot of the ThinkerCAD circuit
└── README.md              # Project overview and documentation

## 👨‍💻 Author

**Chaitanya Kandula**  
🔗 [GitHub](https://github.com/chaitanya-kandula)  
📧 chaitanyakandula2005@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/chaitanya-kandula1201)

🧠 Built With
ThinkerCAD
Arduino IDE
GitHub


---

### ✅ To Use:
1. Save this content as `README.md` inside your project folder.
2. Push it to your GitHub repo.
3. Your links and layout will be perfectly clickable and formatted on GitHub.

Let me know if you want this saved as a `.md` file or directly added to your repo!

