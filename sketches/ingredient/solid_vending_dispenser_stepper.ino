// Pin definitions
#define DIR_PIN 3
#define STEP_PIN 4
#define EN_PIN 5

// Motor parameters
const int stepsPerRevolution = 200; // Adjust for your motor (e.g., 200 for 1.8°/step)
const int stepDelay = 800;          // Microseconds between steps (controls speed)

void setup() {
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

  // Enable the driver (active LOW)
  digitalWrite(EN_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Stepper motor control started!");
}

void loop() {
  // Rotate clockwise
  digitalWrite(DIR_PIN, HIGH);
  Serial.println("Rotating clockwise...");
  stepMotor(stepsPerRevolution);
  delay(1000);

  // Rotate counterclockwise
  digitalWrite(DIR_PIN, LOW);
  Serial.println("Rotating counterclockwise...");
  stepMotor(stepsPerRevolution);
  delay(1000);
}

// Function to perform a given number of steps
void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(stepDelay);
  }
}
