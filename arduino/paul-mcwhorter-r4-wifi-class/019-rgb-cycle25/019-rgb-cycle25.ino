#define CYCLE_AMT 25

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int br = 115200;
const int waitMs = 1000;
const int flashMs = 250;

void setup() {
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  static int cycleCount = 0, currLed = 0;
  static bool blueLit = false;

  if(cycleCount < CYCLE_AMT){
    switch(currLed){
      case 0: //red
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        delay(flashMs);
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        break;
      case 1: //green
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, LOW);
        delay(flashMs);
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        break;
      case 2: //blue
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, HIGH);
        delay(flashMs);
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        blueLit = true;
        break;
    }
  }

  currLed = (currLed + 1) % 3;
  
  if(blueLit){
    cycleCount++;
    delay(waitMs);
    blueLit = false;
  }else{
    delay(flashMs);
  }

}
