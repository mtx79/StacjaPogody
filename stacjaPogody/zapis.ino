bool zapisz(int a){
  if(stanZapisu==false){
   if(!SD.begin(SS))
    return false;
  }
  else
    stanZapisu=true;
    
  ++zapisWar;
  if(zapisWar==a){
  	File dataFile = SD.open("DATA.TXT", FILE_WRITE);
    if (dataFile){
      Serial.print("Zapis przed close: datafile = ");
      Serial.println(dataFile);
      dataFile.print("\nwilgotnosc: ");
      dataFile.print((float)wilgotnosc, 2);
      dataFile.print("\ntemperatura: ");
      dataFile.print((float)temperatura, 2);
      dataFile.close();
      Serial.print("Zapis po close: datafile = ");
      Serial.println(dataFile);

      for(int i=29; i>0; --i){               //
        tempArray[i] = tempArray[i-1];
        humArray[i] = humArray[i-1];
      }
      tempArray[0] = temperatura;
      humArray[0] = wilgotnosc;
      zapisWar=0;
      return true;
    }
    else
      return false;
  }
  else
    return stanZapisu;
}
