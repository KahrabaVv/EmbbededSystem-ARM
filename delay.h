#include "header.h"
#include "stdint.h"

void SysTick_Init();
void SysTick_wait(uint32_t DELAY);
void SysTick_wait_10ms(uint32_t DELAY);
void SysTick_wait_1ms(uint32_t DELAY);
void SysTick_wait_1micro(uint32_t DELAY);