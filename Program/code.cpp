char data;  // Stores incoming serial data
#define INT1 8
#define INT2 9
#define INT3 10
#define INT4 11

void setup() {
  Serial.begin(9600);          // Start serial communication at 9600 baud rate
  pinMode(INT1, OUTPUT);
  pinMode(INT2, OUTPUT);
  pinMode(INT3, OUTPUT);
  pinMode(INT4, OUTPUT);

  // Initial state: Stop the motors
  stopMotors();
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();   // Read the incoming command
    data = toupper(data);   // Convert to uppercase (makes it more responsive)

    switch (data) {
      case 'F': forward();  break;  // Move Forward
      case 'B': backward(); break;  // Move Backward
      case 'R': right();    break;  // Turn Right
      case 'L': left();     break;  // Turn Left
      case 'S': stopMotors(); break; // Stop
      default: stopMotors(); break;  // Safety (any invalid input stops robot)
    }
  }
}

// ===== Motor Control Functions =====
void forward() {
  digitalWrite(INT1, HIGH);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, HIGH);
  digitalWrite(INT4, LOW);
}

void backward() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, HIGH);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, HIGH);
}

void right() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, HIGH);
  digitalWrite(INT3, HIGH);
  digitalWrite(INT4, LOW);
}

void left() {
  digitalWrite(INT1, HIGH);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, HIGH);
}

void stopMotors() {
  digitalWrite(INT1, LOW);
  digitalWrite(INT2, LOW);
  digitalWrite(INT3, LOW);
  digitalWrite(INT4, LOW);
}
