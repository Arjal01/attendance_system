const int buttonPin = 2;
const int greenLedPin = 13;
const int redLedPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  while (!Serial) { ; }
  Serial.println("Arduino Mega ready");
}

void loop() {
  static int lastButtonState = HIGH;
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("CAPTURE");
    delay(200);
  }
  lastButtonState = buttonState;

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'S') {
      digitalWrite(greenLedPin, HIGH);
      digitalWrite(redLedPin, LOW);
      delay(1000);
      digitalWrite(greenLedPin, LOW);
    } else if (command == 'E') {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      delay(1000);
      digitalWrite(redLedPin, LOW);
    }
  }
}