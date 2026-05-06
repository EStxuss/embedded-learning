const unsigned long br = 115200;
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.print("Please select a color\nOptions: red, green, blue, cyan, orange, magenta, yellow, white\n");
  while(Serial.available() == 0){}

  String colorChoice = Serial.readStringUntil('\n');
  colorChoice.toLowerCase();
  
  if(colorChoice == "red"){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }else if(colorChoice == "green"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }else if(colorChoice == "blue"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }else if(colorChoice == "cyan"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }else if(colorChoice == "orange"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255 / 16);
    analogWrite(bluePin, 0);
  }else if(colorChoice == "magenta"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255 / 32);
  }else if(colorChoice == "yellow"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255 / 8);
    analogWrite(bluePin, 0);
  }else if(colorChoice == "white"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255 / 4);    
    analogWrite(bluePin, 255 / 4);
  }
}
