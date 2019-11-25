int motorPin1 = 9;
int motorPin2 = 10;
int motorPin3 = 11;
int xPin = A0;
int yPin = A1;
int xPos = 0;
int yPos = 0;
void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  xPos = analogRead(xPin);
  Serial.println(xPos);
  yPos = analogRead(yPin);
  //Serial.println(yPos);
  yPos = constrain(yPos, 0, 504);
  int motorSpeed1 = map(yPos, 0, 504, 0, 255);
  int motorSpeed2 = map(xPos, 0, 1024, 0, 255);
  //Serial.println(motorSpeed1);
  analogWrite(motorPin1, motorSpeed1);
  if (xPos < 1022) {
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 0);
  } else {
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 255);
  }
  if (motorSpeed1 < 255) {
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
  }
  //analogWrite(motorPin3, 255);
  //delay(500);
}                               
