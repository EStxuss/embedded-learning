const int redPin = 11;
const int yellowPin = 10;
const int greenPin = 9;
const unsigned long br = 9600;
const String promptBrightness = "Please enter a brightness 0 - 100: ";
const String promptColor = "Please enter a LED color (red/yellow/green): ";

int inputBrightness{};
int writeVal{};
String inputColor{};
int lastColorPin{};


void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  Serial.print(promptColor);
  while(Serial.available() == 0){}
  inputColor = Serial.readString();
  Serial.println(inputColor);
  inputColor.toLowerCase();

  if(inputColor == "red" || inputColor == "yellow" || inputColor == "green"){ 
    Serial.print(promptBrightness);
    while(Serial.available() == 0){}
    inputBrightness = Serial.parseInt();
    Serial.println(inputBrightness);

    if(inputBrightness >= 0 && inputBrightness <= 100){
      writeVal = pow(2, (8 / 100.0) * inputBrightness) - 1;
      if(lastColorPin)
        analogWrite(lastColorPin, 0);
        
      if(inputColor == "red"){
        analogWrite(redPin, writeVal);
        Serial.print("Set the red LED to brightness ");
        Serial.print(inputBrightness);
        Serial.println("/100");
        lastColorPin = redPin;
      }
      if(inputColor == "yellow"){
        analogWrite(yellowPin, writeVal);
        Serial.print("Set the yellow LED to brightness ");
        Serial.print(inputBrightness);
        Serial.println("/100");
        lastColorPin = yellowPin;
      }
      if(inputColor == "green"){
        analogWrite(greenPin, writeVal);
        Serial.print("Set the green LED to brightness ");
        Serial.print(inputBrightness);
        Serial.println("/100");
        lastColorPin = greenPin;
      }
    }
  }
}
