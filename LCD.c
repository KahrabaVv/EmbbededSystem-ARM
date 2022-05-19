#include "lcd.h"

void LCD_ports_init(){
		SYSCTL_RCGCGPIO_R |= 0x03; // Enable clock for ports
    while((SYSCTL_PRGPIO_R & 0x03)==0){};  //wait til ports are activated
    GPIO_PORTA_DIR_R |=0xE0; //PORTA controls RS,E and R/W
    GPIO_PORTA_DEN_R |=0xE0;
    //portB
    GPIO_PORTB_DIR_R |=0xFF; //PORTB D0-D7
    GPIO_PORTB_DEN_R |=0xFF; //PORTB D0-D7
}
void LCD_command(unsigned char cmd){
	// using PA5->PA7 FOR  E, R\W , RS  respectively
	GPIO_PORTB_DATA_R=cmd;// LOADING cmd on port B
	GPIO_PORTA_DATA_R&=0X3F;// RS=0,R\W=0
	GPIO_PORTA_DATA_R|=0X20; // EN=1
	SysTick_wait_1micro(1);//waiting for 1 micro second for enable
	GPIO_PORTA_DATA_R&=~0X20;// EN =0 ==> EXECUTING THE COMMAND
	SysTick_wait_1micro(50);
}
void LCD_char_display(unsigned char data){
	// using PA5->PA7 FOR  E, R\W , RS  respectively
	GPIO_PORTB_DATA_R=data;// LOADING cmd on port B
	GPIO_PORTA_DATA_R&=0XBF;// R\W=0
	GPIO_PORTA_DATA_R|=0XA0; // EN=1,RS=1
	SysTick_wait_1micro(1);//waiting for 1 micro second for enable
	GPIO_PORTA_DATA_R&=~0X20;// EN =0 ==> EXECUTING THE COMMAND , DO NOT CHANGE RS untill the RAM take the data
	SysTick_wait_1micro(50);// required: 43 micro seconds to write data to internal RAM
}
void LCD_init(){
	SysTick_wait_1ms(500); //waiting for 0.5 second for voltage stability
	LCD_command(0X38);		 // 8 bit mode & 2-line mode & font 5x8
	LCD_command(0X0F);     // display on & cursor on &  blink on
	LCD_command(0x06);     // Auto Increment cursor
	LCD_command(0x01);     // display clear
	SysTick_wait_1ms(2);   // waiting for clear
	LCD_command(0x2);      //  Cursor at home position
	SysTick_wait_1ms(2);	 // waiting for home return
}
void clear_display(){
	LCD_command(0x01);     // display clear
	SysTick_wait_1ms(2);   // waiting for clear
	LCD_command(0x02);      //  Cursor at home position
	SysTick_wait_1ms(2);	 // waiting for home return
}
void LCD_string_display(char string[]){
	int i;
	for(i=0;string[i]!=0;i++){
		LCD_char_display(string[i]);
	}
}