// C++ code
//
const char BUTTON_12_PIN = 12;
const char BUTTON_11_PIN = 11;

const char BUTTON_10_PIN = 10;
const char BUTTON_9_PIN = 9;

const char BUTTON_8_PIN = 8;
const char BUTTON_7_PIN = 7;

const char BUTTON_6_PIN = 6;
const char BUTTON_5_PIN = 5;

const char BUTTON_4_PIN = 4;
const char BUTTON_3_PIN = 3;

const char BUTTON_2_PIN = 2;
const char BUTTON_1_PIN = 13;

const char BUTTON_0_PIN = 0;
bool pressed = false;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_12_PIN, INPUT_PULLUP);
  pinMode(BUTTON_11_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_10_PIN, INPUT_PULLUP);
  pinMode(BUTTON_9_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_8_PIN, INPUT_PULLUP);
  pinMode(BUTTON_7_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_6_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  
  pinMode(BUTTON_0_PIN, INPUT_PULLUP);
}

void loop()
{
  bool button_12_State = digitalRead(BUTTON_12_PIN);
  bool button_11_State = digitalRead(BUTTON_11_PIN);
  bool button_10_State = digitalRead(BUTTON_10_PIN);
  bool button_9_State = digitalRead(BUTTON_9_PIN);
  bool button_8_State = digitalRead(BUTTON_8_PIN);
  bool button_7_State = digitalRead(BUTTON_7_PIN);
  bool button_6_State = digitalRead(BUTTON_6_PIN);
  bool button_5_State = digitalRead(BUTTON_5_PIN);
  bool button_4_State = digitalRead(BUTTON_4_PIN);
  bool button_3_State = digitalRead(BUTTON_3_PIN);
  bool button_2_State = digitalRead(BUTTON_2_PIN);
  bool button_1_State = digitalRead(BUTTON_1_PIN);
  bool button_0_State = digitalRead(BUTTON_0_PIN);
  
  if(button_12_State == pressed ){
    Serial.println("12");
    while(digitalRead(BUTTON_12_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_11_State == pressed ){
    Serial.println("11");
    while(digitalRead(BUTTON_11_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_10_State == pressed ){
    Serial.println("10");
    while(digitalRead(BUTTON_10_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_9_State == pressed ){
    Serial.println("9");
    while(digitalRead(BUTTON_9_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_8_State == pressed ){
    Serial.println("8");
    while(digitalRead(BUTTON_8_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_7_State == pressed ){
    Serial.println("7");
    while(digitalRead(BUTTON_7_PIN) == pressed){
      //do nothing while the button is pressed
    } 
  } else if(button_6_State == pressed ){
    Serial.println("6");
    while(digitalRead(BUTTON_6_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_5_State == pressed ){
    Serial.println("5");
    while(digitalRead(BUTTON_5_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_4_State == pressed ){
    Serial.println("4");
    while(digitalRead(BUTTON_4_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_3_State == pressed ){
    Serial.println("3");
    while(digitalRead(BUTTON_3_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_2_State == pressed ){
    Serial.println("2");
    while(digitalRead(BUTTON_2_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_1_State == pressed ){
    Serial.println("1");
    while(digitalRead(BUTTON_1_PIN) == pressed){
      //do nothing while the button is pressed
    }
  } else if(button_0_State == pressed ){
    Serial.println("0");
    while(digitalRead(BUTTON_0_PIN) == pressed){
      //do nothing while the button is pressed
    }
  }
  
  	
}