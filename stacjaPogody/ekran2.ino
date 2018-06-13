
void ekran2()
{
  int a=0;
	lcd.clear();
  for(int i = 0; i<4; ++i){
    lcd.setCursor(0, i);
    lcd.print("p");
    lcd.print(i+a);
    lcd.print("   T: ");
    lcd.print(tempArray[i+a]);
    lcd.print("   W: ");
    lcd.print(humArray[i+a]);
  }

  delay(5000);
}
