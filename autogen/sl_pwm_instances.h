/***************************************************************************//**
 * @file
 * @brief PWM Driver Instances
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SL_PWM_INSTANCES_H
#define SL_PWM_INSTANCES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sl_pwm.h"


extern sl_pwm_instance_t sl_pwm_led1;
extern sl_pwm_instance_t sl_pwm_led2;
extern sl_pwm_instance_t sl_pwm_led3;
extern sl_pwm_instance_t sl_pwm_led4;
extern sl_pwm_instance_t sl_pwm_led5;
extern sl_pwm_instance_t sl_pwm_led6;

void sl_pwm_init_instances(void);

#ifdef __cplusplus
}
#endif

#endif // SL_PWM_INSTANCES_H
