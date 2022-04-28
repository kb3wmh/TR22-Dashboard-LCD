#ifndef LCD_MAIN_H
#define LCD_MAIN_H

#include <pthread.h>



volatile updates_queue *updates;
volatile PE3_DATA *data;

volatile PE1_CAN pe1_can;
volatile PE2_CAN pe2_can;
volatile PE3_CAN pe3_can;
volatile PE4_CAN pe4_can;
volatile PE5_CAN pe5_can;
volatile PE6_CAN pe6_can;
volatile PE7_CAN pe7_can;
volatile PE8_CAN pe8_can;
volatile PE9_CAN pe9_can;
volatile PE10_CAN pe10_can;
volatile PE11_CAN pe11_can;
volatile PE12_CAN pe12_can;
volatile PE13_CAN pe13_can;
volatile PE14_CAN pe14_can;
volatile PE15_CAN pe15_can;
volatile PE16_CAN pe16_can;

void setup();
void start();


#endif
