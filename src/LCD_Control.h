#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#include <stdint.h>
#include <stdbool.h>

// Display parameters
#define SERIAL_BAUDRATE 115200
#define SERIAL_PORT "/dev/ttyUSB0"

// Display object indices
#define TACHOMETER_GAUGE 0

#define COOLANT_TEMP_DIGITS 0
#define OIL_TEMP_DIGITS 1
#define OIL_PRESSURE_DIGITS 2
#define RPM_DIGITS 3

//#define VOLTAGE_DIGITS 999
//#define TPS_DIGITS 999
//#define TEMP_DIGITS

#define TEMP_LED 0
#define OIL_LED 1
#define SLIP_LED 2

#define GEAR_STRING 0

#define DEFAULT_PAGE 0
#define DIAG_PAGE 1

// Useful LCD Constants
#define TACH_MAX 100
#define TACH_MIN 0
#define BLINK_RATE 500
#define TACH_RPM_FILTER 125
#define RPM_DISPLAY_ROUND 50

// LCD Type Definitions

typedef enum {
    NORMAL_PAGE,
    DIAGNOSTICS_PAGE,
    NON_DISPLAY_PAGE
} display_page_t;

// LCD Control Functions
bool init_display();
void set_rpm(uint16_t rpm);
void set_tach(uint16_t rpm);
void set_temp(uint16_t temp);
void set_oil_temp(int16_t sensorvolts);
void set_oil_pressure(int16_t sensorvolts);
void set_volt(uint16_t volt);
void set_TPS(uint16_t tps);
void set_gear(uint8_t gear);
void set_oil_warn(bool status);
void set_slip(bool status);
display_page_t get_page();

#endif
