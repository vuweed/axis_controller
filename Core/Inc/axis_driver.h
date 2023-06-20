/*
 * axis_driver.h
 *
 *  Created on: Jun 20, 2023
 *      Author: ADMIN
 */

#ifndef INC_AXIS_DRIVER_H_
#define INC_AXIS_DRIVER_H_
#include "main.h"

typedef struct
{
    uint16_t pwm;
    uint16_t angle;
    uint32_t desired_value;
}M_axis_t;









#endif /* INC_AXIS_DRIVER_H_ */
