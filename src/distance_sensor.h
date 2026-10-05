#ifndef MY_SENSOR_H
#define MY_SENSOR_H

#include <stdint.h>

void sensor_init(void);
uint16_t get_distance(void);

#endif // MY_SENSOR_H