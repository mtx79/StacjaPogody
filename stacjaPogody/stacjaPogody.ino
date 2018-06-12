#include<LiquidCrystal.h>
#include<dht11.h>
#include<SD.h>
dht11 DHT11;
#define DHT11PIN 2
#define BUTTON 3
#define KARTA 10
#define status_karty 8

LiquidCrystal lcd(4,5,6,7,8,9);

float temperatura, wilgotnosc;
int zapisWar=0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  Serial.print("inicjalizacja karty SD...");
  pinMode(KARTA, OUTPUT);
  if(!SD.begin(status_karty))
  {
    Serial.println("Brak lub nieprawidlowe dzialanie karty");
    lcd.print("Brak karty");
    delay(5000);
    return;
  }
  Serial.println("Karta SD gotowa do uzycia.");
  lcd.print("Karta SD - OK");
  delay(5000);

  
	pinMode(BUTTON, INPUT);

}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
  pobierz_dane_z_czujnika();
	ekran1();
	if(zapisWar==12)
	{
    zapisWar=0;
		zapisz();
	}
	zapisWar++;
	for(int i=0; i<1000; ++i)
	{
    delay(5);
		if (digitalRead(BUTTON) == HIGH)
		{
			ekran2();							//dostep do historii
      break;
		}
	}
}





