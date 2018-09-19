void ekran1()
{
  lcd.clear();

    DateTime now = rtc.now();
    int rok = now.year();
    int miesiac = now.month();
    int dzien = now.day();
    int godzina = now.hour();
    int minuta = now.minute();
    int sekunda = now.second();

    lcd.setCursor(0, 0);
    lcd.print(rok, DEC);
    lcd.print('/');
    if(miesiac<10){
      lcd.print(0, DEC);
      lcd.print(miesiac, DEC);
    }
    else
      lcd.print(miesiac, DEC);
    lcd.print('/');
    if(dzien<10){
      lcd.print(0, DEC);
      lcd.print(dzien, DEC);
    }
    else
      lcd.print(dzien, DEC);

    lcd.setCursor(12, 0);
    if(godzina<10){
      lcd.print(0, DEC);
      lcd.print(godzina, DEC);
    }
    else
      lcd.print(godzina, DEC);
      
    lcd.print(':');
    if(minuta<10){
      lcd.print(0, DEC);
      lcd.print(minuta, DEC);
    }
    else
      lcd.print(minuta, DEC);
    lcd.print(':');
    
    if(sekunda<10){
      lcd.print(0, DEC);
      lcd.print(sekunda, DEC);
    }
    else
      lcd.print(sekunda, DEC);
      
/*
    lcd.setCursor(12, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);

    lcd.setCursor(0, 0);
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    
*/


  lcd.setCursor(0, 1);
  lcd.print("Wilg. (%): ");              //wyświetlenie wartości wilgotności
  lcd.print(wilgotnosc, 1);
  lcd.setCursor(0, 2);
  lcd.print("Temp. (C): ");           //wyświetlenie temperatury
  lcd.print(temperatura, 1);
  if(stanZapisu==true){
    lcd.setCursor(18, 3);
    lcd.print("OK");
  }
  else{
    lcd.setCursor(6, 3);
    lcd.print("Blad karty");
  }
}
