#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include <stdint.h>

// Display parameters
#define SERIAL_BAUDRATE 9600

// Display object indices
#define TACHOMETER_GAUGE 0

#define TEMP_DIGITS 0
#define VOLTAGE_DIGITS 1
#define TPS_DIGITS 2
#define RPM_DIGITS 3

#define TEMP_LED 0
#define OIL_LED 1
#define SLIP_LED 2

#define GEAR_STRING 0

// Useful LCD Constants
#define TACH_MAX 100
#define TACH_MIN 0

// LCD Control Functions
bool init_display();
void set_rpm(uint16_t rpm);
void set_tach(uint16_t rpm);
void set_temp(uint16_t temp);
void set_volt(uint16_t volt);
void set_TPS(uint16_t tps);
void set_gear(uint8_t gear);
void set_oil_warn(bool status);
void set_slip(bool status);

#endif
