int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int potPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int potVoltage = analogRead(potPin);
  int redV = redPWM(potVoltage);
  int greenV = greenPWM(potVoltage);
  int blueV = bluePWM(potVoltage);
//  Serial.print("Pot: ");
//  Serial.print(potVoltage);
//  Serial.print(", R: ");
//  Serial.print(redV);
//  Serial.print(", G: ");
//  Serial.print(greenV);
//  Serial.print(", B: ");
//  Serial.println(blueV);
//  delay(500);
  analogWrite(redPin, redV);
  analogWrite(greenPin, greenV);
  analogWrite(bluePin, blueV);
}

int redPWM(int potVoltage) {
  int segment = 1023 / 6;
  if (potVoltage <= segment) {
    return 255;
  } else if (potVoltage > segment && potVoltage <= segment * 2) {
    return map(potVoltage, segment, segment * 2, 255, 0);
  } else if (potVoltage > segment * 2 && potVoltage <= segment * 4) {
    return 0;
  } else if (potVoltage > segment * 4 && potVoltage <= segment * 5) {
    return map(potVoltage, segment * 4, segment * 5, 0, 255);
  } else {
    return 255;
  }
}

int greenPWM(int potVoltage) {
  int segment = 1023 / 6;
  if (potVoltage <= segment) {
    return map(potVoltage, 0, segment, 0, 255);
  } else if (potVoltage > segment && potVoltage <= segment * 3) {
    return 255;
  } else if (potVoltage > segment * 3 && potVoltage <= segment * 4) {
    return map(potVoltage, segment * 3, segment * 4, 255, 0);
  } else {
    return 0;
  }
}

int bluePWM(int potVoltage) {
  int segment = 1023 / 6;
  if (potVoltage <= segment * 2) {
    return 0;
  } else if (potVoltage > segment * 2 && potVoltage <= segment * 3) {
    return map(potVoltage, segment * 2, segment * 3, 0, 255);
  } else if (potVoltage > segment * 3 && potVoltage <= segment * 5) {
    return 255;
  } else {
    return map(potVoltage, segment * 5, 1023, 255, 0);
  }
}
