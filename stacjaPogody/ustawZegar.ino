void ustawZegar(){
  int tab[12];
  int a = 0;
  int j = 0;
  DateTime now = rtc.now();
  
  int rok = now.year();
  int miesiac = now.month();
  int dzien = now.day();
  int godzina = now.hour();
  int minuta = now.minute();

  tab[0] = rok/1000;
  tab[1] = (rok-(tab[0]*1000))/100;
  tab[2] = (rok - (tab[0]*1000) - (tab[1]*100))/10;
  tab[3] = (rok - (tab[0]*1000) - (tab[1]*100) - (tab[2]*10));
  tab[4] = miesiac/10;
  tab[5] = miesiac - (tab[4]*10);
  tab[6] = dzien/10;
  tab[7] = dzien - (tab[6]*10);
  tab[8] = godzina/10;
  tab[9] = godzina - (tab[8]*10);
  tab[10] = minuta/10;
  tab[11] = minuta - (tab[10]*10);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(tab[0]);
  lcd.print(tab[1]);
  lcd.print(tab[2]);
  lcd.print(tab[3]);
  lcd.print("/");
  lcd.print(tab[4]);
  lcd.print(tab[5]);
  lcd.print("/");
  lcd.print(tab[6]);
  lcd.print(tab[7]);
  lcd.print("   ");
  lcd.print(tab[8]);
  lcd.print(tab[9]);
  lcd.print(":");
  lcd.print(tab[10]);
  lcd.print(tab[11]);
  lcd.setCursor(j, 1);
  lcd.print("-");
    
  
  while(digitalRead(BUTTON) == HIGH);     //pusta pętla dopuki nie zwolnie przycisku.
  
  while(a<12){
    if (digitalRead(BUTTON) == HIGH){
      delay(30);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(tab[0]);
      lcd.print(tab[1]);
      lcd.print(tab[2]);
      lcd.print(tab[3]);
      lcd.print("/");
      lcd.print(tab[4]);
      lcd.print(tab[5]);
      lcd.print("/");
      lcd.print(tab[6]);
      lcd.print(tab[7]);
      lcd.print("   ");
      lcd.print(tab[8]);
      lcd.print(tab[9]);
      lcd.print(":");
      lcd.print(tab[10]);
      lcd.print(tab[11]);
      ++a;
      if(a==8)
        j=j+4;
      else if(a==4 || a==6 || a==10)
        j=j+2;
      else
        ++j;
      lcd.setCursor(j, 1);
      lcd.print("-");
      while(digitalRead(BUTTON) == HIGH);
      delay(30);
    }

    if (analogRead(BUTTON_UP) > 1000 && tab[a]<9){
      delay(30);
      ++tab[a];
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(tab[0]);
      lcd.print(tab[1]);
      lcd.print(tab[2]);
      lcd.print(tab[3]);
      lcd.print("/");
      lcd.print(tab[4]);
      lcd.print(tab[5]);
      lcd.print("/");
      lcd.print(tab[6]);
      lcd.print(tab[7]);
      lcd.print("   ");
      lcd.print(tab[8]);
      lcd.print(tab[9]);
      lcd.print(":");
      lcd.print(tab[10]);
      lcd.print(tab[11]);
      lcd.setCursor(j, 1);
      lcd.print("-");
      while(analogRead(BUTTON_UP) > 1000);
      delay(30);
    }

    if (analogRead(BUTTON_DOWN) > 1000 && tab[a]>0){
      delay(30);
      --tab[a];
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(tab[0]);
      lcd.print(tab[1]);
      lcd.print(tab[2]);
      lcd.print(tab[3]);
      lcd.print("/");
      lcd.print(tab[4]);
      lcd.print(tab[5]);
      lcd.print("/");
      lcd.print(tab[6]);
      lcd.print(tab[7]);
      lcd.print("   ");
      lcd.print(tab[8]);
      lcd.print(tab[9]);
      lcd.print(":");
      lcd.print(tab[10]);
      lcd.print(tab[11]);
      lcd.setCursor(j, 1);
      lcd.print("-");
      while(analogRead(BUTTON_DOWN) > 1000);
      delay(30);
    }
  }

  

  rok = (tab[0]*1000) + (tab[1]*100) + (tab[2]*10) + tab[3];
  miesiac = (tab[4]*10) + tab[5];
  dzien = (tab[6]*10) + tab[7];
  godzina = (tab[8]*10) + tab[9];
  minuta = (tab[10]*10) + tab[11];
  
  rtc.adjust(DateTime(rok, miesiac, dzien, godzina, minuta, 0));
}

