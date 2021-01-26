int green = 5;
int redOne = 4;
int redTwo = 3;
int SWITCH = 2;

void setup() {
  pinMode(SWITCH, INPUT);
  pinMode(green, OUTPUT);
  pinMode(redOne, OUTPUT);
  pinMode(redTwo, OUTPUT);
}

int switchState = LOW;

void loop() {
  if (switchState == LOW) {
    switchState = digitalRead(SWITCH);
    digitalWrite(green, HIGH);
    digitalWrite(redOne, LOW);
    digitalWrite(redTwo, LOW);
  } else {
    digitalWrite(green, LOW);
    digitalWrite(redOne, HIGH);
    digitalWrite(redTwo, LOW);
    delay(250);
    digitalWrite(redOne, LOW);
    digitalWrite(redTwo, HIGH);
    delay(250);
  }
}
