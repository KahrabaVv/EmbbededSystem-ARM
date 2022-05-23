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
				
				if ((digit<=57 && digit>=49)){// if the digit is between 1 to 9 and these are the ascii exchange values
				
					int_digit=digit -48 ;// making the digit back from 1 to 9 as an integer to be used later 
					clear_display();
					LCD_char_display(digit);
					SysTick_wait_10ms(2*100);
					clear_display();
					

					time=(int)int_digit; //create time variable holding how many minutes and seconds ex:4.5
					
					
					
					}
				
		


}