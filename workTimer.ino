unsigned long timerStart = 0;
int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (flag == 0) {
    if ( digitalRead(2) == HIGH ) {
    timerStart = millis();
    pomodoro();
    }
  }
}

void reset() {
  delay(2000);
  flag = 0;
}

int pomodoro() {
  while (1) {
    digitalWrite(12, HIGH);
    if ( millis() - timerStart == 5000) {
      flag = 1;
      digitalWrite(12, LOW);
      while (1) {
        if (digitalRead(2) == HIGH) {
          reset();
          return 0;
        }
        delay(100);
        digitalWrite(13, HIGH);
        delay(100);
        digitalWrite(13, LOW);
      }
    }
  }
}
