#ifndef CAN_RECEIVE_H
#define CAN_RECEIVE_H

void can_init();
void receive_messages(struct can_frame *frame);

#endif
