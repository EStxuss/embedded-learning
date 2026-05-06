bool bin[5] = {false, false, false, false, false};
int led[5] = {9, 10, 11, 12, 13};
const unsigned long onMs = 500;
const unsigned long offMs = 500;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 5; ++i)
    pinMode(led[i], OUTPUT);
  delay(offMs);
}

void loop() { 
  // put your main code here, to run repeatedly:
  for(int i = 4; i >= 0; --i){
    if(bin[i] == false){
      bin[i] = true;
      digitalWrite(led[i], HIGH);
      break;
    }
    else{
      bin[i] = false;
      digitalWrite(led[i], LOW);
    }
  }
  delay(onMs);
}
