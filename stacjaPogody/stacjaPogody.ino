#include<LiquidCrystal.h>
#include<dht11.h>
//#include<SPI.h>
#include<SD.h>
#include<time.h>

#define DHT11PIN 2
#define BUTTON 3
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
typedef struct czas{
  int godzina;
  int minuta;
  int sekunda;
  void pobierz_czas(){
    unsigned long temp = millis();
    godzina = (temp/100/60/60);
    minuta = (temp/1000/60) - (godzina*60);
    sekunda = (temp/1000)-(minuta*60);
  }
}czas;
czas _czas[ilosc_zapisow];


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
  //attachInterrupt(1, ekran2, RISING);

}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
  pobierz_dane_z_czujnika();
  stanZapisu=zapisz(czestotliwosc_zapisu);
  Serial.print("StanZapisu = ");
  Serial.println(stanZapisu);
	ekran1();
  if(sprawdz_przycisk(1))
    ekran2();
}





