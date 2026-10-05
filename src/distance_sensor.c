/***************************************************************
* FILENAME: distance_sensor.c
* DESCRIPTION: This program creates an interface with the PSK-CM8JL65-CC5 Infrared Distance Measuring Sensor.
* AUTHOR: Owen Ringrose
* DATE: 10/3/2026
****************************************************************/

#include <stdio.h>
#include <stdint.h>

#include "driver/uart.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define UART_PORT UART_NUM_2
#define TXD2 GPIO_NUM_17
#define RXD2 GPIO_NUM_16


void sensor_init(void)
{
    uart_config_t uart_config = 
    {
        .baud_rate = 115200,
            .data_bits = UART_DATA_8_BITS,
            .parity = UART_PARITY_DISABLE,
            .stop_bits = UART_STOP_BITS_1,
            .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
            .source_clk = UART_SCLK_DEFAULT
        };

        uart_param_config(UART_PORT, &uart_config);

        uart_set_pin(
            UART_PORT,
            TXD2,
            RXD2,
            UART_PIN_NO_CHANGE,
            UART_PIN_NO_CHANGE
        );

        uart_driver_install(
            UART_PORT,
            1024,   // RX buffer size
            0,      // TX buffer size
            0,      // event queue size
            NULL,
            0
        );
    
}
uint16_t get_distance(void)
{
    static uint8_t buffer[6];
    int index = 0;
    while (index < 6){
        // int uart_read_bytes(uart_port_t uart_num, void* buf, uint32_t length, uint32_t ticks_to_wait);
        int bytes_read = uart_read_bytes(UART_PORT, &buffer, 6 - index, pdMS_TO_TICKS(20));
        index += bytes_read;
    }
    uint16_t distance = ((uint16_t)buffer[2] << 8) |buffer[3]; 
    return distance;
}
