void pobierz_dane_z_czujnika(const long interval){

  unsigned long currentMillis = millis();
  unsigned long czas = currentMillis-startMillisCzujnik;
  if(czas >= interval){
    startMillisCzujnik = currentMillis;
    int chk = DHT11.read(DHT11PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym

    switch (chk){
      case DHTLIB_OK: 
      temperatura=DHT11.temperature;
      wilgotnosc=DHT11.humidity;
      break;
      case DHTLIB_ERROR_CHECKSUM:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.println("ERROR CHECKSUM");
      lcd.setCursor(0, 1);
      lcd.println("Blad czujnika");
      delay(5000);  
      break;
      case DHTLIB_ERROR_TIMEOUT:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.println("ERROR TIMEOUT");
      lcd.setCursor(0, 1);
      lcd.println("Blad czujnika");
      delay(5000);
      break;
      default: 
      lcd.clear();
      lcd.println("Blad czujnika"); 
      delay(5000);
      break;
    }
  }
}
