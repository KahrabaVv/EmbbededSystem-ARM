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
					
					
					
					if(time%2==0){
						minutes=time/2; //taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=0; //returning 30/0 seconds ex: (int)(30*(5-4))= 30
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
						char k ;
						for (k=0;k<3;k++){
							RGB_output(0);
							SysTick_wait_10ms(1*100);
							RGB_output(14);
							SysTick_wait_10ms(1*100);
							}
						RGB_output(0);
						clear_display();
						return;}
			
					}
					else{
						minutes=(time-1)/2;//taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=30;
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
							buzzer_RGB_blinking();
						
						
							RGB_output(0);
							clear_display();
							return;}
					}
					
					
		
					
		
				}

			
				else {
					
					clear_display();
					LCD_string_display("ERR"); // show the error message and keep it for two seconds then restart the loop with clearing  display
					SysTick_wait_10ms(2*100);
					goto loop;
				}
					
		


}