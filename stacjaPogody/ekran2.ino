void ekran2()
{
  int a=1;
  char dateArray[63];
  lcd.clear();
  dataFile = SD.open("DATA.TXT");
  if (dataFile) {
    dataFile.seek((dataFile.size()-(63*a)));
    dataFile.read(dateArray,63);
    dataFile.close();

        lcd.setCursor(0, 0);
    for(int i = 1; i<21; ++i){
      lcd.print(dateArray[i]);
    }
    
    lcd.setCursor(0, 1);
    for(int i = 23; i<42; ++i){
      lcd.print(dateArray[i]);
    }

    lcd.setCursor(0, 2);
    for(int i = 44; i<63; ++i){
      lcd.print(dateArray[i]);
    }
  } 
  else {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Problem z odczytem z karty");
  }




  while(digitalRead(BUTTON) == HIGH);
  delay(20);
  
  do{
    if (analogRead(BUTTON_UP) > 1000){
      delay(30);
      ++a;
      lcd.clear();
      dataFile = SD.open("DATA.TXT");
      if (dataFile) {
        dataFile.seek((dataFile.size()-(63*a)));
        dataFile.read(dateArray,63);
        dataFile.close();

        lcd.setCursor(0, 0);
        for(int i = 1; i<21; ++i){
          lcd.print(dateArray[i]);
        }
    
        lcd.setCursor(0, 1);
        for(int i = 23; i<42; ++i){
          lcd.print(dateArray[i]);
        }

        lcd.setCursor(0, 2);
        for(int i = 44; i<63; ++i){
          lcd.print(dateArray[i]);
        }
      } 
      else {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Problem z odczytem z karty");
      }
    }          
    while(analogRead(BUTTON_UP) > 1000);
    delay(30);


    if (analogRead(BUTTON_DOWN) > 1000 && a>1){
      delay(30);
      --a;
      lcd.clear();
      dataFile = SD.open("DATA.TXT");
      if (dataFile) {
        dataFile.seek((dataFile.size()-(63*a)));
        dataFile.read(dateArray,63);
        dataFile.close();

        lcd.setCursor(0, 0);
        for(int i = 1; i<21; ++i){
          lcd.print(dateArray[i]);
        }
    
        lcd.setCursor(0, 1);
        for(int i = 23; i<42; ++i){
          lcd.print(dateArray[i]);
        }

        lcd.setCursor(0, 2);
        for(int i = 44; i<63; ++i){
          lcd.print(dateArray[i]);
        }
      } 
      else {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Problem z odczytem z karty");
      }
    }

      while(analogRead(BUTTON_DOWN) > 1000);
      delay(30);
  
  }while(digitalRead(BUTTON) != HIGH);
  delay(30);
}
