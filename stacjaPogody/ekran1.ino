void ekran1()
{
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Wilg. (%): ");              //wyświetlenie wartości wilgotności
  lcd.print(wilgotnosc, 1);
  lcd.setCursor(0, 2);
  lcd.print("Temp. (C): ");           //wyświetlenie temperatury
  lcd.print(temperatura, 1);
}
