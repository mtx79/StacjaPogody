#include<LiquidCrystal.h>
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2
#define BUTTON 3

LiquidCrystal lcd(4,5,6,7,8,9);

float temperatura, wilgotnosc;
int zapisWar=0;

void setup()
{
	pinMode(BUTTON, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void ekran1()
{
  lcd.clear();
  int chk = DHT11.read(DHT11PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym

 /* lcd.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK: 
    lcd.print("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    lcd.println("Błąd sumy kontrolnej"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    lcd.println("Koniec czasu oczekiwania - brak odpowiedzi"); 
    break;
    default: 
    lcd.println("Nieznany błąd"); 
    break;
  }*/
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wilg. (%): ");              //wyświetlenie wartości wilgotności
  lcd.print((float)DHT11.humidity, 1);
  lcd.setCursor(0,1);
  lcd.print("Temp. (C): ");           //wyświetlenie temperatury
  lcd.print((float)DHT11.temperature, 1);
}

void ekran2()
{
	
}

void zapisz()
{
	
}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
	ekran1();
	if(zapisWar=200)
	{
		zapisz();
	}
	zapisWar++;
	for(int i=0; i<10000; ++i)
	{
		if (digitalRead(BUTTON) == HIGH)
		{
			ekran2();							//dostep do historii
		}
	}
}




