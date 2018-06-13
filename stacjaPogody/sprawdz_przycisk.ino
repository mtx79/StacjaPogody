void sprawdz_przycisk(){	
	for(int i=0; i<1000; ++i){
    delay(5);
		if (digitalRead(BUTTON) == HIGH){
			ekran2();							//dostep do historii
      break;
		}
	}
}
