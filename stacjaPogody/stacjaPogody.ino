#include<LiquidCrystal.h>
#include<dht11.h>
#include<SD.h>
dht11 DHT11;
#define DHT11PIN 2
#define BUTTON 3
#define KARTA 10

LiquidCrystal lcd(4,5,6,7,8,9);

float temperatura, wilgotnosc;
int zapisWar=0;
int test = 0;
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  Serial.print("inicjalizacja karty SD...");
  pinMode(KARTA, OUTPUT);
  if(!SD.begin(8))
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
  //lcd.print(test);
  //test++;
}

void ekran2()
{
	lcd.clear();
  lcd.setCursor(0, 0);
  for(int i=0; i<=9; i++)
  {
    lcd.print(i);
    delay(1000);
  }
}

void zapisz()
{
	File dataFile = SD.open("DATA.TXT", FILE_WRITE);
  if (dataFile){
    dataFile.print("\nwilgotnosc: ");
    dataFile.print((float)DHT11.humidity, 2);
    dataFile.print("\ntemperatura: ");
    dataFile.print((float)DHT11.temperature, 2);
    dataFile.close();
  }
  else{
    Serial.println("Niedudalo sie otworzyc pliku DATA.TXT");
    lcd.print("Zapis nieudany!");
  }
}

void loop()	//oddzielenie przyciskow od obslugi wyswietlacza
{
	ekran1();
	if(zapisWar==1)
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





