
void ekran2()
{
  int a=0;
  lcd.clear();
  for(int i = 0; i<4; ++i){
    lcd.setCursor(0, i);
    lcd.print("p");
    lcd.print(i+a);
    lcd.print("  1T: ");
    lcd.print(tempArray[i+a]);
    lcd.print("   W: ");
    lcd.print(humArray[i+a]);
  }

  while(digitalRead(BUTTON) == HIGH);
  delay(20);
  
  do{
    if (analogRead(BUTTON_UP) > 10 && a<27){
      delay(20);
      ++a;
      lcd.clear();
      for(int i = 0; i<4; ++i){
        lcd.setCursor(0, i);
        lcd.print("p");
        lcd.print(i+a);
        lcd.print("  2T: ");
        lcd.print(tempArray[i+a]);
        lcd.print("   W: ");
        lcd.print(humArray[i+a]);
      }
      while(analogRead(BUTTON_UP) > 10);
      delay(20);
    }


    if (analogRead(BUTTON_DOWN) > 10 && a>0){
      delay(20);
      --a;
      lcd.clear();
      for(int i = 0; i<4; ++i){
        lcd.setCursor(0, i);
        lcd.print("p");
        lcd.print(i+a);
        lcd.print("  3T: ");
        lcd.print(tempArray[i+a]);
        lcd.print("   W: ");
        lcd.print(humArray[i+a]);
      }
      while(analogRead(BUTTON_DOWN) > 10);
      delay(20);
    }
  }while(digitalRead(BUTTON) != HIGH);
  delay(20);
}
