void ekran2()
{
	lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("To dziala!");
  lcd.setCursor(0, 1);
  for(int i=0; i<=9; i++)
  {
    lcd.print(i);
    delay(1000);
  }
}
