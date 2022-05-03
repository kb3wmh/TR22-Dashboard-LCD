#include "LCD_Main.h"
#include <stdlib.h>
#include <stdio.h>

#include "can_receive.h"
#include <linux/can.h>

#include "handlers.h"
#include "LCD_Control.h"

// Initialize the data fields for each of the CAN handlers

void setup() {
  init_display();
  can_init();
}

void loop() {
  cframe frame;

  printf("Terps Racing Dashboard 2022\n");
  
  for (;;) {
    if (receive_messages(&frame) != 0) {
      printf("Error receiving message!\n");
      return;
    }

    process_can_frame(&frame);    
  }
}


int main() {
  setup();
  loop();
}
