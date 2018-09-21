bool zapisz(const long interval){

unsigned long currentMillis = millis();
unsigned long czas = currentMillis-startMillisZapis;
  if(czas >= interval){
    startMillisZapis = currentMillis;
    
  	dataFile = SD.open("DATA.TXT", FILE_WRITE);
    Serial.print("dataFile po probie otwarcia: ");
    Serial.println(dataFile);
    if (dataFile){
      DateTime now = rtc.now();
      dataFile.print("\n");
      dataFile.print(now.year(), DEC);
      dataFile.print('/');
      dataFile.print(now.month(), DEC);
      dataFile.print('/');
      dataFile.print(now.day(), DEC);
      dataFile.print("  ");
      dataFile.print(now.hour(), DEC);
      dataFile.print(':');
      dataFile.print(now.minute(), DEC);
      dataFile.print(':');
      dataFile.print(now.second(), DEC);

      dataFile.print("   ");  
      dataFile.print("wilgotnosc: ");
      dataFile.print((float)wilgotnosc, 2);
      dataFile.print("   ");
      dataFile.print("temperatura: ");
      dataFile.print((float)temperatura, 2);
      dataFile.close();

      for(int i=29; i>0; --i){               //
        tempArray[i] = tempArray[i-1];
        humArray[i] = humArray[i-1];
      }
      tempArray[0] = temperatura;
      humArray[0] = wilgotnosc;
      return true;
    }
    else
      return false;
  }
  else
    return stanZapisu;
}
