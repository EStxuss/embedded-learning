const int redPin = 12;
const int greenPin = 11;
const int redBlinks = 10;
const int greenBlinks = 5;
const int redMs = 250;
const int greenMs = 100;
const int waitMs = 1000;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for(int i = 0; i < greenBlinks; ++i){
    digitalWrite(greenPin, HIGH);
    delay(greenMs);
    digitalWrite(greenPin, LOW);
    delay(greenMs);
  }
  delay(waitMs);
  for(int i = 0; i < redBlinks; ++i){
    digitalWrite(redPin, HIGH);
    delay(redMs);
    digitalWrite(redPin, LOW);
    delay(redMs);
  }
  delay(waitMs);
}
