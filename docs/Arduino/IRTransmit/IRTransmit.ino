#include "IRTX.h"
#define RED 5
#define BLUE 10
#define GREEN 9
#define IRTRANSMIT 3

IRTX ir (IRTRANSMIT);
unsigned long fireTimeout = 0;
unsigned long ledTimeout = 0;
int ledValue = 1;

void color(int pin) {
  digitalWrite (BLUE, 1);
  digitalWrite (GREEN, 1);
  digitalWrite (RED, 1);

  digitalWrite (pin, 0);
}

void fire() {
  Serial.println ( "Fire yo" );      
  ir.fireType = 7;
  fireTimeout = 1;
  ledTimeout = 1;
  color (BLUE);
}

void setup() {
  char ch;
  pinMode (6,INPUT);
  digitalWrite (6,1); // pull-up
  Serial.begin (115200);  
  pinMode (RED, OUTPUT);
  pinMode (BLUE, OUTPUT);
  pinMode (GREEN, OUTPUT);
  Serial.println ( "IR Transmit" );

  // color (GREEN);  
  fire();  
}

void loop() {
  static int last6 = 1;
  int value = digitalRead (6);

  if (value != last6) {
    if (value == 0) {
      Serial.println ( "Got a value of 0" );
      fire();
      delay (300);
    }
    last6 = value;
  }
  
  if (fireTimeout) {
    if (millis() > ledTimeout) { 
       digitalWrite (13,ledValue);
       ledValue = 1 - ledValue;
       ledTimeout = millis() + 500;
    }
    if (millis() > fireTimeout) {   
      if (ir.fireType)
      {
        // Allow time for each individual fire sequence.
        fireTimeout = millis() + 300; 
        ir.fireAll ();
        Serial.print ( "fireType: " );
        Serial.println ( ir.fireType );
      } else {
        fireTimeout = 0;
        Serial.println ( "Done" );
      }  
    }
  } else {
    digitalWrite (13,0);
  }
  
}
