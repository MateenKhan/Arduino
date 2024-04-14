int buttonValue =0;
int Button = A0;
int LED = A1;



void setup()
{
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  buttonValue = digitalRead(Button);
  if(buttonValue!=0){
  	digitalWrite(LED,HIGH);
  } else{
  	digitalWrite(LED,LOW);
  }
  
}