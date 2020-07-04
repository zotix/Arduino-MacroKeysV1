#include "DigiKeyboard.h"

#define input1 1
#define input2 0    // Work
#define input3 2
//#define key4 5

#define repeatDelay 500/delayTime   // ms     // Delay before repeat
#define repeatRate 300/delayTime // ms
#define delayTime 50 // ms
#define delayPush 50

// Protect repeat
bool key1 = false;
bool key2 = false;
bool key3 = false;
bool key4 = false;

// Can improve to array 
unsigned int delayKey1 = 0;
unsigned int delayKey2 = 0;
unsigned int delayKey3 = 0;
unsigned int delayKey4 = 0;

unsigned int countKey1 = 0;
unsigned int countKey2 = 0;
unsigned int countKey3 = 0;
unsigned int countKey4 = 0;

unsigned int count = 0;

void setup() {
  // Setup pins
  pinMode(0, INPUT);  // input
  pinMode(1, INPUT);  // Display system 
  pinMode(2, INPUT);
//  pinMode(3, INPUT);  // USB
//  pinMode(4, INPUT);  // USB
//  pinMode(5, INPUT);  // Reset
}


void loop() {

  // Reset btn  // limitation cannot detect push two buttom same time
  // Not seperation because key 4 common use input 1 and input 3
  if ((!btn_push(input1) && !btn_push(input2) && !btn_push(input3))){
    key1 = false;
    key2 = false;
    key3 = false;
    key4 = false;
  }

  // Repeat btn
  if (key1) {     // key push
    delayKey1++;
    if (delayKey1 >= repeatDelay) {
      countKey1++;  // Start count
      if (countKey1 >= repeatRate){ // Count > Repeat Rate
        key1 = false;     // key not push
        countKey1 = 0;    // Reset count
      }
    }
  } else {            // key not push
    delayKey1 = 0;
    countKey1 = 0;    // Reset count
  }
  
  if (key2) {     // key push
    delayKey2++;
    if (delayKey2 >= repeatDelay) {
      countKey2++;  // Start count
      if (countKey2 >= repeatRate){ // Count > Repeat Rate
        key2 = false;     // key not push
        countKey2 = 0;    // Reset count
      }
    }
  } else {            // key not push
    delayKey2 = 0;
    countKey2 = 0;    // Reset count
  }
  
  if (key3) {     // key push
    delayKey3++;
    if (delayKey3 >= repeatDelay) {
      countKey3++;  // Start count
      if (countKey3 >= repeatRate){ // Count > Repeat Rate
        key3 = false;     // key not push
        countKey3 = 0;    // Reset count
      }
    }
  } else {            // key not push
    delayKey3 = 0;
    countKey3 = 0;    // Reset count
  }
    
  if (key4) {     // key push
    delayKey4++;
    if (delayKey4 >= repeatDelay) {
      countKey4++;  // Start count
      if (countKey4 >= repeatRate){ // Count > Repeat Rate
        key4 = false;     // key not push
        countKey4 = 0;    // Reset count
      }
    }
  } else {            // key not push
    delayKey4 = 0;
    countKey4 = 0;    // Reset count
  }

  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  if (count >= 1000) {
    DigiKeyboard.sendKeyStroke(0);
  }
  

  if ((key1 == false) && btn_push(input1) && !btn_push(input3)) {
    DigiKeyboard.sendKeyPress(KEY_1, MOD_CONTROL_LEFT| MOD_ALT_LEFT| MOD_SHIFT_RIGHT );
    delay(delayPush);
    DigiKeyboard.sendKeyPress(0,0);
//    DigiKeyboard.println('A');
    key1 = true;
  }

  if ((key2 == false) && btn_push(input2)) {
    DigiKeyboard.sendKeyPress(KEY_2, MOD_CONTROL_LEFT| MOD_ALT_LEFT| MOD_SHIFT_RIGHT );
    delay(delayPush);
    DigiKeyboard.sendKeyPress(0,0);
//    DigiKeyboard.println('B');
    key2 = true;
  }
  
  if ((key3 == false) && !btn_push(input1) && btn_push(input3)) {
    DigiKeyboard.sendKeyPress(KEY_3, MOD_CONTROL_LEFT| MOD_ALT_LEFT| MOD_SHIFT_RIGHT );
    delay(delayPush);
    DigiKeyboard.sendKeyPress(0,0);
//    DigiKeyboard.println('C');
    key3 = true;
  }

  if ((key4 == false) && btn_push(input1) && btn_push(input3)) {
    DigiKeyboard.sendKeyPress(KEY_4, MOD_CONTROL_LEFT| MOD_ALT_LEFT| MOD_SHIFT_RIGHT );
    delay(delayPush);
    DigiKeyboard.sendKeyPress(0,0);
//    DigiKeyboard.println('D');
    key4 = true;
  }

//  DigiKeyboard.sendKeyStroke(KEY_V,MOD_CONTROL_LEFT| MOD_ALT_LEFT );
//  DigiKeyboard.sendKeyPress(0,0);

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(delayTime);
}

bool btn_push(int input) {
  if (digitalRead(input) == HIGH) {
    return true;
  }
  return false;
}
