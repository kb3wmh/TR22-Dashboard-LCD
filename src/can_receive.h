#ifndef CAN_RECEIVE_H
#define CAN_RECEIVE_H

typedef struct can_frame cframe;

void can_init();
int receive_messages(cframe *frame);

#endif
