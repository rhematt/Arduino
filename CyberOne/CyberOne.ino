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

int defaultDelay = 50;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;
int execute = 0;

bool ledOn = true;

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

    payload(); //run attack payload
  }


}

void payload() {
  digitalWrite(RED, HIGH);
  Keyboard.begin();
  Mouse.begin();

  /* ----- Begin-Script -----*/

  /* [Parsed By Duckuino (Licensed under MIT) - for more information visit: https://github.com/Nurrl/Dckuino.js] */
  delay(1000);

  delay(defaultDelay);
  Keyboard.press(KEY_LEFT_GUI);
  //Keyboard.press(KEY_LEFT_CTRL);
  //Keyboard.press(KEY_LEFT_ALT);
  Keyboard.print(" ");
  Keyboard.releaseAll();

  delay(2000);

  delay(defaultDelay);
  Keyboard.print("https://www.youtube.com/watch?v=dQw4w9WgXcQ");

  delay(defaultDelay);
  typeKey(KEY_RETURN);

  delay(3000);

  delay(defaultDelay);
  Keyboard.print("f");

  /* ----- End-Script -----*/

  Keyboard.end();
  execute = 1;
  digitalWrite(RED, LOW);

}

void loop() {
  ledOn = !ledOn;
  digitalWrite(GREEN, ledOn);
  delay(blinkIntervalTwo);
  
}
