/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */
#include <Bounce.h>



// constants won't change. They're used here to
// set pin numbers:
const int buttonPin    = 2;     // the number of the pushbutton pin
const int RED_PIN      = 3;
const int YELLOW_PIN   = 4;
const int GREEN_PIN    = 5;
Bounce bouncer = Bounce(buttonPin, 50);

const int RED_LIGHT    = 0;
const int YELLOW_LIGHT = 1;
const int GREEN_LIGHT  = 2;
const int YELLOW_LIGHT_2 = 3;

const int MODE_AUTO = 0;
const int MODE_BLINK_YELLOW = 1;



// variables will change:
int currentLight = 0;
int currentMode = 0;


void setup() {
//  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  // initialize the pushbutton pin as an input:
}

void loop() {
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if(bouncer.update() == true && bouncer.read() == HIGH) {
    // turn LED on:
    currentLight++;
  }
  if (currentLight > YELLOW_LIGHT_2){
    currentLight = 0;
  }

  if (currentLight == RED_LIGHT){
    digitalWrite(RED_PIN    , HIGH);
    digitalWrite(YELLOW_PIN , LOW);
    digitalWrite(GREEN_PIN  , LOW);
  }else if (currentLight == YELLOW_LIGHT || currentLight == YELLOW_LIGHT_2){
    digitalWrite(RED_PIN    , LOW);
    digitalWrite(YELLOW_PIN , HIGH);
    digitalWrite(GREEN_PIN  , LOW);
  }else if (currentLight == GREEN_LIGHT){
    digitalWrite(RED_PIN    , LOW);
    digitalWrite(YELLOW_PIN , LOW);
    digitalWrite(GREEN_PIN  , HIGH);
  }
  delay(100);
}
