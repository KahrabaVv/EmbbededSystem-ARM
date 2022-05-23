#include "buttonD.h"
#define MAXTIME 1800

void D(){

	int input[4] = {0, 0, 0, 0};
	int sec = 0;
	int min = 0;
	int totaltime = 0;
	int cookedFlag;
	char temp;

	clear_display();
	LCD_string_display("Cooking Time?");
	
	
	while(1){
	
		if(Keypad_PressedKey() != 0){
			temp = Keypad_PressedKey();
			if(temp >= '0' && temp <= '9'){
				
				sec = 0;
				min = 0;
				
				input[0] = input[1];
				input[1] = input[2];
				input[2] = input[3];
				input[3] = temp - '0';
				temp = 0;
				
				sec = (input[2] * 10) + input[3];
				min = (input[0] * 10) + input[1];
				totaltime = (min * 60) + sec;
				clear_display();
				timer_display(min, sec);
				
				while(Keypad_PressedKey() != 0);
			
			}
		
		}
		
		if(SW1_input() != 0){
			clear_display();
			return;
				
		}
		
		if(SW2_input() != 0){
		
			if(totaltime > MAXTIME){
				clear_display();
				LCD_string_display("MAX TIME 30 MINS");
				SysTick_wait_10ms(50);
				clear_display();
				return;
			
			}
			else if(sec > 59){
				clear_display();
				LCD_string_display("ERR");
				SysTick_wait_10ms(50);
				clear_display();
				return;
			
			}
			else{
				cookedFlag = start(min, sec);
				
				if(cookedFlag == 1){
				
					buzzer_RGB_blinking();
					RGB_output(0);
					clear_display();
					return;
					
				}
				if(cookedFlag == 0){
				
					clear_display();
					return;
					
				}
			}
		}
	}
}