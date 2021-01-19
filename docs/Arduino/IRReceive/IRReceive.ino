#include "IRRX.h"
#include "TimerOne.h"

#define IRRECEIVEPIN 17
#define RED 5
#define BLUE 10
#define GREEN 9

IRRX ir (IRRECEIVEPIN);

unsigned long ledTimeout = 0;
unsigned long blinkTimeout;
int ledValue = 1;

void color(int pin) {
  digitalWrite (BLUE, 1);
  digitalWrite (GREEN, 1);
  digitalWrite (RED, 1);

  digitalWrite (pin, 0);
}
void callback() // Timer1 is set to 50 microsecond to balance PWM output
{
    ir.callback();
}

void setup() {
    
  Serial.begin (115200); // Baud rate of bluetooth serial
  pinMode (5,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  
  Serial.println ( "\nIR Receive" );  

  Timer1.initialize (50);
  Timer1.attachInterrupt(callback,50);
  ledTimeout = millis() + 5000;  

  color (BLUE);
}

void loop () {
  int irValue;

  irValue = ir.IRDetected();
  if (irValue != 0) {
    Serial.print ( "Received: ");
    Serial.println ( irValue,HEX);
    ledTimeout = millis() + 3000;
    color (RED);
  } 

  if (ledTimeout) {
     if (millis() > blinkTimeout) {
         blinkTimeout = millis() + 500;
         digitalWrite (13,ledValue);
         ledValue = 1 - ledValue;      
     }
     if (millis() > ledTimeout ) {
        ledTimeout = 0;      
        color (GREEN);
     }    
  }
}
