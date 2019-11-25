int ledPin = 13;
int ledLevel = 0;
int levelStep = 51;
int sensorPin = 0;
int sensorVal = analogRead(sensorPin);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorVal = constrain(sensorVal, 750, 900);
  ledLevel = map(sensorVal, 750, 900, 255, 0);
  analogWrite(ledPin, ledLevel);
  
  /*
  ledLevel += levelStep;
  if (ledLevel > 255) {
    ledLevel = 0;
  }
  analogWrite(ledPin, ledLevel);
  */
}
