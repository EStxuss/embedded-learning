bool forward = true;
unsigned long forwardLitMs = 100;
unsigned long forwardOffMs = 0;
unsigned long backLitMs = 500;
unsigned long backOffMs = 250;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(forward){
    digitalWrite(13, HIGH);
    delay(forwardLitMs);
    digitalWrite(13, LOW);
    delay(forwardOffMs);

    digitalWrite(12, HIGH);
    delay(forwardLitMs);
    digitalWrite(12, LOW);
    delay(forwardOffMs);
    
    digitalWrite(11, HIGH);
    delay(forwardLitMs);
    digitalWrite(11, LOW);
    delay(forwardOffMs);

    digitalWrite(10, HIGH);
    delay(forwardLitMs);
    digitalWrite(10, LOW);
    delay(forwardOffMs);
    
    delay(1000);
    forward = false;
  }
  else{
    digitalWrite(10, HIGH);
    delay(backLitMs);
    digitalWrite(10, LOW);
    delay(backOffMs);

    digitalWrite(11, HIGH);
    delay(backLitMs);
    digitalWrite(11, LOW);
    delay(backOffMs);
    
    digitalWrite(12, HIGH);
    delay(backLitMs);
    digitalWrite(12, LOW);
    delay(backOffMs);

    digitalWrite(13, HIGH);
    delay(backLitMs);
    digitalWrite(13, LOW);
    delay(backOffMs);
    
    delay(1000);
    forward = true;
  }
}