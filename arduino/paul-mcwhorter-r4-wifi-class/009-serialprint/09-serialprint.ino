const String ledOffMsg = "The LED is OFF";
const String ledOnMsg = "The LED is ON";
const int ledMs = 1000;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println(ledOnMsg);
  Serial.println();
  delay(ledMs);

  digitalWrite(ledPin, LOW);
  Serial.println(ledOffMsg);
  Serial.println();
  delay(ledMs);
}
