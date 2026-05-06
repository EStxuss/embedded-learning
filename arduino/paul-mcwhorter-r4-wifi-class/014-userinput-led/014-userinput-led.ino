const int ledPin = 11;
const unsigned long br = 9600;
const unsigned long checkDelayMs = 3;

int userInput = 0;
int writeVal = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(br);
}

void loop() {
  Serial.print("Enter a integer 0 - 100: ");
  while(Serial.available() == 0)// while zero bytes in serial buffer
    delay(checkDelayMs);
    
  userInput = Serial.parseInt();
  Serial.println(userInput);
  bool withinRange = true;
  if(userInput < 0 || userInput > 100)
    withinRange = false;
  
  if(withinRange){
    writeVal = pow(2, (8 / 100.0) * userInput) - 1;
    
    analogWrite(ledPin, writeVal);

    Serial.print("The writeVal for the input was: ");
    Serial.println(writeVal);
  }
}
