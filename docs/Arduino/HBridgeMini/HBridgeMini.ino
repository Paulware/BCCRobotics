#include <MemoryFree.h>

#define FULLSPEED 255

unsigned long offTimeout = 0;
unsigned long speedTimeout = 0;
unsigned long allStopTimeout = 0;
int state = 0;

void setup() {
  char ch;
  Serial.begin (115200);
  Serial.println ( "LlFfSs to control motor" );
    
  pinMode (5, OUTPUT); 
  analogWrite (5, 0);

  pinMode (6, OUTPUT);
  analogWrite (6, 0);

  pinMode (9, OUTPUT);
  analogWrite (9, 0);

  pinMode (10, OUTPUT);
  analogWrite (10,0); 
    
  allStopTimeout = millis() + 1000;
}

void loop() {
  char ch;
  static char lastCh = ' ';
  
  if (Serial.available()) {
     ch = Serial.read();
     Serial.print (ch);
     allStopTimeout = millis() + 3000;
     if (ch == 'L')  { // Turn Left      
        analogWrite (5,0);
        analogWrite (6,FULLSPEED);
        analogWrite (10,0);
        analogWrite (9,FULLSPEED);
     } else if (ch == 'l')  { // Turn Right 
        analogWrite (6,0);
        analogWrite (5,FULLSPEED);
        analogWrite (9,0);
        analogWrite (10,FULLSPEED);
     } else if (ch == 'F') { // Forward 
        analogWrite (6,0);
        analogWrite (5,FULLSPEED);
        analogWrite (10,0);
        analogWrite (9,FULLSPEED);
     } else if (ch == 'f')  { // Reverse
        analogWrite (5,0);
        analogWrite (6,FULLSPEED);
        analogWrite (9,0);
        analogWrite (10,FULLSPEED);
     } else if ((ch == 'S') || (ch == 's')) { // stop 
        analogWrite (6,0);
        analogWrite (5,0);
        analogWrite (9,0);
        analogWrite (10,0);
     }
  }

  if (allStopTimeout) { 
     if (millis() > allStopTimeout ) { 
        digitalWrite (5,0);
        digitalWrite (6,0);
        digitalWrite (9,0);
        digitalWrite (10,0);
     }
     allStopTimeout = 0;
  }
  
}
