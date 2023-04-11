#include "handlers.h"
#include "LCD_Control.h"

#include <linux/can.h>

// All of these functions assume display has been initialized.
void process_can_frame(struct can_frame *frame) {
  display_page_t page = get_page();
  
  switch(frame->can_id & 0xFFFFFFF) {
  case PE1_CAN_ID:
    pe1_handler(frame->data, page);
    break;
  case PE2_CAN_ID:
    pe2_handler(frame->data, page);
    break;
  case PE3_CAN_ID:
    pe3_handler(frame->data, page);
    break;
  case PE4_CAN_ID:
    pe4_handler(frame->data, page);
    break;
  case PE5_CAN_ID:
    pe5_handler(frame->data, page);
    break;
  case PE6_CAN_ID:
    pe6_handler(frame->data, page);
    break;
  case PE7_CAN_ID:
    pe7_handler(frame->data, page);
    break;
  case PE8_CAN_ID:
    pe8_handler(frame->data, page);
    break;
  case PE9_CAN_ID:
    pe9_handler(frame->data, page);
    break;
  case PE10_CAN_ID:
    pe10_handler(frame->data, page);
    break;
  case PE11_CAN_ID:
    pe11_handler(frame->data, page);
    break;
  case PE12_CAN_ID:
    pe12_handler(frame->data, page);
    break;
  case PE13_CAN_ID:
    pe13_handler(frame->data, page);
    break;
  case PE14_CAN_ID:
    pe14_handler(frame->data, page);
    break;
  case PE15_CAN_ID:
    pe15_handler(frame->data, page);
    break;
  case PE16_CAN_ID:
    pe16_handler(frame->data, page);
    break;
  default:
    break;
  }
}

void pe1_handler(void *data, display_page_t page) {
  PE1_CAN *pe1_data = (PE1_CAN *) data;

  set_rpm(pe1_data->rpm);
  set_tach(pe1_data->rpm);
  set_TPS(pe1_data->tps_percent);
  
}


void pe2_handler(void *data, display_page_t page){
  PE2_CAN *pe2_data = (PE2_CAN *) data;

  (void) pe2_data;
}


void pe3_handler(void *data, display_page_t page) {
  PE3_CAN *pe3_data = (PE3_CAN *) data;

  (void) pe3_data;
}


void pe4_handler(void *data, display_page_t page) {
  PE4_CAN *pe4_data = (PE4_CAN *) data;

  set_oil_pressure(pe4_data->analogInput6_volts);
}


void pe5_handler(void *data, display_page_t page) {
  PE5_CAN *pe5_data = (PE5_CAN *) data;

  (void) pe5_data;
}


void pe6_handler(void *data, display_page_t page) {
  PE6_CAN *pe6_data = (PE6_CAN *) data;

  set_temp(pe6_data->coolantTemp_f/10);
  set_volt(pe6_data->battery_volts/10);
}


void pe7_handler(void *data, display_page_t page) {
  PE7_CAN *pe7_data = (PE7_CAN *) data;

  set_oil_temp(pe7_data->analogInput7_f);
}


void pe8_handler(void *data, display_page_t page) {
  PE8_CAN *pe8_data = (PE8_CAN *) data;

  (void) pe8_data;
}


void pe9_handler(void *data, display_page_t page) {
  PE9_CAN *pe9_data = (PE9_CAN *) data;

  (void) pe9_data;
}


void pe10_handler(void *data, display_page_t page) {
  PE10_CAN *pe10_data = (PE10_CAN *) data;

  (void) pe10_data;
}


void pe11_handler(void *data, display_page_t page) {
  PE11_CAN *pe11_data = (PE11_CAN *) data;

  (void) pe11_data;
}


void pe12_handler(void *data, display_page_t page) {
  PE12_CAN *pe12_data = (PE12_CAN *) data;

  (void) pe12_data;
}


void pe13_handler(void *data, display_page_t page) {
  PE13_CAN *pe13_data = (PE13_CAN *) data;

  (void) pe13_data;
}


void pe14_handler(void *data, display_page_t page) {
  PE14_CAN *pe14_data = (PE14_CAN *) data;

  (void) pe14_data;
}


void pe15_handler(void *data, display_page_t page) {
  PE15_CAN *pe15_data = (PE15_CAN *) data;

  (void) pe15_data;
}


void pe16_handler(void *data, display_page_t page) {
  PE16_CAN *pe16_data = (PE16_CAN *) data;

  (void) pe16_data;
}
