#include <stdio.h>
#include <stdint.h>

#include "driver/uart.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "distance_sensor.h"

#define UART_PORT UART_NUM_2
#define TXD2 GPIO_NUM_17
#define RXD2 GPIO_NUM_16


uint16_t distance;

void app_main(void)
{
    sensor_init();
    while(1)
    {
        distance = get_distance();
        printf(">distance:%d\n", distance);
    }
}