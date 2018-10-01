void ustawCzasZapisu(){
    int a=0;
    int j=0;
    int tab[4];
    tab[0] = intervalZapisu/36000000;
    tab[1] = (intervalZapisu - tab[0]*36000000)/3600000;
    tab[2] = (intervalZapisu - tab[0]*36000000 - tab[1]*3600000)/600000;
    tab[3] = (intervalZapisu - tab[0]*36000000 - tab[1]*3600000 - tab[2]*600000)/60000;



    
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Czestotliwosc ");
  lcd.setCursor(0, 1);
  lcd.print("zapisu: ");
  lcd.setCursor(0, 2);
  lcd.print(tab[0]);
  lcd.print(tab[1]);
  lcd.print("h,   ");
  lcd.print(tab[2]);
  lcd.print(tab[3]);
  lcd.print("min");
       lcd.setCursor(j, 3);
      lcd.print("-");



  while(analogRead(BUTTON_UP) > 1000);
  delay(30);
  
   while(a<4){
    if (digitalRead(BUTTON) == HIGH){
      delay(30);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Czestotliwosc ");
  lcd.setCursor(0, 1);
  lcd.print("zapisu: ");
  lcd.setCursor(0, 2);
  lcd.print(tab[0]);
  lcd.print(tab[1]);
  lcd.print("h,   ");
  lcd.print(tab[2]);
  lcd.print(tab[3]);
  lcd.print("min");
      ++a;
      if(a==2)
        j=j+6;
      else
        ++j;
      lcd.setCursor(j, 3);
      lcd.print("-");
      while(digitalRead(BUTTON) == HIGH);
      delay(30);
    }

    if (analogRead(BUTTON_UP) > 1000 && tab[a]<9){
      delay(30);
      ++tab[a];
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Czestotliwosc ");
  lcd.setCursor(0, 1);
  lcd.print("zapisu: ");
  lcd.setCursor(0, 2);
  lcd.print(tab[0]);
  lcd.print(tab[1]);
  lcd.print("h,   ");
  lcd.print(tab[2]);
  lcd.print(tab[3]);
  lcd.print("min");
      lcd.setCursor(j, 3);
      lcd.print("-");
      while(analogRead(BUTTON_UP) > 1000);
      delay(30);
    }

    if (analogRead(BUTTON_DOWN) > 1000 && tab[a]>0){
      delay(30);
      --tab[a];
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Czestotliwosc ");
  lcd.setCursor(0, 1);
  lcd.print("zapisu: ");
  lcd.setCursor(0, 2);
  lcd.print(tab[0]);
  lcd.print(tab[1]);
  lcd.print("h,   ");
  lcd.print(tab[2]);
  lcd.print(tab[3]);
  lcd.print("min");
      lcd.setCursor(j, 3);
      lcd.print("-");
      while(analogRead(BUTTON_DOWN) > 1000);
      delay(30);
    }
  }
  intervalZapisu = tab[0]*36000000 + tab[1]*3600000 + tab[2]*600000 + tab[3]*60000;
  if (intervalZapisu == 0){
    intervalZapisu = 60000;
  }

}  

