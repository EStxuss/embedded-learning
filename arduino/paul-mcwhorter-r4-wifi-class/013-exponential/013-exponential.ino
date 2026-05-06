const int ledPin = 11;
const int potPin = A0;
const unsigned long br = 9600;
const int delayMs = 100;
int potVal = 0;
int writeVal = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(br);
}

void loop() {
  potVal = analogRead(potPin);
  
  writeVal = pow(2, (8 / 1023.0) * potVal) - 1;

  analogWrite(ledPin, writeVal);
  
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("      writeVal: ");
  Serial.print(writeVal);
  Serial.println();

  delay(delayMs);
}
