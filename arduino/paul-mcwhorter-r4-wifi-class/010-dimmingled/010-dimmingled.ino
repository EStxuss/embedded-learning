const int ledPin = 11;
const int dimInc = 5;
const int dimMin = 1;
const int dimMax = 255;
const unsigned long holdMs = 5;
const String stateMsg = "The LED Brighness is: ";
float dimPercent = dimMin / 255;
bool dimming = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  analogWrite(ledPin, dimMin);
}

void loop() {
  if(dimming){
    for(int i = dimMax - 1; i >= dimMin;){
      analogWrite(ledPin, i);
      dimPercent = i / 255.0f * 100;
      Serial.print(stateMsg);
      Serial.print(dimPercent);
      Serial.println('%');
      delay(holdMs);
      if(i == dimMin) break;
      i = (i - dimInc < dimMin) ? dimMin : i - dimInc;
    }
    dimming = false;
  }
  else{
    for(int i = dimMin + 1; i <= dimMax;){
      analogWrite(ledPin, i);
      dimPercent = i / 255.0f * 100;
      Serial.print(stateMsg);
      Serial.print(dimPercent);
      Serial.println('%');
      delay(holdMs);
      if(i == dimMax) break;
      i = (i + dimInc > dimMax) ? dimMax : i + dimInc;
    }
    dimming = true;
  }
}
