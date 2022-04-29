#ifndef PE3_CAN_H
#define PE3_CAN_H

#include <stdint.h>

/*
 * For CAN Definitions visit:
 * https://pe-ltd.com/assets/AN400_CAN_Protocol_C.pdf
 */

#define PE1_CAN_ID 0x0CFFF048
typedef struct __attribute__((__packed__)) PE1_CAN {
  uint16_t rpm;
  int16_t tps_percent;
  int16_t fuelOpenTime_ms;
  int16_t ignitionAngle_deg;
} PE1_CAN;

#define PE2_CAN_ID 0x0CFFF148
typedef struct __attribute__((__packed__)) PE2_CAN {
  int16_t barometer_psi;
  int16_t map_psi;
  int16_t lambda;
  uint16_t UNUSED_PAD;
} PE2_CAN;

#define PE3_CAN_ID 0x0CFFF248
typedef struct __attribute__((__packed__)) PE3_CAN {
  int16_t analogInput1_volts;
  int16_t analogInput2_volts;
  int16_t analogInput3_volts;
  int16_t analogInput4_volts;
} PE3_CAN;

#define PE4_CAN_ID 0x0CFFF348
typedef struct __attribute__((__packed__)) PE4_CAN {
  int16_t analogInput5_volts;
  int16_t analogInput6_volts;
  int16_t analogInput7_volts;
  int16_t analogInput8_volts;
} PE4_CAN;

#define PE5_CAN_ID 0x0CFFF448
typedef struct __attribute__((__packed__)) PE5_CAN {
  int16_t frequency1_hz;
  int16_t frequency2_hz;
  int16_t frequency3_hz;
  int16_t frequency4_hz;
} PE5_CAN;

#define PE6_CAN_ID 0x0CFFF548
typedef struct __attribute__((__packed__)) PE6_CAN {
  int16_t battery_volts;
  int16_t airTemp_f;
  int16_t coolantTemp_f;
  int16_t UNUSED_PAD;
  
} PE6_CAN;

#define PE7_CAN_ID 0x0CFFF648
typedef struct __attribute__((__packed__)) PE7_CAN {
  int16_t analogInput5_f;
  int16_t analogInput7_f;
  uint8_t versionMajor;
  uint8_t versionMinor;
  uint8_t versionBuild;
  uint8_t UNUSED_PAD;
} PE7_CAN;

#define PE8_CAN_ID 0x0CFFF748
typedef struct __attribute__((__packed__)) PE8_CAN {
  int16_t rpmRate_rpmPerSecond;
  int16_t tpsRate_percentPerSecond;
  int16_t mapRate_psiPerSecond;
  int16_t mafLoadRate_gPerRevPerSecond;
} PE8_CAN;

#define PE9_CAN_ID 0x0CFFF848
typedef struct __attribute__((__packed__)) PE9_CAN {
  int16_t lambda1Measured;
  int16_t lambda2Measured;
  int16_t targetLambda;
  int16_t UNUSED_PAD;
} PE9_CAN;

#define PE10_CAN_ID 0x0CFFF948
typedef struct __attribute__((__packed__)) PE10_CAN {
  uint8_t pwmDutyCycle1_percent;
  uint8_t pwmDutyCycle2_percent;
  uint8_t pwmDutyCycle3_percent;
  uint8_t pwmDutyCycle4_percent;
  uint8_t pwmDutyCycle5_percent;
  uint8_t pwmDutyCycle6_percent;
  uint8_t pwmDutyCycle7_percent;
  uint8_t pwmDutyCycle8_percent;
} PE10_CAN;

#define PE11_CAN_ID 0x0CFFFA48
typedef struct __attribute__((__packed__)) PE11_CAN {
  int16_t slip_percent;
  int16_t drivenWheelRateOfChange_ftPerSecPerSec;
  int16_t desiredValue_percent;
  uint16_t UNUSED_PAD;
} PE11_CAN;

#define PE12_CAN_ID 0x0CFFFB48
typedef struct __attribute__((__packed__)) PE12_CAN {
  uint16_t drivenAvgWheelSpeed_ftPerSec;
  uint16_t nonDrivenAvgWheelSpeed_ftPerSec;
  int16_t ignitionCompensation_deg;
  int16_t ignitionCut_percent;
} PE12_CAN;

#define PE13_CAN_ID 0x0CFFFC48
typedef struct __attribute__((__packed__)) PE13_CAN {
  uint16_t drivenWheelSpeed1_ftPerSec;
  uint16_t drivenWheelSpeed2_ftPerSec;
  uint16_t nonDrivenWheelSpeed1_ftPerSec;
  uint16_t nonDrivenWheelSpeed2_ftPerSec;
} PE13_CAN;

#define PE14_CAN_ID 0x0CFFFD48
typedef struct __attribute__((__packed__)) PE14_CAN {
  int16_t fuelCompAccel_percent;
  int16_t fuelCompStart_percent;
  int16_t fuelCompAirTemp_percent;
  int16_t fuelCompCoolantTemp_percent;
} PE14_CAN;

#define PE15_CAN_ID 0x0CFFFE48
typedef struct __attribute__((__packed__)) PE15_CAN {
  int16_t fuelCompBarometer_percent;
  int16_t fuelCompMAP_percent;
  uint32_t UNUSED_PAD;
} PE15_CAN;

#define PE16_CAN_ID 0x0CFFD048
typedef struct __attribute__((__packed__)) PE16_CAN {
  int16_t ignitionCompAirTemp_percent;
  int16_t ignitionCompCoolantTemp_percent;
  int16_t ignitionCompBarometer_percent;
  int16_t ignitionCompMAP_percent;
} PE16_CAN;

#endif
