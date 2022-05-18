#include "buzzer.h"

void buzzer_init(){
		GPIO_PORTA_DIR_R |=0x4; //PORTA controls RS,E and R/W
    GPIO_PORTA_DEN_R |=0x4;
}

void buzzer_RGB_blinking(){
char counter;
for(counter=0;counter<3;counter++){
			RGB_output(0);
			GPIO_PORTA_DATA_R|=0x4;
			SysTick_wait_10ms(1*100);
			GPIO_PORTA_DATA_R&=~0x4;
			RGB_output(14);
			SysTick_wait_10ms(1*100);
			}
}