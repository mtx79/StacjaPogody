#include<LiquidCrystal.h>
#include<dht11.h>
#include<SPI.h>
#include<SD.h>
#include<Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;


#define DHT11PIN 2
#define BUTTON 3
#define BUTTON_UP 1
#define BUTTON_DOWN 2
#define SS 10
#define czestotliwosc_zapisu 1
#define ilosc_zapisow 30

LiquidCrystal lcd(4,5,6,7,8,9);
dht11 DHT11;
float temperatura, wilgotnosc;
int zapisWar=0;
int tempArray[ilosc_zapisow];
int humArray[ilosc_zapisow];
bool stanZapisu=true;


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
  pobierz_dane_z_czujnika();
  stanZapisu=zapisz(czestotliwosc_zapisu);
	ekran1();
  sprawdz_przycisk(1);
}





