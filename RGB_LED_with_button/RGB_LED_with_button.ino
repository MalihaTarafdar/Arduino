const int RED_PIN = 3;
const int GREEN_PIN = 5;
const int BLUE_PIN = 6;
const int BUTTON_PIN = 8;

int red = 255;
int green = 0;
int blue = 0;
int stage = 1;
const int BRIGHTNESS = 255;

boolean lastButtonState = LOW;
boolean ledOn = LOW;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

boolean debounce(boolean lastState, int pin) {
  boolean currentState = digitalRead(pin);
  if (lastState != currentState) {
    delay(5);
    currentState = digitalRead(pin);
  }
  return currentState;
}

int changeValue(int value, boolean increment) {
  value = constrain((increment) ? value + 1 : value - 1, 0, BRIGHTNESS);
  return value;
}

void setLEDColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void changeColors() {
  switch (stage) {
    case 1:
      green = changeValue(green, true);
      if (green == BRIGHTNESS) {
        stage++;
      }
      break;
    case 2:
      red = changeValue(red, false);
      if (red == 0) {
        stage++;
      }
      break;
    case 3:
      blue = changeValue(blue, true);
      if (blue == BRIGHTNESS) {
        stage++;
      }
      break;
    case 4:
      green = changeValue(green, false);
      if (green == 0) {
        stage++;
      }
      break;
    case 5:
      red = changeValue(red, true);
      if (red == BRIGHTNESS) {
        stage++;
      }
      break;
    case 6:
      blue = changeValue(blue, false);
      if (blue == 0) {
        stage = 1;
      }
      break;
  }
}

void loop() {
  boolean currentButtonState = debounce(lastButtonState, BUTTON_PIN);
  if (currentButtonState && !lastButtonState) {
    ledOn = !ledOn;
  }
  lastButtonState = currentButtonState;
  
  if (ledOn) {
    setLEDColor(red, green, blue);
    changeColors();
  } else {
    setLEDColor(0, 0, 0);
  }
  delay(5);
}
