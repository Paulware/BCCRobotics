unsigned long ledTimeout = 0;
void setup() {
   pinMode (13,OUTPUT);
   digitalWrite (13,1);
   Serial.begin (115200);
   Serial.println ( "Ready" );
   ledTimeout = millis() + 3000;
}

void loop() {
  char ch;
  if (Serial.available()) {
    ch = Serial.read();
    if (ch == 'A') {
      digitalWrite (13,0);
    } else if (ch == 'B') {
      digitalWrite (13,1);
    }
  }
  if (ledTimeout) {
    if (millis() > ledTimeout) {
       digitalWrite (13,0);
       ledTimeout = 0;
    }
  }
}
