/* RUBIKS CUBE SOLVER
 *  
 * KEY
 * 1      white
 * 2      yellow
 * 3      blue
 * 4      green
 * 5      red
 * 6      orange
 */
int motorFront = 3;
int motorUp = 5;
int motorDown = 6;
int motorBack = 9;
int motorLeft = 10;
int motorRight = 11;
int buttonPin = 2;
int cube[][] = {{2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {4, 4, 4, 6, 6, 6, 3, 3, 3, 5, 5, 5},
               {4, 4, 4, 6, 6, 6, 3, 3, 3, 5, 5, 5},
               {4, 4, 4, 6, 6, 6, 3, 3, 3, 5, 5, 5},
               {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorFront, OUTPUT);
  pinMode(motorUp, OUTPUT);
  pinMode(motorDown, OUTPUT);
  pinMode(motorBack, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
}
void move(int motorPin, int speed) {
  
}
void moveRow(int row, int direction) {
  
}
void swap(int row1, int col1, int row2, int col2) {
  
}
void swapCol(int row1, int col1, int row2, int col2) {
  
}
void swapRowWithCol(int row1, int col1, int row2, int col2) {
  
}
void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    
  }
}

