/*
 * This program uses a button to turn a LED on and off. 
 * Author: Maliha Tarafdar
 */

const int ledPin = 13;
const int buttonPin = 2;
boolean lastButtonState = LOW;
boolean ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, OUTPUT);
}

/*
 * This method returns the current state of the button after it has stabilized.
 * Parameter lastButtonState: The state of the button before a state change
 */
boolean debounce(boolean lastButtonState) {
  boolean currentButtonState = digitalRead(buttonPin);
  if (currentButtonState != lastButtonState) {
    delay(5);
    currentButtonState = digitalRead(buttonPin);
  }
  return currentButtonState;
}

void loop() {
  boolean currentButtonState = debounce(lastButtonState);
  if (currentButtonState && !lastButtonState) {
    ledState = !ledState;
  }
  lastButtonState = currentButtonState;
  digitalWrite(ledPin, ledState);
}
