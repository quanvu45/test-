/***************************************************************************//**
 * @file
 * @brief PWM Driver
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
#ifndef SL_PWM_H
#define SL_PWM_H

#include "em_device.h"

#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif

#include "sl_status.h"
#include "sl_enum.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup pwm PWM Driver
 * @brief PWM Driver
 * @{
 * The PWM driver uses one or more TIMER peripherals to generate one or more PWM
 * waveform, with configurable frequency, duty cycle, and polarity. Multiple
 * instances of the driver can be created and allocated to their own TIMER
 * channel.
 *
 * The duty cycle of the PWM waveform can be updated, while the PWM driver is
 * running by calling @ref sl_pwm_set_duty_cycle(), without causing glitches
 * in the output waveform.
 *
 * @note If several PWM driver instances are set up to use the same TIMER
 * instance, the PWM frequency of these instances must be the same.
 * ### PWM Example Code
 *
 * Basic example for generating PWM waveform:
 *
 * ```c
 *
 * #include "sl_pwm.h"
 * #include "sl_gpio.h"
 *
 * int main( void )
 * {
 *
 *   ...
 *
 *   sl_pwm_instance_t sl_pwm_led0 = {
 *     .timer    = TIMER0,
 *     .channel  = 0,
 *     .port     = SL_GPIO_PORT_A,
 *     .pin      = 0,
 *     .location = 0,
 *   };
 *
 *   sl_pwm_config_t pwm_led0_config = {
 *     .frequency = 10000,
 *     .polarity  = PWM_ACTIVE_HIGH,
 *   };
 *
 *   // Initialize PWM
 *   sl_pwm_init(&sl_pwm_led0, &pwm_led0_config);
 *
 *   // Set duty cycle to 40%
 *   sl_pwm_set_duty_cycle(&sl_pwm_led0, 40);
 *
 *   // Enable PWM output
 *   sl_pwm_start(&sl_pwm_led0);
 *
 *   ...
 *
 * }
 * ```
 *
 ******************************************************************************/

/** PWM polarity selection */
SL_ENUM(sl_pwm_polarity_t) {
  /** PWM polarity active high */
  PWM_ACTIVE_HIGH = 0,
  /** PWM polarity active low */
  PWM_ACTIVE_LOW = 1,
};

/**
 * PWM driver instance
 */
typedef struct sl_pwm_instance {
  TIMER_TypeDef *timer; /**< TIMER instance */
  uint8_t channel;      /**< TIMER channel */
  uint8_t port;         /**< GPIO port */
  uint8_t pin;          /**< GPIO pin */
  uint8_t location;     /**< GPIO location */
} sl_pwm_instance_t;

/**
 * PWM driver configuration
 */
typedef struct sl_pwm_config {
  int frequency;              /**< PWM frequency */
  sl_pwm_polarity_t polarity; /**< PWM polarity */
} sl_pwm_config_t;

/**************************************************************************//**
 * @brief
 *   Initialize PWM driver.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @param[in] config
 *   Driver configuration
 *
 * @return
 *   SL_STATUS_OK if there are no errors.
 *****************************************************************************/
sl_status_t sl_pwm_init(sl_pwm_instance_t *pwm, sl_pwm_config_t *config);

/**************************************************************************//**
 * @brief
 *   Deinitialize PWM driver.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @return
 *   SL_STATUS_OK if there are no errors.
 *****************************************************************************/
sl_status_t sl_pwm_deinit(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Start generating PWM waveform
 *
 * @param[in] pwm
 *   PWM driver instance
 *****************************************************************************/
void sl_pwm_start(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Stop generating PWM waveform
 *
 * @param[in] pwm
 *   PWM driver instance
 *****************************************************************************/
void sl_pwm_stop(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Set duty cycle for PWM waveform.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @param[in] percent
 *   Percent of the PWM period waveform is in the state defined
 *   as the active polarity in the driver configuration
 *****************************************************************************/
void sl_pwm_set_duty_cycle(sl_pwm_instance_t *pwm, uint8_t percent);

/**************************************************************************//**
 * @brief
 *   Set duty cycle for PWM waveform.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @return
 *   Percent of the PWM period waveform is in the state defined
 *   as the active polarity in the driver configuration
 *****************************************************************************/
uint8_t sl_pwm_get_duty_cycle(sl_pwm_instance_t *pwm);

/** @} (end addtogroup pwm) */

#ifdef __cplusplus
}
#endif

#endif // SL_PWM_H
