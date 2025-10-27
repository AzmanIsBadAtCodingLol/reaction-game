#define B1 7
#define B2 6
#define B3 5
#define L1 4
#define L2 3
#define L3 2
#define L4 11

void setup() {
  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);

  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);

  randomSeed(analogRead(0));
}

void loop() {
  unsigned long waitTime = random(500, 2000);
  unsigned long startTime = millis();
  
  while (millis() - startTime < waitTime) {
    if (digitalRead(B1) == LOW) { digitalWrite(L1, HIGH); while(1); }
    if (digitalRead(B2) == LOW) { digitalWrite(L2, HIGH); while(1); }
    if (digitalRead(B3) == LOW) { digitalWrite(L3, HIGH); while(1); }
  }

  digitalWrite(L4, HIGH); // go


  while (true) {
    int b1 = digitalRead(B1);
    int b2 = digitalRead(B2);
    int b3 = digitalRead(B3);

    if (b1 == LOW && b2 == LOW && b3 == LOW) {
      digitalWrite(L1, HIGH);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, HIGH);
      digitalWrite(L4, LOW);
      break;
    } 
    else if (b1 == LOW) {
      digitalWrite(L1, HIGH);
      digitalWrite(L4, LOW);
      break;
    } 
    else if (b2 == LOW) {
      digitalWrite(L2, HIGH);
      digitalWrite(L4, LOW);
      break;
    }
    else if (b3 == LOW) {
      digitalWrite(L3, HIGH);
      digitalWrite(L4, LOW);
      break;
    }
  }

  // LEDs stay lit forever
  while (1);
}
