#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>

#include <geniePi.h>

#include "LCD_Control.h"
#include "car_consts.h"

// Old RPM state used to limit rate of updates to RPM
uint16_t rpm_old;

// Returns false if display does not initialize correctly
bool init_display() {

  if (genieSetup(SERIAL_PORT, SERIAL_BAUDRATE) < 0) {
    fprintf (stderr, "rgb: Can't initialize Genie Display: %s\n", strerror(errno));
    return false;
  }

  genieWriteObj(GENIE_OBJ_FORM, DEFAULT_PAGE, 0);

  rpm_old = 0;
  
  return true;
}

void set_rpm(uint16_t rpm) {
    // Round RPM to the nearest 50
    rpm = rpm - (rpm % RPM_DISPLAY_ROUND);

    genieWriteObj(GENIE_OBJ_LED_DIGITS, RPM_DIGITS, rpm);
}

void set_tach(uint16_t rpm) {
  int16_t gaugePercent = 0;

  if (rpm > TACH_MIN_RPM) {
    gaugePercent = (TACH_MAX * (rpm - TACH_MIN_RPM)) / (REDLINE - TACH_MIN_RPM);
    
    if (rpm > SHIFT_POINT) {
      struct timeval current_time;
      gettimeofday(&current_time, NULL);

      suseconds_t milliseconds = current_time.tv_usec / 1000;

      // First half of every second, allow gauge to be on, otherwise force it off
      int16_t blink = (milliseconds % BLINK_RATE) < (BLINK_RATE / 2) ? 0 : 1;
      gaugePercent = gaugePercent * blink;

      genieWriteObj(GENIE_OBJ_GAUGE, TACHOMETER_GAUGE, gaugePercent);
    }

    // Only update tachometer if RPM has changed by more than 125 RPM
    else if (abs(rpm - rpm_old) > TACH_RPM_FILTER) {
      rpm_old = rpm;
      genieWriteObj(GENIE_OBJ_GAUGE, TACHOMETER_GAUGE, gaugePercent);
    }

    else if (rpm == 0) {
      rpm_old = rpm;
      genieWriteObj(GENIE_OBJ_GAUGE, TACHOMETER_GAUGE, 0);
    }
    
  }
}

void set_temp(uint16_t temp) {
  genieWriteObj(GENIE_OBJ_LED_DIGITS, COOLANT_TEMP_DIGITS, temp);

  if (temp >= TEMP_ALARM_ON) {
    genieWriteObj(GENIE_OBJ_USER_LED, TEMP_LED, 1);
  }

  if (temp <= TEMP_ALARM_OFF) {
    genieWriteObj(GENIE_OBJ_USER_LED, TEMP_LED, 0);
  }
}

void set_oil_temp(int16_t temp) {
  // TODO: Determine calibration at different temps
  genieWriteObj(GENIE_OBJ_LED_DIGITS, OIL_TEMP_DIGITS, temp * 0.1);
}

void set_oil_pressure(int16_t sensorvolts) {
  double pressure = ((sensorvolts * 0.001) - 0.5)*37.0/1.55;

  genieWriteObj(GENIE_OBJ_LED_DIGITS, OIL_PRESSURE_DIGITS, (uint16_t) pressure);

  if (pressure < 10.0) {
    set_oil_warn(true);
  }

  else {
    set_oil_warn(false);
  }
}

void set_volt(uint16_t volt) {
  //genieWriteObj(GENIE_OBJ_LED_DIGITS, VOLTAGE_DIGITS, volt);
}

void set_TPS(uint16_t tps) {
  //genieWriteObj(GENIE_OBJ_LED_DIGITS, TPS_DIGITS, tps);
}

void set_gear(uint8_t gear) {
  char gears[7][2] = {"N", "1", "2", "3", "4", "5", "6"};

  genieWriteStr(GEAR_STRING, gears[gear]);
}

// TODO: determine oil pressure CAN message
void set_oil_warn(bool status) {
  genieWriteObj(GENIE_OBJ_USER_LED, OIL_LED, status);
}

// TODO: determine slip cutoff
void set_slip(bool status) {
  genieWriteObj(GENIE_OBJ_USER_LED, SLIP_LED, status);
}

// Determines if display is in normal mode, diagnostics mode, or a non-interactive mode
display_page_t get_page() {
  display_page_t page;

  int page_reply = genieReadObj(GENIE_OBJ_FORM, 0);

  if (page_reply == DEFAULT_PAGE) {
    page = NORMAL_PAGE;
  }

  else if (page_reply == DIAG_PAGE) {
    page = DIAGNOSTICS_PAGE;
  }

  else {
    page = NON_DISPLAY_PAGE;
  }

  return page;
}

void set_diagnostics_digits(int field, int value) {
  genieWriteObj(GENIE_OBJ_LED_DIGITS, field, value);
}

/* int main() { */
/*   // Try to initialize display, quit if error */
/*   printf("Starting\n"); */
/*   if (!init_display()) { */
/*     return 1; */
/*   } */

/*   printf("Initialized Display\n"); */
/*   uint16_t rpm = 12500; */
/*   uint16_t temp = 225; */
/*   uint16_t volt = 125; */
/*   uint16_t tps = 78; */
/*   uint8_t gear = 0; */
/*   bool oil_warn = false; */
/*   bool slip = false; */

/*   set_gear(gear); */

  
/*   for (;;) { */
/*     set_rpm(rpm); */
/*     set_tach(rpm); */
/*     set_temp(temp); */
/*     set_volt(volt); */
/*     set_TPS(tps); */
/*     set_oil_warn(oil_warn); */
/*     set_slip(slip); */

/*     usleep(10000); */
/*   } */
/* } */
