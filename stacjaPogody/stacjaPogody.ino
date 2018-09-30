#include<LiquidCrystal.h> //biblioteka wyswietlacza
#include<dht11.h>         //biblioteka do czujnika tamp i wilgotnosci
#include<SPI.h>           //biblioteka do obslugi magistrali SPI (podlaczona karta SD)
#include<SD.h>            //biblioteka do obslugi karty SD
//#include<Wire.h>          
#include "RTClib.h"       //biblioteka do obslugi zegara czasu rzeczywistego
#include <stdio.h>

RTC_DS1307 rtc;


#define DHT11PIN 2
#define BUTTON 3
#define BUTTON_UP 1
#define BUTTON_DOWN 2
#define SS 10
#define intervalZapisu 3600000
#define intervalCzujnik 5000
#define intervalEkran 1000




LiquidCrystal lcd(4,5,6,7,8,9);
dht11 DHT11;
float temperatura, wilgotnosc;
bool stanZapisu=true;
File dataFile;
unsigned long startMillisZapis = 0;
unsigned long startMillisCzujnik = 0;
unsigned long startMillisEkran = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.clear();
  pinMode(SS, OUTPUT);
  if(!SD.begin(SS))
    stanZapisu=false;
  else
    stanZapisu=true;
	pinMode(BUTTON, INPUT);
  rtc.begin();
  rtc.isrunning();
  //rtc.adjust(DateTime(2018, 9, 15, 10, 13, 0));
}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
  //Serial.println(analogRead(BUTTON_UP));
  //Serial.println(analogRead(BUTTON_DOWN));
  //Serial.println(" ");
  pobierz_dane_z_czujnika(intervalCzujnik);
  stanZapisu = zapisz(intervalZapisu);
	ekran1(intervalEkran);
  sprawdz_przycisk();
}





