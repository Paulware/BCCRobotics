#define BLUE 4
#define GREEN 7
#define RED 8
#define BUZZER 2

unsigned long ledTimeout = 0;
int ledValue = 1;
int ledPins[] = {4,7,8};

void setup() {
   for (int i=0; i<3; i++) {
      pinMode (ledPins[i], OUTPUT);
      digitalWrite (ledPins[i], 1);
   }
   digitalWrite (BLUE, 0);
   pinMode (13,OUTPUT);
   digitalWrite (13,1);
   Serial.begin (115200);
   Serial.println ( "Ready" );
   ledTimeout = 1;
   tone(BUZZER,440,300);
   delay (1000);
   noTone (BUZZER);
}

void loop() {
  char ch;
  if (Serial.available()) {
    ch = Serial.read();
    if (ch == 'A') {
      digitalWrite (13,0);
      ledTimeout = 0;
    } else if (ch == 'B') {
      digitalWrite (13,1);
      ledTimeout = 0;
    }
  }
  if (ledTimeout) {
    if (millis() > ledTimeout) {
       digitalWrite (13,ledValue);
       ledValue = 1 - ledValue;
       ledTimeout = millis() + 500;
    }
  }
}
