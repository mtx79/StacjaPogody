bool sprawdz_przycisk(int a){	
	for(int i=0; i<=(a*200); ++i){
    delay(5);
		if (digitalRead(BUTTON) == HIGH){return true;}
	}
 return false;
}
