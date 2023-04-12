#ifndef HANDLERS_H
#define HANDLERS_H

#include <linux/can.h>
#include "PE3_CAN.h"
#include "LCD_control.h"

void process_can_frame(struct can_frame *frame);

// Take CAN data and process it
void pe1_handler(void *data, display_page_t page);
void pe2_handler(void *data, display_page_t page);
void pe3_handler(void *data, display_page_t page);
void pe4_handler(void *data, display_page_t page);
void pe5_handler(void *data, display_page_t page);
void pe6_handler(void *data, display_page_t page);
void pe7_handler(void *data, display_page_t page);
void pe8_handler(void *data, display_page_t page);
void pe9_handler(void *data, display_page_t page);
void pe10_handler(void *data, display_page_t page);
void pe11_handler(void *data, display_page_t page);
void pe12_handler(void *data, display_page_t page);
void pe13_handler(void *data, display_page_t page);
void pe14_handler(void *data, display_page_t page);
void pe15_handler(void *data, display_page_t page);
void pe16_handler(void *data, display_page_t page);


#endif
