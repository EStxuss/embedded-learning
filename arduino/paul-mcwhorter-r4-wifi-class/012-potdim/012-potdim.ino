const int potPin = A0;
const int ledPin = 11;
int potVal{};
int ledVal{};
float brightness{};
const int br = 9600;
const int readDelayMs = 125;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(br);
}

void loop() {
  potVal = analogRead(potPin);
  ledVal = (potVal / 1023.0f) * 255;
  brightness = (ledVal / 255.0f) * 100;

  analogWrite(ledPin, ledVal);
  
  Serial.print("LED Value: ");
  Serial.print(ledVal);
  Serial.print('/');
  Serial.print(255);
  Serial.print("   Brightness: ");
  Serial.print(brightness);
  Serial.println('%');
  Serial.println();
  
  delay(readDelayMs);
}
