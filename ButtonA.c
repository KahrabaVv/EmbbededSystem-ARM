#include "buttonA.h"

void A(){
	char counter;

			LCD_string_display("Popcorn?");
			SysTick_wait_10ms(150);
			timer_display(1,0);
			if(start(1,0)==1){
				//buzzer_blink start
				buzzer_RGB_blinking();
				//buzzer blink 
				clear_display() ;
			}
			RGB_output(0);
}

