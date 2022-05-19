#include "header.h"
#include "stdint.h"
#include "delay.h"

void LCD_ports_init();
void LCD_command(unsigned char cmd);
void LCD_char_display(unsigned char data);
void LCD_init();
void clear_display();
void LCD_string_display(char string[]);