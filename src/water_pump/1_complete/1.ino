#include <Keypad.h>

#include <LiquidCrystal_I2C.h>  //i2C LCD Library
LiquidCrystal_I2C lcd(0x27, 20, 4); //library i2c lcd


int relay = 13;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;
long kartu3;
int id;
long beli;
long beli1;
char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {10,9,8,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,5,4,3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 


byte sensorInterrupt = 0;  // 0 = digital pin 2
byte sensorPin       = 2;

float calibrationFactor = 4.5; /// SETTING SESUAI KEPRESISIAN SENSOR SAYA PAKE 9.6

volatile byte pulseCount;  

unsigned int frac;
float flowRate;
unsigned int flowMilliLitres;
int totalMilliLitres;

unsigned long oldTime;

void setup() 
{
  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
  oldTime           = 0;

  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  
  lcd.init(); //set lcd i2c
  lcd.noCursor(); //biar gak ada cursor di lcd
  lcd.clear(); //clear lcd
  Serial.begin(9600);   // Initiate a serial communication
//  Serial.println("Put your card to the reader...");
//  Serial.println();

  delay(1000);

}


void loop() 
{

  lcd.setCursor(0,0); 
  lcd.print("     POM MINI   ");
  lcd.setCursor(0,1); 
  lcd.print("-> A : setting awal");
  lcd.setCursor(0,2);
  lcd.print("-> B : setting tetap");
  
customKey = customKeypad.getKey();

    if(customKey == 'A'){
    pulseCount        = 0;
    flowRate          = 0.0;
    flowMilliLitres   = 0;
    totalMilliLitres  = 0;
    oldTime           = 0;
  
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Loading...");
    delay(3000);
    lcd.clear(); 

    lcd.clear();
    beli = 0;
    beli1 = 0;
    bayar();
    digitalWrite(relay, LOW);
    mulaiisi();
    }

     if(customKey == 'B'){
     pulseCount        = 0;
     flowRate          = 0.0;
     flowMilliLitres   = 0;
     totalMilliLitres  = 0;
     oldTime           = 0;
     lcd.clear();
     digitalWrite(relay, LOW);
     mulaiisi();
     } 
}


void bayar(){

  lcd.setCursor(0,0); 
  lcd.print("Setting Value");
  lcd.setCursor(0,3);
  lcd.print("lalu tekan 'D' ");
  
customKey = customKeypad.getKey();

    if(customKey >= '0' && customKey <= '9')
    {
      beli = beli * 10 + (customKey - '0');
      lcd.setCursor(0,1);
      lcd.print(beli);
      
    
      beli1 = beli * 1000 ;
      lcd.setCursor(0,2);
      lcd.print(beli1);
      
    }
   
    if(customKey == 'C'){
    lcd.clear();
    delay(200); 
    beli = 0;
    }
 
if(customKey == 'D'){
    lcd.clear();
    delay(2000); 
    kartu3 = kartu3 - beli;

kartu3 = 100000;       /////////////////////////jika hasil terlalu banyak bisa setting disini
    
      if(kartu3 >= 0){
    Serial.println(beli1);
    delay(1000);
    lcd.setCursor(0,0); 
    lcd.print("BERHASIL");
    lcd.setCursor(0,1); 
    lcd.print("Maks Set=");
    lcd.print(kartu3);
    lcd.setCursor(0,3);
    lcd.print("tunggu");
    delay(5000);
    lcd.clear();
 return;
      }
      } 
    
  bayar();
   }

void mulaiisi(){

lcd.setCursor(0,0); 
lcd.print("Setting ");
lcd.print(beli1);
lcd.print(" mL   ");

delay(100);
  
if((millis() - oldTime) > 1000)    // Only process counters once per second
  { 

    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
       
    
    // Print the flow rate for this second in litres / minute
    //lcd.setCursor(0,3);
    //lcd.print("Flow rate: ");
    //lcd.print(int(flowRate));  // Print the integer part of the variable
    //lcd.print(".");             // Print the decimal point
    // Determine the fractional part. The 10 multiplier gives us 1 decimal place.
    frac = (flowRate - int(flowRate)) * 10;
    
    //lcd.print(frac, DEC) ;      // Print the fractional part of the variable
    //lcd.print("L/min             ");
    // Print the number of litres flowed in this second
    
    lcd.setCursor(0,1);
    lcd.print("Spd Flow: ");             // Output separator
    lcd.print(flowMilliLitres);
    lcd.print(" mL/Sec   ");

    // Print the cumulative total of litres flowed since starting
    lcd.setCursor(0,2); 
    lcd.print("ISI     : ");             // Output separator
    lcd.print(totalMilliLitres);
    lcd.print(" mL   ");
    

    lcd.setCursor(0,3); 
    lcd.print("Setting :  ");
    lcd.print(beli);
    lcd.print(" kg ");

    //lcd.setCursor(0,3); 
    //lcd.print("              "); 
    
    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);

  if(totalMilliLitres < beli1){
    delay(1000);
    digitalWrite(relay, HIGH);
  }
 
 if(totalMilliLitres >= beli1){
    
    digitalWrite(relay, LOW);
     
    delay(1000);
    
    return;
 }
  }

    
mulaiisi();

}
void pulseCounter()
{
  pulseCount++;
  
}
