/*
 * This program uses a passive buzzer and 9 buttons to make a piano.
 * Notes are C, D, E, F, G, A, B, in that order. Octaves are 4-7. 
 * Octaves can be increased and decreased. 
 * Author: Maliha Tarafdar
 */

const int SPEAKER = 12;
const int BUTTONS[] = {10, 9, 8, 7, 6, 5, 4};
const int HIGHER_OCTAVE_BUTTON = 2;
const int LOWER_OCTAVE_BUTTON = 3;

//frequencies of notes in 4th octave (STARTING_OCTAVE)
//Note order: C, D, E, F, G, A, B
const double notes[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88};

int octave = 4; //current octave
const int STARTING_OCTAVE = 4;
const int OCTAVE_MIN = 3;
const int OCTAVE_MAX = 7;
boolean octaveIncreased = false;
boolean octaveDecreased = false;

void setup() {
  pinMode(SPEAKER, OUTPUT);
  for (int i = 0; i < (sizeof(BUTTONS) / sizeof(BUTTONS[0])); i++) {
    pinMode(BUTTONS[i], OUTPUT);
  }
  pinMode(HIGHER_OCTAVE_BUTTON, OUTPUT);
  pinMode(LOWER_OCTAVE_BUTTON, OUTPUT);
  Serial.begin(9600);
}

void playSound(int buttonNum) {
  while (digitalRead(BUTTONS[buttonNum])) {
    //frequency of note is (frequency at 4th octave) * 2^(distance from 4th octave)
    tone(SPEAKER, notes[buttonNum] * pow(2, octave - STARTING_OCTAVE), 100);
  }
}

void loop() {
  for (int i = 0; i < (sizeof(BUTTONS) / sizeof(BUTTONS[0])); i++) {
    playSound(i);
  }

  //checks if button to change octave is pressed and checks if the octave was already changed
  if (digitalRead(HIGHER_OCTAVE_BUTTON) && !octaveIncreased) {
    octave = constrain(octave + 1, OCTAVE_MIN, OCTAVE_MAX);
    octaveIncreased = true;
  } else if (digitalRead(LOWER_OCTAVE_BUTTON) && !octaveDecreased) {
    octave = constrain(octave - 1, OCTAVE_MIN, OCTAVE_MAX);
    octaveDecreased = true;
  }
  if (!digitalRead(HIGHER_OCTAVE_BUTTON)) octaveIncreased = false;
  if (!digitalRead(LOWER_OCTAVE_BUTTON)) octaveDecreased = false;
}
