#include<LiquidCrystal.h>
#include<dht11.h>
#include<SD.h>

#define DHT11PIN 2
#define BUTTON 3
#define KARTA 10
#define status_karty 8
#define czestotliwosc_zapisu 1

LiquidCrystal lcd(4,5,6,7,8,9);
dht11 DHT11;
float temperatura, wilgotnosc;
int zapisWar=1;
int tempArray[30];
int humArray[30];

void setup()
{
  lcd.begin(20, 4);
  lcd.clear();
  pinMode(KARTA, OUTPUT);
  if(!SD.begin(status_karty)){
    lcd.print("Brak karty");
    delay(5000);
  }
  else{
    lcd.print("Karta OK");
    delay(5000);
  }
	pinMode(BUTTON, INPUT);
  //attachInterrupt(1, ekran2, RISING);

}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
  pobierz_dane_z_czujnika();
	ekran1();
	zapisz(czestotliwosc_zapisu);
  sprawdz_przycisk();
}





