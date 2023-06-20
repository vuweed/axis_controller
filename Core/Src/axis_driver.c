/*
 * axis_driver.c
 *
 *  Created on: Jun 20, 2023
 *      Author: ADMIN
 */

#include "axis_driver.h"

ret_val_t pwm_handler(TIM_HandleTypeDef *htim, M_axis_t *axis, uint8_t axis_num, uint16_t encoder_val)
{
    uint8_t ret_val = ERR;
    uint16_t axis_pin_num = 0;
    axis->desired_value = (uint32_t)(axis->angle * ANGLE_CONVERT_VAL);
    /*PWM*/
    switch (axis_num) {
        case 1:
            axis_pin_num = GPIO_PIN_3;
            break;
        case 2:
            axis_pin_num = GPIO_PIN_4;
            break;
        case 3:
            axis_pin_num = GPIO_PIN_5;
            break;
        case 4:
            axis_pin_num = GPIO_PIN_13;
            break;
        default:
            break;
    }
    /*1300 ~ 360 degree*/
    if (axis->desired_value != 0)
    {
        if(encoder_val > (axis->desired_value - CALIB_VAL))
        {
            HAL_GPIO_WritePin(GPIOB,axis_pin_num, RESET);
            axis->desired_value = 0;
            axis->angle = 0;
            __HAL_TIM_SET_COUNTER(htim, 0);
            ret_val = SUCCESSFUL;
        }
        else
        {
            HAL_GPIO_WritePin(GPIOB,axis_pin_num, SET);
        }
    }
    return ret_val;
}

