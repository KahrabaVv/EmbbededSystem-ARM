#include "buttonC.h"

void C(){

				
				unsigned char int_digit;
				unsigned char digit;
				unsigned int time;
				unsigned char minutes;
				unsigned char seconds;
				
loop:		clear_display();
				LCD_string_display ("CHICKEN WEIGHT?");
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
					
					
					
					if(time==1 || time==6){
						minutes=(time<5)?0:1;  //taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=12; //returning 30/0 seconds ex: (int)(30*(5-4))= 30
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
						buzzer_RGB_blinking();
						RGB_output(0);
						clear_display();
						return;}
			
					}
					else if(time==2 || time==7){
						minutes=(time<5)?0:1;//taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=24;
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
						buzzer_RGB_blinking();
						RGB_output(0);
						clear_display();
						return;}
					}
					else if(time==3 || time==8){
						minutes=(time<5)?0:1;//taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=36;
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
						buzzer_RGB_blinking();
						RGB_output(0);
						clear_display();
						return;}
					}else if(time==4 || time==9){
						minutes=(time<5)?0:1;//taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=48;
						timer_display(minutes,seconds);
						if(start(minutes,seconds) ==1){
						buzzer_RGB_blinking();
						RGB_output(0);
						clear_display();
						return;}
					}else if(time==5){
						minutes=1;//taking the integer part and turning it into char ex: digit_to_char(4.5)=4
		
						seconds=0;
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
