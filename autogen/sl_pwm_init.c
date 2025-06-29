/***************************************************************************//**
 * @file
 * @brief PWM Driver Instance Initialization
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

#include "sl_pwm.h"

#include "sl_pwm_init_led1_config.h"

#include "sl_pwm_init_led2_config.h"

#include "sl_pwm_init_led3_config.h"

#include "sl_pwm_init_led4_config.h"

#include "sl_pwm_init_led5_config.h"

#include "sl_pwm_init_led6_config.h"


#include "sl_gpio.h"


sl_pwm_instance_t sl_pwm_led1 = {
  .timer = SL_PWM_LED1_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED1_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED1_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED1_OUTPUT_PIN),
#if defined(SL_PWM_LED1_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED1_OUTPUT_LOC),
#endif
};

sl_pwm_instance_t sl_pwm_led2 = {
  .timer = SL_PWM_LED2_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED2_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED2_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED2_OUTPUT_PIN),
#if defined(SL_PWM_LED2_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED2_OUTPUT_LOC),
#endif
};

sl_pwm_instance_t sl_pwm_led3 = {
  .timer = SL_PWM_LED3_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED3_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED3_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED3_OUTPUT_PIN),
#if defined(SL_PWM_LED3_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED3_OUTPUT_LOC),
#endif
};

sl_pwm_instance_t sl_pwm_led4 = {
  .timer = SL_PWM_LED4_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED4_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED4_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED4_OUTPUT_PIN),
#if defined(SL_PWM_LED4_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED4_OUTPUT_LOC),
#endif
};

sl_pwm_instance_t sl_pwm_led5 = {
  .timer = SL_PWM_LED5_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED5_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED5_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED5_OUTPUT_PIN),
#if defined(SL_PWM_LED5_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED5_OUTPUT_LOC),
#endif
};

sl_pwm_instance_t sl_pwm_led6 = {
  .timer = SL_PWM_LED6_PERIPHERAL,
  .channel = (uint8_t)(SL_PWM_LED6_OUTPUT_CHANNEL),
  .port = (uint8_t)(SL_PWM_LED6_OUTPUT_PORT),
  .pin = (uint8_t)(SL_PWM_LED6_OUTPUT_PIN),
#if defined(SL_PWM_LED6_OUTPUT_LOC)
  .location = (uint8_t)(SL_PWM_LED6_OUTPUT_LOC),
#endif
};


void sl_pwm_init_instances(void)
{

  sl_pwm_config_t pwm_led1_config = {
    .frequency = SL_PWM_LED1_FREQUENCY,
    .polarity = SL_PWM_LED1_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led1, &pwm_led1_config);

  sl_pwm_config_t pwm_led2_config = {
    .frequency = SL_PWM_LED2_FREQUENCY,
    .polarity = SL_PWM_LED2_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led2, &pwm_led2_config);

  sl_pwm_config_t pwm_led3_config = {
    .frequency = SL_PWM_LED3_FREQUENCY,
    .polarity = SL_PWM_LED3_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led3, &pwm_led3_config);

  sl_pwm_config_t pwm_led4_config = {
    .frequency = SL_PWM_LED4_FREQUENCY,
    .polarity = SL_PWM_LED4_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led4, &pwm_led4_config);

  sl_pwm_config_t pwm_led5_config = {
    .frequency = SL_PWM_LED5_FREQUENCY,
    .polarity = SL_PWM_LED5_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led5, &pwm_led5_config);

  sl_pwm_config_t pwm_led6_config = {
    .frequency = SL_PWM_LED6_FREQUENCY,
    .polarity = SL_PWM_LED6_POLARITY,
  };

  sl_pwm_init(&sl_pwm_led6, &pwm_led6_config);

}
