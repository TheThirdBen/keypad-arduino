#define MAX_ULONG 4294967295  // 0xFFFFFFFFdelta_time = (time2 < time1)? (MAX_ULONG - time1) + time2: time2 - time1;
char oldKeypadState;
char newKeypadState;
unsigned long lastDebounceCheck = 0;
unsigned long debounceDelay = 100000;
void setup() {
  //Rows from top to bottom
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  //Columns from left to right
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  oldKeypadState = -2;
  newKeypadState = -1;
}

char determineKeyPressed() {
  /*
Col   4   3   2

      1   2   3     Row 12
      4   5   6         11
      7   8   9         10
      *   0   #          9
  
  */
  char keyPressed;
  if (digitalRead(12) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '1';
              else if (digitalRead(3) == LOW) keyPressed = '2';
              else if (digitalRead(2) == LOW) keyPressed = '3';
              else keyPressed = NULL;
  }
  else if (digitalRead(11) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '4';
              else if (digitalRead(3) == LOW) keyPressed = '5';
              else if (digitalRead(2) == LOW) keyPressed = '6';
              else keyPressed = NULL;
  }
  else if (digitalRead(10) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '7';
              else if (digitalRead(3) == LOW) keyPressed = '8';
              else if (digitalRead(2) == LOW) keyPressed = '9';
              else keyPressed = NULL;
  }
  else if (digitalRead(9) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '*';
              else if (digitalRead(3) == LOW) keyPressed = '0';
              else if (digitalRead(2) == LOW) keyPressed = '#';
              else keyPressed = NULL;
  }
  else keyPressed = NULL;
  return keyPressed;
  Serial.println("Press a button");
}

void loop() {
  // put your main code here, to run repeatedly:
  
// test button input
//  
//  if (digitalRead(11) == LOW){
//    if (digitalRead(3) == LOW)
//      newKeypadState = '5';
//    else if (digitalRead(2) == LOW)
//      newKeypadState = '6';
//    else if (digitalRead(4) == LOW)
//      newKeypadState = '4';
//  }
//  else newKeypadState = 'z';

  char keyPressed;
  if (digitalRead(12) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '1';
              else if (digitalRead(3) == LOW) keyPressed = '2';
              else if (digitalRead(2) == LOW) keyPressed = '3';
              else keyPressed = NULL;
  }
  else if (digitalRead(11) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '4';
              else if (digitalRead(3) == LOW) keyPressed = '5';
              else if (digitalRead(2) == LOW) keyPressed = '6';
              else keyPressed = NULL;
  }
  else if (digitalRead(10) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '7';
              else if (digitalRead(3) == LOW) keyPressed = '8';
              else if (digitalRead(2) == LOW) keyPressed = '9';
              else keyPressed = NULL;
  }
  else if (digitalRead(9) == LOW){
              if      (digitalRead(4) == LOW) keyPressed = '*';
              else if (digitalRead(3) == LOW) keyPressed = '0';
              else if (digitalRead(2) == LOW) keyPressed = '#';
              else keyPressed = NULL;
  }
  else keyPressed = NULL;
//  
  //Debouncing
  
  if (oldKeypadState != keyPressed) {
    lastDebounceCheck = micros();  
  }

  unsigned long time1 = micros();
  unsigned long delta_time = (time1 < lastDebounceCheck)? (MAX_ULONG - time1) + lastDebounceCheck: lastDebounceCheck - time1;
  if (delta_time > debounceDelay) {
    if ((oldKeypadState != keyPressed) && (keyPressed != NULL)) { 
      Serial.println(keyPressed);
    }
    oldKeypadState = keyPressed;
  }
}

