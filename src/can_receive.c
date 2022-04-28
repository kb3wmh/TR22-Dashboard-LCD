#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "LCD_Main.h"
#include "can_receive.h"

int s;
struct sockaddr_can addr;
struct ifreq ifr;


void can_init() {
  s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

  strcpy(ifr.ifr_name, "can0");
  ioctl(s, SIOCGIFINDEX, &ifr);

  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;

  bind(s, (struct sockaddr *)&addr, sizeof(addr));
}

int receive_messages(struct can_frame *frame) {
  // Read next CAN frame
  nbytes = read(s, frame, sizeof(struct can_frame));

  if (nbytes < 0) {
    perror("can raw socket read");
    return 1;
  }

  if (nbytes < sizeof(struct can_frame)) {
    fprintf(stderr, "read: incomplete CAN frame\n");
    return 1;
  }

  return 0;
}
