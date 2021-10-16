#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include <geniePi.h>

#include "LCD_Control.h"
#include "car_consts.h"

// Returns false if display does not initialize correctly
bool init_display() {

  if (genieSetup("/dev/ttyS0", SERIAL_BAUDRATE) < 0) {
    fprintf (stderr, "rgb: Can't initialize Genie Display: %s\n", strerror(errno));
    return false;
  }

  return true;
}

void set_rpm(uint16_t rpm) {
  //genieWriteShortToIntLedDigits(RPM_DIGITS, (int16_t) rpm);
  genieWriteObj(GENIE_OBJ_LED_DIGITS, RPM_DIGITS, rpm);
}

void set_tach(uint16_t rpm) {
  int16_t gaugePercent = 0;

  if (rpm > TACH_MIN_RPM) {
    gaugePercent = (TACH_MAX * (rpm - TACH_MIN_RPM)) / (REDLINE - TACH_MIN_RPM);
    genieWriteObj(GENIE_OBJ_GAUGE, TACHOMETER_GAUGE, gaugePercent);
  }
}

void set_temp(uint16_t temp) {
  genieWriteObj(GENIE_OBJ_LED_DIGITS, TEMP_DIGITS, temp);

  if (temp >= TEMP_ALARM_ON) {
    genieWriteObj(GENIE_OBJ_USER_LED, TEMP_LED, 1);
  }

  if (temp <= TEMP_ALARM_OFF) {
    genieWriteObj(GENIE_OBJ_USER_LED, TEMP_LED, 0);
  }
}

void set_volt(uint16_t volt) {
  genieWriteObj(GENIE_OBJ_LED_DIGITS, VOLTAGE_DIGITS, volt);
}

void set_TPS(uint16_t tps) {
  genieWriteObj(GENIE_OBJ_LED_DIGITS, TPS_DIGITS, tps);
}

void set_gear(uint8_t gear) {
  char gears[7][2] = {"N", "1", "2", "3", "4", "5", "6"};

  genieWriteStr(GEAR_STRING, gears[gear]);
}

void set_oil_warn(bool status) {
  genieWriteObj(GENIE_OBJ_USER_LED, OIL_LED, status);
}

void set_slip(bool status) {
  genieWriteObj(GENIE_OBJ_USER_LED, SLIP_LED, status);
}

int main() {
  // Try to initialize display, quit if error
  printf("Starting\n");
  if (!init_display()) {
    return 1;
  }

  printf("Initialized Display\n");
  uint16_t rpm = 12500;
  uint16_t temp = 225;
  uint16_t volt = 125;
  uint16_t tps = 78;
  uint8_t gear = 6;
  bool oil_warn = false;
  bool slip = false;

  set_rpm(rpm);
  set_tach(rpm);
  set_temp(temp);
  set_gear(gear);
  set_volt(volt);
  set_TPS(tps);
  set_oil_warn(oil_warn);
  set_slip(slip);
}
