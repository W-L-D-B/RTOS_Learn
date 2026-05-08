#include "Led.h"

void LED_Init(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    
    GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_RESET);
}

void delay(unsigned int ms);
void delay(unsigned int ms){
    unsigned int i, j;
    for(i = 0; i < ms; i++){
        for(j = 0; j < 12000; j++);
    }
}

void LED_Turn(void){
    GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_RESET);
    delay(1000);
    GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_SET);
    delay(1000);
}
