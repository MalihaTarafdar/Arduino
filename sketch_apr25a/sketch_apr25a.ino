int motorPin = 9;
int xPin = A0;
int yPin = A1;
int xPos = 0;
int yPos = 0;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);
  //Serial.println(xPos);
  int motorSpeed = map(xPos, 0, 657, 0, 255);
  //Serial.println(motorSpeed);
  analogWrite(motorPin, 200);
}
