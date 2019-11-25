int speakerPin = 13;
int redLedPin = 9;
int yellowLedPin = 10;
int greenLedPin = 12;

int wirePin = 6;
//int proximityInput = 7;
//int proximityOutput = 8;
int touchPin1 = 4;
int touchPin2 = 8;
int motionPin = 2;
int masterSwitch = 5;

boolean currentButton = LOW;
boolean lastButton = LOW;
boolean motionState = LOW;
boolean armed = true;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(wirePin, INPUT);
  //pinMode(proximityInput, INPUT); //echo
  //pinMode(proximityOutput, OUTPUT); //trig
  pinMode(touchPin1, INPUT);
  pinMode(touchPin2, INPUT);
  pinMode(motionPin, INPUT);
  pinMode(masterSwitch, INPUT);
  Serial.begin(9600);
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if (last != current) {
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}

void alarm() {
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  analogWrite(speakerPin, 150);
  delay(50);
  digitalWrite(redLedPin, LOW);
  analogWrite(speakerPin, 0);
  delay(50);
}

/*boolean proximitySensor() {
  digitalWrite(proximityOutput, LOW);
  delayMicroseconds(2);
  digitalWrite(proximityOutput, HIGH);
  delayMicroseconds(10);
  digitalWrite(proximityInput, LOW);

  float duration = pulseIn(proximityInput, HIGH);
  float distance = duration * 0.034 / 2;
  constrain(distance, 0, 30);
  delay(50);
  if (distance < 5) {
    return true;
  }
  return false;
}*/

boolean motionSensor() {
  int motionVal = digitalRead(motionPin);
  if (motionVal == HIGH) {
    if (motionState == LOW) {
      motionState = HIGH;
      return true;
    }
  } else {
    if (motionState == HIGH) {
      motionState = LOW;
      return false;
    }
  }
}

boolean wireLoop() {
  if (digitalRead(wirePin) == HIGH) {
    return true;
  }
  return false;
}

boolean touchSensor(int touchPin) {
  if (digitalRead(touchPin) == HIGH) {
    return true;
  }
  return false;
}

boolean armSystem() {
  currentButton = debounce(lastButton, masterSwitch);
  if (lastButton != currentButton) {
    return true;
  }
  lastButton = currentButton;
  return false;
}

void loop() {
  while (!armed) {
    alarm();
    armed = armSystem();
  }
  while (armed) {
    digitalWrite(yellowLedPin, !digitalRead(masterSwitch));
    digitalWrite(redLedPin, LOW);
    digitalWrite(speakerPin, LOW);
    if (touchSensor(touchPin2) || motionSensor() || wireLoop() || touchSensor(touchPin1)) {
      armed = false;
    }
  }
}

