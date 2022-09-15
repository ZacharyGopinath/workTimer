unsigned long timerStart = 0;
int flag = 0; // 0 = ready to restart timer, 1 = resetting

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // timer done LED
  pinMode(12, OUTPUT); // timer ON LED
  pinMode(2, INPUT); // button
}

void loop() {
  if (flag == 0) {
    if ( digitalRead(2) == HIGH ) { // button pressed, start timer
    timerStart = millis(); // time at button pressed
    workTimer();
    }
  }
}

void reset() { // wait before able to start timer again
  delay(2000); // 2s
  flag = 0;
}

int workTimer() {
  while (1) { // wait for countdown
    digitalWrite(12, HIGH); // time ON LED ON
    if ( millis() - timerStart == 5000) { // 5s, change 5000 to desired timer in ms
      flag = 1; // don't restart workTimer() on next button press
      digitalWrite(12, LOW);
      while (1) {
        if (digitalRead(2) == HIGH) { // press button again to stop blinking
          reset();
          return 0;
        }
        delay(100);
        digitalWrite(13, HIGH); // blink LED
        delay(100);
        digitalWrite(13, LOW);
      }
    }
  }
}
