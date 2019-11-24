/*
 * This program programs an RGB LED to change colors gradually and only turn on in darkness.
 * Author: Maliha Tarafdar
 */
const int RED_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_PIN = 6;
const int PHOTORESISTOR_PIN = A0;

int red = 255;
int green = 0;
int blue = 0;
const int BRIGHTNESS = 255;
int stage = 0;

boolean ledOn = LOW;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  Serial.begin(9600);
}

/*
 * This function increments or decrement a value that is constrained to 0-BRIGHTNESS
 * Parameter value: the value to change
 * Parameter increment: increment (true) or decrement (false)
 */
int changeValue(int value, boolean increment) {
  return constrain((increment) ? value + 1 : value - 1, 0, BRIGHTNESS);;
}

/*
 * This function sets the red, green, and blue pins on an RGB LED to the desired amounts
 */
void setLEDColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

/*
 * This function appropriately changes the red, green, and blue amounts to create a color gradient
 */
void changeColors() {
  switch (stage % 3) {
    case 0:
      green = (stage < 3) ? changeValue(green, true) : changeValue(green, false);
      if (green == 0 || green == BRIGHTNESS) stage++;
      break;
    case 1:
      red = (stage >= 3) ? changeValue(red, true) : changeValue(red, false);
      if (red == 0 || red == BRIGHTNESS) stage++;
      break;
    case 2:
      blue = (stage < 3) ? changeValue(blue, true) : changeValue(blue, false);
      if (blue == 0 || blue == BRIGHTNESS) stage++;
      break;
  }
  if (stage > 5) stage = 0;
}

void loop() {
  ledOn = analogRead(PHOTORESISTOR_PIN) < 300; //from 0 to 1023
  
  if (ledOn) {
    setLEDColor(red, green, blue);
    changeColors();
  } else {
    setLEDColor(0, 0, 0);
  }
  delay(5);
}
