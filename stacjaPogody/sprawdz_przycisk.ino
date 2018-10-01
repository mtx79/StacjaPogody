void sprawdz_przycisk(){
  unsigned long start=0;
  unsigned long koniec=0;	
  unsigned long czas=0;

		if (digitalRead(BUTTON) == HIGH){
      delay(30);
      start = millis();
      while(digitalRead(BUTTON) == HIGH && (czas < 3000)){    //mierze jak długo przycisk jest wcisniety
        koniec = millis();
        czas=koniec-start;
      }	
      Serial.println(start);  
      Serial.println(koniec);
      Serial.println(czas);
      if(czas < 3000){
        ekran2();
        while(digitalRead(BUTTON) == HIGH);
      }
      else
        ustawZegar();
		}
   if (analogRead(BUTTON_UP) > 1000){
    delay(30);
    ustawCzasZapisu();
    while(digitalRead(BUTTON) == HIGH);
   }
}
