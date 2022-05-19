#include "switches.h"

void SW1_init(){
		SYSCTL_RCGCGPIO_R|=0X20;
		while((SYSCTL_PRGPIO_R&0X20)==0);
		GPIO_PORTF_LOCK_R=0X4C4F434B;
		GPIO_PORTF_CR_R|=0X10;
		GPIO_PORTF_DIR_R&=~0x10;
		GPIO_PORTF_DEN_R|=0X10;
		GPIO_PORTF_AMSEL_R&=~0x10;// disabling analog function of PF4(SW2)
		GPIO_PORTF_PUR_R|=0X10;
		GPIO_PORTF_PCTL_R&=~0xF0000;
		GPIO_PORTF_AFSEL_R&=~0x10;
}

void SW2_init(){
		SYSCTL_RCGCGPIO_R|=0X20;
		while((SYSCTL_PRGPIO_R&0X20)==0);
		GPIO_PORTF_LOCK_R=0X4C4F434B;
		GPIO_PORTF_CR_R|=0X01;
		GPIO_PORTF_DIR_R&=~0x01;
		GPIO_PORTF_DEN_R|=0X01;
		GPIO_PORTF_AMSEL_R&=~0x01;// disabling analog function of PF4(SW2)
		GPIO_PORTF_PUR_R|=0X01;
		GPIO_PORTF_AFSEL_R&=~0x01;
		GPIO_PORTF_PCTL_R&=~0x0000F;
}

void SW3_init(){
		SYSCTL_RCGCGPIO_R |= 0x01; //activating port A
		while((SYSCTL_PRGPIO_R & 0x01) == 0);
	
		// Pin PA3
		GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY; // Unlock Port A
		GPIO_PORTA_CR_R |= 0x08;	// Enable Changes on PA3
		GPIO_PORTA_DIR_R &= ~0x08; // Set PA3 as Input
		GPIO_PORTA_DEN_R |= 0x08; // Set PA3 as Digital Pins
		GPIO_PORTA_PUR_R |= 0x08;	// Enable Pull Up Resistor for PA3
		GPIO_PORTA_AMSEL_R &= ~0x08; // Disable Analog Mode for PA3
		GPIO_PORTA_PCTL_R &= ~0XF000; // Disable PCTL for PA3
		GPIO_PORTA_AFSEL_R &= ~0x08; // Disable Alternate Functions for PA3
	
}

unsigned char SW1_input(){
		return (~GPIO_PORTF_DATA_R )& 0x10;
}

unsigned char SW2_input(){
		return (~GPIO_PORTF_DATA_R) & 0x01;
}

unsigned char SW3_input(){
		return (~GPIO_PORTA_DATA_R&0x8)>>3;
}