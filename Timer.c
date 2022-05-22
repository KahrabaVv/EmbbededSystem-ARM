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
unsigned char start(unsigned char minutes,unsigned char seconds){
		int counter,i;// replace sw state with sw_input latelty
		unsigned char pause_flag=0;
		m=minutes,s=seconds;
	if(seconds>59){
		clear_display();
		LCD_string_display("ERR");
		SysTick_wait_10ms(1.5*100);
		clear_display();
		return 0;
		}
		while(SW3_input()==0){
		if(SW1_input()!=0){
		clear_display();
		RGB_output(0);
		return 0;// SW1!=0 which means it is pressed
		}
		}
		while(SW3_input()!=0){
			while(SW2_input()==0){
					if(pause_flag==1){
							// blinking code start
							RGB_output(0);
							for(counter=0;counter<800;counter++){
										//checking the SW1 if yes return with 0
										if(SW3_input()==0){
										pause_flag=1;
										RGB_output(0);
										if(start(minutes,seconds)==1){
										
										
										return 1;
										
										}
										else{
											clear_display();
											return 0;
										}
										}
										if(SW1_input()!=0){
										while(SW1_input()!=0);
										clear_display();
										RGB_output(0);
										return 0;// SW1!=0 which means it is pressed
										}
										if(SW2_input()!=0){
												while(SW2_input()!=0);
												goto label;
										} 
										SysTick_wait(80000/5);
										}
										RGB_output(14);
							for(counter=0;counter<700;counter++){
										//checking the SW1 if yes return with 0
										if(SW3_input()==0){
										pause_flag=1;
										RGB_output(0);
										if(start(minutes,seconds)==1){
										
										
										return 1;
										
										}
										else{
											clear_display();
											return 0;
										}
									}
										if(SW1_input()!=0){
										while(SW1_input()!=0);
										clear_display();
										RGB_output(0);
										return 0;// SW1!=0 which means it is pressed
										}
										if(SW2_input()!=0){
												while(SW2_input()!=0);
												goto label;
										}
										// waiting 1ms 
										SysTick_wait(80000/5);
										}
							//blinking code end
						}
					if (SW1_input()!=0){
						clear_display();
						RGB_output(0);
						return 0;
					}
				}
label:	if(timer(minutes,seconds)==1){
				//WRITE ENDING CODE
				RGB_output(0);
				return 1; //succesful timer without intterrpt
			}
			else{
					pause_flag=1;
					minutes=m;
					seconds=s;
			}
			}
		if(SW3_input()==0){
		pause_flag=0;
		RGB_output(0);
			if(start(minutes,seconds)==1){
				return 1;
										
			}
			else{
				clear_display();
				return 0;
			}
		}
		return 0;
					
}