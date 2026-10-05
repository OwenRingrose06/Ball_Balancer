#include "iot_servo.h"

void servo_init(void)
{
    servo_handle_t servo = NULL;
    servo_config_t cfg = SERVO_CONFIG_DEFAULT(LEDC_LOW_SPEED_MODE, LEDC_TIMER_0, LEDC_CHANNEL_0, GPIO_NUM_18);

    iot_servo_new(&cfg, &servo);
}