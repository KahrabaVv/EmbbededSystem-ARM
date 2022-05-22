#include "buttonB.h"


void B(){
				
		unsigned char int_digit;
		unsigned char digit;
		unsigned int time;
		unsigned char minutes;
		unsigned char seconds;
				
loop:		clear_display();
				LCD_string_display ("BEEF WEIGHT?");
				while ((int)Keypad_PressedKey()!=0);
				while (Keypad_PressedKey()==0){
					if(SW1_input()!=0){
						clear_display();
						return;
					}
				}
			
				
		
				 // wait till keypad is pressed , if not pressed this function returns 0
				
				digit=Keypad_PressedKey();
				
				
		


}