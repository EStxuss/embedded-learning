int led1_pin = 13;
int led2_pin = 12;
int led3_pin = 11;
int led4_pin = 10;

const unsigned long long_duration_on_ms = 2500;
const unsigned long short_duration_on_ms = 150;
const unsigned long duration_off_ms = 150;

unsigned long last_led_toggle = 0;
int blink_num = 0;
bool long_blink = true;
bool led_on = true;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led4_pin, OUTPUT);
  digitalWrite(led1_pin, HIGH);
  digitalWrite(led2_pin, HIGH);
  digitalWrite(led3_pin, HIGH);
  digitalWrite(led4_pin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(long_blink && led_on){
    if(millis() - last_led_toggle >= long_duration_on_ms){
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW);
      digitalWrite(led4_pin, LOW);
      led_on = false;
      last_led_toggle = millis();
      ++blink_num;
      if(blink_num == 3){
        long_blink = false;
        blink_num = 0;
      }
    }
  }else if(!long_blink && led_on){
    if(millis() - last_led_toggle >= short_duration_on_ms){
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW);
      digitalWrite(led4_pin, LOW);
      led_on = false;
      last_led_toggle = millis();
      ++blink_num;
      if(blink_num == 3){
        long_blink = true;
        blink_num = 0;
      }
    }
  }else{
    if(millis() - last_led_toggle >= duration_off_ms){
      digitalWrite(led1_pin, HIGH);
      digitalWrite(led2_pin, HIGH);
      digitalWrite(led3_pin, HIGH);
      digitalWrite(led4_pin, HIGH);
      led_on = true;
      last_led_toggle = millis();
    }
  }
}
