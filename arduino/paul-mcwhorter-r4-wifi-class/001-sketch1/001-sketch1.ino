const int onboard_led = 13;
const unsigned long led13_toggle_ms = 1000;

unsigned long last_toggle_ms = 0;
bool led13_on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(onboard_led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - last_toggle_ms >= led13_toggle_ms){
    last_toggle_ms = millis();
    if(led13_on){
      digitalWrite(onboard_led, LOW);
      led13_on = false;
    }
    else{
      digitalWrite(onboard_led, HIGH);
      led13_on = true;
    }
  }
}
