void ekran1()
{
  lcd.clear();
  lcd.setCursor(5, 0);
  _czas[0].pobierz_czas();
  lcd.print(_czas[0].godzina);
  lcd.print("-");
  lcd.print(_czas[0].minuta);
  lcd.print("-");
  lcd.print(_czas[0].sekunda);

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
