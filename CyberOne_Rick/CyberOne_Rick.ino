
/*
  Copyright (c) 2017 Seytonic, Spacehuhn (Licensed under MIT)
  For more information see: github.com/seytonic/malduino
*/

#include "Keyboard.h"
#include "Mouse.h"

#define blinkIntervalOne 50
#define blinkIntervalTwo 500
#define RED 13
#define GREEN 9
#define BLUE 10
#define TONE 11
#define buttonPin 6

#define interval 5000 //30 seconds
int defaultDelay = 90;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;
int execute = 0;
int trigger = 2;

bool ledOn = true;


unsigned long previousMillis = 0;

void typeKey(int key) {
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);

  if (execute < 1) {
    payload(trigger);
    trigger++;
  }

}

void macRun() { //trigger 1
  //Spolight Search
  delay(defaultDelay);
  Keyboard.press(KEY_LEFT_GUI);
  delay(defaultDelay);
  Keyboard.print(" ");
  delay(defaultDelay);
  Keyboard.releaseAll();
  delay(defaultDelay);

}

void winRun() { //trigger 2
  //run window
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.print("r");
  Keyboard.releaseAll();
  delay(defaultDelay);
}

void linRun() { //trigger 3
  //Terminal
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.print("t");
  Keyboard.releaseAll();
  delay(defaultDelay);
}

void payload(int trigger) {
  digitalWrite(RED, HIGH);
  Keyboard.begin();
  Mouse.begin();

  /* ----- Begin-Script -----*/

  /* [Parsed By Duckuino (Licensed under MIT) - for more information visit: https://github.com/Nurrl/Dckuino.js] */
  delay(2000);

  delay(defaultDelay);
  switch (trigger) {
    case 1:
      macRun();
      break;
    case 2:
      winRun();
      break;
    case 3:
      linRun();
      break;

  }
  //winRun();
  //linRun();

  delay(2000);
  delay(defaultDelay);
  Keyboard.print("https://www.youtube.com/watch?v=dQw4w9WgXcQ");

  delay(defaultDelay);
  Keyboard.press(KEY_RETURN);
  delay(defaultDelay);
  Keyboard.release(KEY_RETURN);
  delay(defaultDelay);

  delay(3000);
  delay(defaultDelay);

  delay(2000); //wait before going fullscreen

  Keyboard.print("f");

  /* ----- End-Script -----*/

  Keyboard.end();
  execute = 1;
  digitalWrite(RED, LOW);

}

void loop() {
  unsigned long currentMillis = millis();
  delay(3000);
  ledOn = !ledOn;
  digitalWrite(GREEN, ledOn);
  delay(blinkIntervalTwo);

  payload(1);
  
  //if (currentMillis - previousMillis >= interval) {
  //  previousMillis += interval;
  //  payload(trigger);
  //  trigger = trigger + 1;
  //  if (trigger == 4) {
  //    trigger = 1;
  //  }
  //}


}


/*

*/
