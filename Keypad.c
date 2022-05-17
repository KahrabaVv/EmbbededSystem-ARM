#include "Keypad.h"

const int ROWS = 4;
const int COLUMNS = 4;

void Keypad_Init(){
		SYSCTL_RCGCGPIO_R |= 0x14; //activating port C and port E
		while((SYSCTL_PRGPIO_R & 0x14) == 0);
	
		// Pins PC4 -> PC7 Represents The Columns of The Keypad
		GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY; // Unlock Port C
		GPIO_PORTC_CR_R |= 0xF0;	// Enable Changes on PC4 -> PC7
		GPIO_PORTC_DIR_R |= 0xF0; // Set PC4 -> PC7 as Outputs
		GPIO_PORTC_DEN_R |= 0xF0; // Set PC4 -> PC7 as Digital Pins
		GPIO_PORTC_AMSEL_R &= ~0xF0; // Disable Analog Mode for PC4 -> PC7
		GPIO_PORTC_PCTL_R &= ~0XFFFF0000; // Disable PCTL for PC4 -> PC7
		GPIO_PORTC_AFSEL_R &= ~0xF0; // Disable Alternate Functions for PC4 -> PC7
	
		// Pins PE0 -> PE3 Represents The Rows of The Keypad
		GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY; // Unlock Port E
		GPIO_PORTE_CR_R |= 0x0F;	// Enable Changes on PE0 -> PE3
		GPIO_PORTE_DIR_R &= ~0x0F; // Set PE0 -> PE3 as Inputs
		GPIO_PORTE_DEN_R |= 0x0F;	 // Set PE0 -> PE3 as Digital Pins
		GPIO_PORTE_PDR_R |= 0x0F;	 // Enable PDR for PE0 -> PE3
		GPIO_PORTE_AMSEL_R &= ~0x0F; // Disable Analog Mode for PE0 -> PE3
		GPIO_PORTE_PCTL_R &= ~0X0000FFFF; // Disable PCTL for PE0 -> PE3
		GPIO_PORTE_AFSEL_R &= ~0x0F; // Disable Alternate Functions for PE0 -> PE3
		
}

char Keypad_check(){
		char keys[ROWS][COLUMNS] = { {'1', '2', '3', 'A'},
																 {'4', '5', '6', 'B'},
																 {'7', '8', '9', 'C'}, 
																 {'*', '0', '#', 'D'} };
		
			int i;
			int j;
			
			for(i = 0; i < COLUMNS; i++){
				
				GPIO_PORTC_DATA_R = (1U << (i+4)); // Shifts The "Set" Bit by i+4 To Set One of The Used Port C Pins
				SysTick_wait_1micro(2);
				
				for(j = 0; j < ROWS; j++){
					
					if((GPIO_PORTE_DATA_R & 0x0F) & (1U << j)){ // Checks If a Key Was Pressed
				
						return keys[j][i];	// Returns The Pressed KEY
				
					}
				}				
			}
			return 0;
		
}
