

/* Bad Arduino based on the HID Keyboard emulator from kevin demarco 
 *  http://www.kevindemarco.com/2014/01/02/arduino-uno-as-a-usb-hid-interface/
*/
uint8_t buf[8] = {0 }; /* Keyboard report buffer */

int execute = 0;
int ledPin = 9;

void setup(){
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop(){
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  if(execute<1){
    
    digitalWrite(8,HIGH);
    payload();
    
    digitalWrite(8,LOW);
    digitalWrite(7, HIGH);
    delay(250);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(7, HIGH);
    delay(250);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(7, HIGH);
    delay(250);
    digitalWrite(7, LOW);
  }
  else{
// fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 50; fadeValue += 1) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 50 ; fadeValue >= 0; fadeValue -= 1) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  delay(1000);
  }
}

void releaseKey(){
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
  delay(5);
}

void payload(){

//APPLE KEYBOARD REGISTER

//buf[0] = 0x00;
//buf[2] = 0x1D; //z
//Serial.write(buf, 8); // Release key
//releaseKey();

//buf[0] = 0x00;
//buf[2] = 0x38; //z
//Serial.write(buf, 8); // Release key
//releaseKey();

// SOME HOW NEED TO PRESS THE DONE BUTTON HERE>>>


//BAD ARDUINO!
    buf[0] = 0x02;
    buf[2] = 0x05; //b
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x04; //a
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x07; //d
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x2C; //Space
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0x02; //SHIFT
    buf[2] = 0x04; //A
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x15; //r
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x07; //d
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x18; //u
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x0C; //i
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x11; //n
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0;
    buf[2] = 0x12; //o
    Serial.write(buf, 8); // Release key
    releaseKey();
  
    buf[0] = 0x02; //SHIFT
    buf[2] = 0x1E; //!
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0; 
    buf[2] = 0x28; //Return
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0x02;
    buf[2] = 0x05; //b
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0x00;
    buf[2] = 0x1C; //b
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x2C; //Space
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0x02;
    buf[2] = 0x15; //R
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0;
    buf[2] = 0x0C; //i
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x06; //c
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x0B; //h
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0;
    buf[2] = 0x04; //a
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x15; //r
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x07; //d
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x2C; //Space
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0x02;
    buf[2] = 0x10; //M
    Serial.write(buf, 8); // Release key
    releaseKey();
   
    buf[0] = 0;
    buf[2] = 0x04; //a
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0;
    buf[2] = 0x17; //t
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0;
    buf[2] = 0x17; //t
    Serial.write(buf, 8); // Release key
    releaseKey();
    
    buf[0] = 0;
    buf[2] = 0x0B; //h
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x08; //e
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x1A; //w
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0;
    buf[2] = 0x16; //s
    Serial.write(buf, 8); // Release key
    releaseKey();

    buf[0] = 0; 
    buf[2] = 0x28; //Return
    Serial.write(buf, 8); // Release key
    releaseKey();
  execute = 1;
}

