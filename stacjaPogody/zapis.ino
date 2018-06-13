void zapisz(int a)
{
  if(zapisWar==a){
  	File dataFile = SD.open("DATA.TXT", FILE_WRITE);
    if (dataFile){
      dataFile.print("\nwilgotnosc: ");
      dataFile.print((float)wilgotnosc, 2);
      dataFile.print("\ntemperatura: ");
      dataFile.print((float)temperatura, 2);
      dataFile.close();
      lcd.setCursor(18,4);
      lcd.print("OK");

      for(int i=29; i>0; --i){               //
        tempArray[i] = tempArray[i-1];
        humArray[i] = humArray[i-1];
      }
      tempArray[0] = temperatura;
      humArray[0] = wilgotnosc;
    }
    else{
      lcd.setCursor(5, 4);
      lcd.print("Zapis nieudany!");
    }
    zapisWar=0;
  }
  ++zapisWar;
}
