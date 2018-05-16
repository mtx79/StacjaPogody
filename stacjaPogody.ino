#include<LiquidCrystal.h>
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 2

LiquidCrystal lcd(4,5,6,7,8,9);

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  }

void loop()
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

  delay(1000); 

}

