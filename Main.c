#include "main.h"

int main(){
	
	init();
	
	while(1){
	
		char input = Keypad_PressedKey();

		switch(input){
		
			case 'A':
				A();
				break;
			
			case 'B':
				B();
				break;
			
			case 'C':
				C();
				break;
			
			case 'D':
				D();
				break;
			
		}
		
	}

}