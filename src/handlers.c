#include "handlers.h"
#include "LCD_Control.h"

#include <linux/can.h>

// All of these functions assume display has been initialized.
void process_can_frame(struct can_frame *frame) {
  switch(frame->can_id) {
  case PE1_CAN_ID:
    pe1_handler(frame->data);
    break;
  case PE2_CAN_ID:
    pe2_handler(frame->data);
    break;
  case PE3_CAN_ID:
    pe3_handler(frame->data);
    break;
  case PE4_CAN_ID:
    pe4_handler(frame->data);
    break;
  case PE5_CAN_ID:
    pe5_handler(frame->data);
    break;
  case PE6_CAN_ID:
    pe6_handler(frame->data);
    break;
  case PE7_CAN_ID:
    pe7_handler(frame->data);
    break;
  case PE8_CAN_ID:
    pe8_handler(frame->data);
    break;
  case PE9_CAN_ID:
    pe9_handler(frame->data);
    break;
  case PE10_CAN_ID:
    pe10_handler(frame->data);
    break;
  case PE11_CAN_ID:
    pe11_handler(frame->data);
    break;
  case PE12_CAN_ID:
    pe12_handler(frame->data);
    break;
  case PE13_CAN_ID:
    pe13_handler(frame->data);
    break;
  case PE14_CAN_ID:
    pe14_handler(frame->data);
    break;
  case PE15_CAN_ID:
    pe15_handler(frame->data);
    break;
  case PE16_CAN_ID:
    pe16_handler(frame->data);
    break;
  default:
    break;
  }
}

void pe1_handler(void *data) {
  PE1_CAN *pe1_data = (PE1_CAN *) data;

  set_rpm(pe1_data->rpm);
  set_tach(pe1_data->rpm);
  set_TPS(pe1_data->tps_percent);
  
}


void pe2_handler(void *data){
  PE2_CAN *pe2_data = (PE2_CAN *) data;
}


void pe3_handler(void *data) {
  PE3_CAN *pe3_data = (PE3_CAN *) data;
}


void pe4_handler(void *data) {
  PE4_CAN *pe4_data = (PE4_CAN *) data;
}


void pe5_handler(void *data) {
  PE5_CAN *pe5_data = (PE5_CAN *) data;
}


void pe6_handler(void *data) {
  PE6_CAN *pe6_data = (PE6_CAN *) data;

  set_temp(pe6_data->coolantTemp_f);
  set_volt(pe6_data->battery_volts);
}


void pe7_handler(void *data) {
  PE7_CAN *pe7_data = (PE7_CAN *) data;
}


void pe8_handler(void *data) {
  PE8_CAN *pe8_can = (PE8_CAN *) data;
}


void pe9_handler(void *data) {
  PE9_CAN *pe9_can = (PE9_CAN *) data;
}


void pe10_handler(void *data) {
  PE10_CAN *pe10_can = (PE10_CAN *) data;
}


void pe11_handler(void *data) {
  PE11_CAN *pe11_can = (PE11_CAN *) data;
}


void pe12_handler(void *data) {
  PE12_CAN *pe12_can = (PE12_CAN *) data;
}


void pe13_handler(void *data) {
  PE13_CAN *pe13_can = (PE13_CAN *) data;
}


void pe14_handler(void *data) {
  PE14_CAN *pe14_can = (PE14_CAN *) data;
}


void pe15_handler(void *data) {
  PE15_CAN *pe15_can = (PE15_CAN *) data;
}


void pe16_handler(void *data) {
  PE16_CAN *pe16_can = (PE16_CAN *) data;
}
