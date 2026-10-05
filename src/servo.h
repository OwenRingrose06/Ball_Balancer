#ifndef MY_SERVO_H
#define MY_SERVO_H
#include <stdint.h>

void servo_init(void);
void servo_set_angle(uint8_t angle);
uint8_t servo_get_angle(void);

#endif // MY_SENSOR_H