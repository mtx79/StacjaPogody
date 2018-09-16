
void ekran2()
{
  int a=0;
//  if (digitalRead(BUTTON_UP) == HIGH)
//    ++a;
//  if (digitalRead(BUTTON_DOWN) == HIGH && a>0) 
//    --a; 




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
    delay(500);

  do{    
//   lcd.clear();
//    for(int i = 0; i<4; ++i){
//      lcd.setCursor(0, i);
//      lcd.print("p");
//      lcd.print(i+a);
//      lcd.print("   T: ");
//      lcd.print(tempArray[i+a]);
//      lcd.print("   W: ");
//      lcd.print(humArray[i+a]);
//    }
//    delay(100);
  }while(digitalRead(BUTTON) != HIGH);
}
