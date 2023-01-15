#include "Keyboard.h"
#include "Mouse.h"



int execute = 0;

int RED = 13;
int GREEN = 9;
int BLUE = 10;
int TONE = 11;

void setup() {
  // initialize control over the keyboard:
  Keyboard.begin();
  
  //Mouse.begin();

  //13 - RED
  //9 - GREEN
  //10 - BLUE
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  //appleRegister();
  
  
  
  
}

void loop() {
delay(300); //Delay of 300ms is needed inorder for serial interface to setup correctly before the commands can parse.

if(execute<1){
 
  payload(); //run attack payload
  }
  
  digitalWrite(GREEN, HIGH);   // turn the LED on (HIGH is the voltage level)

}



void appleRegister(){
      // Apple Register
//      2880 x 1800
    digitalWrite(RED, HIGH);
    delay(1000);
    Mouse.move(char(-2880),char(-1800),0);
    delay(1000);
    digitalWrite(RED, LOW);
    delay(250);
    digitalWrite(RED, HIGH);
    Mouse.move(char(1440),char(900),0);
    
    
    Keyboard.print("z");
    Keyboard.print("/");
    digitalWrite(RED, LOW);
    Keyboard.print("\n");
}

void payload(){
  
    //BadArduino Payload
    digitalWrite(BLUE, HIGH);
    delay(300);
    Keyboard.press(KEY_LEFT_GUI); 
    Keyboard.print(" ");
    Keyboard.release(KEY_LEFT_GUI);
    delay(300);
    Keyboard.print("terminal");
    delay(300);
    Keyboard.print("\n");
    delay(300);
    
    Keyboard.print("printf \"\\033c*************************************\n****     BAD LEOSTICK PAYLOAD    ****\n**** Your Computer is vunerable  ****\n*************************************\n\"");
    Keyboard.print("\n");
    
    
    //Keyboard.print("Bad Arduino!");
    //Keyboard.print("\n");
    //Keyboard.print("Using a Freetronics Leostick");
    //Keyboard.print("\n");
    //Keyboard.print("This is a SysAdmins nightmare!");
    //Keyboard.print("\n");
    digitalWrite(BLUE, LOW);
    //tune();
    //deathMarch();
    execute=1;
}

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void tune() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(11, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(11);
  }
}

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const int buzzerPin = 11; // Digital Pin 8
const int ledPin1 = 13;  // Digital Pin 12
const int ledPin2 = 10;  // Digital Pin 13 Built In Led can Change it if you want

int counter = 0;



void deathMarch()
{

  //Play first section
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);


  //Play second section
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);

  delay(325);

  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  

  delay(350);
  
//  //Variant 1
//  beep(f, 250);  
//  beep(gS, 500);  
//  beep(f, 350);  
//  beep(a, 125);
//  beep(cH, 500);
//  beep(a, 375);  
//  beep(cH, 125);
//  beep(eH, 650);
//
//  delay(500);
//
//  //Repeat second section
//  beep(aH, 500);
//  beep(a, 300);
//  beep(a, 150);
//  beep(aH, 500);
//  beep(gSH, 325);
//  beep(gH, 175);
//  beep(fSH, 125);
//  beep(fH, 125);    
//  beep(fSH, 250);
//
//  delay(325);
//
//  beep(aS, 250);
//  beep(dSH, 500);
//  beep(dH, 325);  
//  beep(cSH, 175);  
//  beep(cH, 125);  
//  beep(b, 125);  
//  beep(cH, 250);  
//
//  delay(350);
  //Variant 2
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);  
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }

  //Stop tone on buzzerPin
  noTone(buzzerPin);

  delay(50);

  //Increment counter
  counter++;
}




