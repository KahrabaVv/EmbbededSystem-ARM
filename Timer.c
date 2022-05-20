#include "timer.h"

char m,s;

void timer_display(unsigned char minutes,unsigned char seconds){
		unsigned char m1,m0,s1,s0;// the timer will be as follows : m1 m0:s1 s0
		s0=seconds%10;
		s1=(seconds-s0)/10;
		m0=minutes%10;
		m1=(minutes-m0)/10;
		s0+='0';//changing the number to real character format
		s1+='0';//changing the number to real character format
		m0+='0';//changing the number to real character format
		m1+='0';//changing the number to real character format
		clear_display();// to clear the lcd
		LCD_char_display(m1);// the sequence is important here
		LCD_char_display(m0);
		LCD_char_display(':');
		LCD_char_display(s1);
		LCD_char_display(s0);
		// can it be done with LCD_string_display() ?
}