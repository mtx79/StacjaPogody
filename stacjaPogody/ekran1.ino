void ekran1()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wilg. (%): ");              //wyświetlenie wartości wilgotności
  lcd.print((float)wilgotnosc, 1);
  lcd.setCursor(0,1);
  lcd.print("Temp. (C): ");           //wyświetlenie temperatury
  lcd.print((float)temperatura, 1);
}
