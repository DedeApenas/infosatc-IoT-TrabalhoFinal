int sinal = A3;
float distancia;
int Temp;
int valorAT, valorAD;

#include <LiquidCrystal.h> 
#define TempSensor A2
#define som A0
#define luz1 7
#define luz2 8
#define luz3 9
#define luz4 10
#define LDR A1
#define gas A4

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{     
 Serial.begin(9600);
  //LCD
 lcd.begin(16, 2); 
  ////Sensor de distancia
 pinMode(sinal,OUTPUT); 
 digitalWrite(sinal,LOW); 
  //Led
 pinMode(luz1,OUTPUT);
 digitalWrite(luz1,LOW);
 pinMode(luz2,OUTPUT);
 digitalWrite(luz2,LOW);
 pinMode(luz3,OUTPUT);
 digitalWrite(luz3,LOW);
 pinMode(luz4,OUTPUT);
 digitalWrite(luz4,LOW);
  //Piezo 
 pinMode(som,OUTPUT);
 digitalWrite(som,LOW);
 
  
}
void loop()
{  
 {
  //Sensor de gás
  int vlg = analogRead(gas);
  vlg = map(vlg,300,750,0,100);
  //Sensor de temperatura
  float sinalTemp = analogRead(TempSensor)*5;
  float tempC = ((sinalTemp/1023)-0.5)*100;
  //Fotorresistor
  valorAT = analogRead(LDR);
  //Sensor de distancia
  leitura();
  distancia=distancia/2;
  distancia=distancia*0.034029;  
  delay(100); 
 
  //Funcionamento do alarme
  
  //Monitora distancia
  if (distancia <= 150) 
  {
    digitalWrite(luz1,HIGH);
    digitalWrite(luz2,HIGH);
    digitalWrite(luz3,HIGH);
    digitalWrite(luz4,HIGH);
    digitalWrite(som,HIGH); 
    lcd.setCursor(3, 0);
    lcd.print("PERIGO!!!!");
    lcd.setCursor(2, 1);
    lcd.print(" PERIGO!!!!");
    delay(10);
  }
  //Monitora fotorresistor
  else if     
     (valorAT <= 400) 
  {
    digitalWrite(luz1,HIGH);
    digitalWrite(luz2,HIGH);
    digitalWrite(luz3,HIGH);
    digitalWrite(luz4,HIGH);
    digitalWrite(som,HIGH);
    lcd.setCursor(3, 0);
    lcd.print("PERIGO!!!!");
    lcd.setCursor(2, 1);
    lcd.print(" PERIGO!!!!");
    delay(10);  
  }
 //Monitora Temperatura
  else if (tempC >= 40) 
  {
    digitalWrite(luz1,HIGH);
    digitalWrite(luz2,HIGH);
    digitalWrite(luz3,HIGH);
    digitalWrite(luz4,HIGH);
    digitalWrite(som,HIGH);
    lcd.setCursor(3, 0);
    lcd.print("PERIGO!!!!");
    lcd.setCursor(2, 1);
    lcd.print(" PERIGO!!!!");
    delay(10);  
  }
   else if (vlg >= 50) 
  {
    digitalWrite(luz1,HIGH);
    digitalWrite(luz2,HIGH);
    digitalWrite(luz3,HIGH);
    digitalWrite(luz4,HIGH);
    digitalWrite(som,HIGH);
    lcd.setCursor(3, 0);
    lcd.print("PERIGO!!!!");
    lcd.setCursor(2, 1);
    lcd.print(" PERIGO!!!!");
    delay(10);  
  }
  else
  {
    digitalWrite(som,LOW);
    digitalWrite(luz1,LOW);
    digitalWrite(luz2,LOW);
    digitalWrite(luz3,LOW);
    digitalWrite(luz4,LOW); 
    lcd.clear();
  }
}
delay(50);
}
void leitura()
{
  //Leitura do sensor de distancia
 pinMode(sinal,OUTPUT);
 digitalWrite(sinal,HIGH);
 delayMicroseconds(5);
  digitalWrite(sinal,LOW);
  pinMode(sinal,INPUT);
  distancia=pulseIn(sinal,HIGH);
}

  