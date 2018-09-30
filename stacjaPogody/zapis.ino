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
      if(now.month()<10){
        dataFile.print(0);
        dataFile.print(now.month(), DEC);
      }
      else
        dataFile.print(now.month(), DEC);
        
        dataFile.print('/');
      if(now.day()<10){
        dataFile.print(0);
        dataFile.print(now.day(), DEC);
      }
      else
        dataFile.print(now.day(), DEC);
        
        dataFile.print("  ");
      if(now.hour()<10){
        dataFile.print(0);
        dataFile.print(now.hour(), DEC);
      }
      else
        dataFile.print(now.hour(), DEC);
        dataFile.print(':');
      if(now.minute()<10){
        dataFile.print(0);
        dataFile.print(now.minute(), DEC);
      }
      else
        dataFile.print(now.minute(), DEC);
        dataFile.print(':');
      if(now.second()<10){
        dataFile.print(0);
        dataFile.print(now.second(), DEC);
      }
      else
        dataFile.print(now.second(), DEC);


      dataFile.print("   ");  
      dataFile.print("wilgotnosc:  ");
      dataFile.print((float)wilgotnosc, 2);
      dataFile.print("   ");
      dataFile.print("temperatura: ");
      dataFile.print((float)temperatura, 2);
      dataFile.close();


      return true;
   }
    else
      return false;
  }
  else
    return stanZapisu;
}
