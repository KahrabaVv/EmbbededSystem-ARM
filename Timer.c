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
unsigned char timer(unsigned char minutes,unsigned char seconds){
	int counter;
	RGB_output(14);
	while(1){
		timer_display(minutes,seconds);
		// in case of pause
		m=minutes;
		s=seconds;
		// no need if there is no pause
		if(((minutes|seconds)!=0)){
			if(seconds>0){
				seconds-=1;
			}
			else{
					seconds=59;
					minutes-=1;
			}
		}
		else{
			SysTick_wait_10ms(100);
			RGB_output(0);
			return 1; //successful timer without interrupt (may be paused and resumed)
		}
		//waiting one second
		for(counter=0;counter<1000;counter++){
			//checking the SW1 if yes return with 0
			if(SW3_input()==0){
				return 2;}
			if(SW1_input()!=0){
				while(SW1_input()!=0);
				return 0;// SW1!=0 which means it is pressed
			}
			// waiting 1ms 
			SysTick_wait(80000/5);
		}
	}
}