#include "init.h"

void init(){
		SysTick_Init();
		SW1_init();
		SW2_init();
		SW3_init();
		RGB_init();
		Keypad_Init();
		LCD_ports_init();	
		LCD_init();
		buzzer_init();
}