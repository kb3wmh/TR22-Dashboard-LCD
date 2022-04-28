#ifndef HANDLERS_H
#define HANDLERS_H

#include <linux/can.h>
#include "PE3_CAN.h"

void process_can_frame(struct can_frame *frame);

// Take CAN data and process it
void pe1_handler(void *data);
void pe2_handler(void *data);
void pe3_handler(void *data);
void pe4_handler(void *data);
void pe5_handler(void *data);
void pe6_handler(void *data);
void pe7_handler(void *data);
void pe8_handler(void *data);
void pe9_handler(void *data);
void pe10_handler(void *data);
void pe11_handler(void *data);
void pe12_handler(void *data);
void pe13_handler(void *data);
void pe14_handler(void *data);
void pe15_handler(void *data);
void pe16_handler(void *data);


#endif
