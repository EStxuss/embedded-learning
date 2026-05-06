const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;
const unsigned long br = 9600;
const String prompt = "Turn on which LED (red, yellow, green): ";

String inputStr{};
int lastColorPin{};

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  Serial.print(prompt);
  
  while(Serial.available() == 0){}
  
  inputStr = Serial.readString();
  Serial.println(inputStr);

  inputStr.toLowerCase();

  if(lastColorPin)
    digitalWrite(lastColorPin, LOW);

  if(inputStr == "red"){
    digitalWrite(redPin, HIGH);
    Serial.println("Turned on the red LED");
    lastColorPin = redPin;
  }
  else if(inputStr == "yellow"){
    digitalWrite(yellowPin, HIGH);
    Serial.println("Turned on the yellow LED");
    lastColorPin = yellowPin;
  }
  else if(inputStr == "green"){
    digitalWrite(greenPin, HIGH);
    Serial.println("Turned on the green LED");
    lastColorPin = greenPin;
  }
}
