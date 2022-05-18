#include "header.h"
#include "stdint.h"

void SysTick_Init(){
  NVIC_ST_CTRL_R=0;
  NVIC_ST_RELOAD_R=0X00FFFFFF;
  NVIC_ST_CURRENT_R=0;
  NVIC_ST_CTRL_R=0X05;
}
void SysTick_wait(uint32_t DELAY){
  NVIC_ST_RELOAD_R=DELAY-1;
  NVIC_ST_CURRENT_R=0;
  while((NVIC_ST_CTRL_R&0x10000)==0);
}
void SysTick_wait_10ms(uint32_t DELAY){
    uint32_t counter;
    for(counter=0;counter<DELAY;counter++){
    SysTick_wait(800000/5);
  }
}
void SysTick_wait_1ms(uint32_t DELAY){
    uint32_t counter;
    for(counter=0;counter<DELAY;counter++){
    SysTick_wait(80000/5);
  }
}
void SysTick_wait_1micro(uint32_t DELAY){
    uint32_t counter;
    for(counter=0;counter<DELAY;counter++){
    SysTick_wait(80/5);
  }
}