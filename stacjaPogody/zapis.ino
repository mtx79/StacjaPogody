void zapisz()
{
	File dataFile = SD.open("DATA.TXT", FILE_WRITE);
  if (dataFile){
    dataFile.print("\nwilgotnosc: ");
    dataFile.print((float)wilgotnosc, 2);
    dataFile.print("\ntemperatura: ");
    dataFile.print((float)temperatura, 2);
    dataFile.close();
  }
  else{
    Serial.println("Niedudalo sie otworzyc pliku DATA.TXT");
    lcd.print("Zapis nieudany!");
  }
}
