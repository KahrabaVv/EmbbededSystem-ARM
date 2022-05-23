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
			
			// Checks if the user inputted a valid digit
			if(temp >= '0' && temp <= '9'){
				
				sec = 0;
				min = 0;
				
				// Shifts each displayed digit to the left (discards the leftmost digit) when a new valid input is given by the user
				input[0] = input[1];
				input[1] = input[2];
				input[2] = input[3];
				input[3] = temp - '0';
				temp = 0;
				
				// Calculates the time to be displayed
				sec = (input[2] * 10) + input[3];
				min = (input[0] * 10) + input[1];
				
				// Calculates the total time in seconds inputted by the user
				totaltime = (min * 60) + sec;
				
				// Displays the time inputted by the user
				clear_display();
				timer_display(min, sec);
				
				while(Keypad_PressedKey() != 0);
			
			}
		
		}
		
		// Clears the display and returns home if SW1 is pressed
		if(SW1_input() != 0){
			clear_display();
			return;
				
		}
		
		// Checks if SW2 is pressed
		if(SW2_input() != 0){
		
			// Checks if the total time inputted by the user is less than or equal to 30 minutes
			if(totaltime > MAXTIME){
				clear_display();
				LCD_string_display("MAX TIME 30 MINS");
				SysTick_wait_10ms(50);
				clear_display();
				return;
			
			}
			// Checks if the user inputted a valid number of the "seconds" part of the timer
			else if(sec > 59){
				clear_display();
				LCD_string_display("ERR");
				SysTick_wait_10ms(50);
				clear_display();
				return;
			
			}
			// Starts the cooking process
			else{
				cookedFlag = start(min, sec);
				
				// Checks if the food had been cooked
				if(cookedFlag == 1){
				
					buzzer_RGB_blinking();
					RGB_output(0);
					clear_display();
					return;
					
				}
				
				// Returns home if the user pressed clear
				if(cookedFlag == 0){
				
					clear_display();
					return;
					
				}
			}
		}
	}
}