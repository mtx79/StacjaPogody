void ekran1()
{
  lcd.clear();
  lcd.setCursor(12, 0);

    DateTime now = rtc.now();
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
