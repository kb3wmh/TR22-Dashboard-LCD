#include "LCD_Main.h"
#include <stdlib.h>

#include <can_receive.h>
#include <linux/can.h>

#include "handlers.h"

// Initialize the data fields for each of the CAN handlers

void setup() {
  init_display();
  can_init();
}

void loop() {
  struct can_frame frame;

  for (;;) {
    if (receive_messages(&frame) != 0) {
      printf("Error receiving message!\n");
      return;
    }

    process_can_frame(&frame);    
  }
}


int main(int argc, char **argv) {
  setup();
  loop();
}
