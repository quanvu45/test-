/***************************************************************************//**
 * @file
 * @brief app_rgb_led.c
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

// -----------------------------------------------------------------------------
//                                   Includes
// -----------------------------------------------------------------------------

#include <string.h>
#include "app_rgb_led.h"
#include "CC_MultilevelSwitch_Support.h"
#include "sl_component_catalog.h"
#include "assert.h"

#ifdef SL_CATALOG_RGB_LED_PRESENT
#include "sl_simple_rgb_pwm_led.h"
#include "sl_simple_rgb_pwm_led_instances.h"
#else // SL_CATALOG_RGB_LED_PRESENT
#include "sl_pwm.h"
#include "sl_pwm_instances.h"
#endif

// -----------------------------------------------------------------------------
//                              Macros and Typedefs
// -----------------------------------------------------------------------------
//#define DEBUGPRINT
#include "DebugPrint.h"

// -----------------------------------------------------------------------------
//                          Static Function Declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Global Variables
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                                Static Variables
// -----------------------------------------------------------------------------
#define RGBW_LED_ENDPOINT_COUNT  3

static rgb_led_setting rgb_led_attributes[RGBW_LED_ENDPOINT_COUNT];


// -----------------------------------------------------------------------------
//                          Public Functions Declarations
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//                          Public Function Definitions
// -----------------------------------------------------------------------------

/**
 * @brief Gets the color of the RGB LED.
 *
 * This function returns the color of the RGB LED set by app_rgbw_led_set_color.
 *
 * @param color Pointer to an `rgb_led_color` structure where the latest set values
 * will be written to.
 */
void app_rgbw_led_get_color(uint8_t endpoint, rgb_led_color* colorOut)
{
  if (endpoint >= RGBW_LED_ENDPOINT_COUNT || !colorOut) return;
  memcpy(colorOut, &rgb_led_attributes[endpoint].color, sizeof(rgb_led_color));
}

/**
 * @brief Sets the color of the RGB LED.
 *
 * This function sets the color of the RGB LED by updating the internal color attributes.
 *
 * @param color Pointer to an `rgb_led_color` structure containing the new color values.
 */
void app_rgbw_led_set_color(uint8_t endpoint, const rgb_led_color* color)
{
  if (endpoint >= RGBW_LED_ENDPOINT_COUNT || !color) return;
  memcpy(&rgb_led_attributes[endpoint].color, color, sizeof(rgb_led_color));
}
/**
 * @brief Sets the intensity of the RGB LED.
 *
 * This function sets the intensity of the RGB LED by updating the internal intensity attribute.
 *
 * @param intensity The new intensity value to set.
 */
void app_rgbw_led_set_intensity(uint8_t endpoint, uint8_t intensity)
{
  if (endpoint >= RGBW_LED_ENDPOINT_COUNT) return;
  rgb_led_attributes[endpoint].intensity = intensity;
}

/**
 * @brief Updates the RGB LED with the current color and intensity settings.
 *
 * This function applies the current color and intensity settings to the RGB LED.
 * It calculates the appropriate PWM values and sets the LED accordingly.
 */
void app_rgbw_led_update(uint8_t endpoint)
{
  if (endpoint == 0 || endpoint >= RGBW_LED_ENDPOINT_COUNT)
    return;

  rgb_led_setting *attr = &rgb_led_attributes[endpoint];
  uint8_t max_val = cc_multilevel_switch_get_max_value();

#if defined(DEBUGPRINT) && defined(SL_CATALOG_RGB_LED_PRESENT)
  DPRINTF("%s (ep %u) RGB=(%u,%u,%u)\n", __func__, endpoint,
          (attr->color.red   * attr->intensity) / max_val,
          (attr->color.green * attr->intensity) / max_val,
          (attr->color.blue  * attr->intensity) / max_val);
#endif

#ifdef SL_CATALOG_RGB_LED_PRESENT
  if (endpoint == 1) {
    sl_led_set_rgb_color(&sl_simple_rgb_pwm_led_rgb_led0,
                         (uint16_t)((attr->color.red   * attr->intensity) / max_val),
                         (uint16_t)((attr->color.green * attr->intensity) / max_val),
                         (uint16_t)((attr->color.blue  * attr->intensity) / max_val));
  } else if (endpoint == 2) {
    sl_led_set_rgb_color(&sl_simple_rgb_pwm_led_rgb_led1, // hoặc rgb_led1 nếu có
                         (uint16_t)((attr->color.red   * attr->intensity) / max_val),
                         (uint16_t)((attr->color.green * attr->intensity) / max_val),
                         (uint16_t)((attr->color.blue  * attr->intensity) / max_val));
  }
#else
  static bool initialized[RGBW_LED_ENDPOINT_COUNT] = {false};

  if (!initialized[endpoint]) {
    if (endpoint == 1) {
      sl_pwm_start(&sl_pwm_led1); // red
      sl_pwm_start(&sl_pwm_led2); // green
      sl_pwm_start(&sl_pwm_led3); // blue
    } else if (endpoint == 2) {
      sl_pwm_start(&sl_pwm_led4); // red
      sl_pwm_start(&sl_pwm_led5); // green
      sl_pwm_start(&sl_pwm_led6); // blue
    }
    initialized[endpoint] = true;
  }

  uint8_t red   = ((attr->color.red   * attr->intensity * 100) / (max_val * 255));
  uint8_t green = ((attr->color.green * attr->intensity * 100) / (max_val * 255));
  uint8_t blue  = ((attr->color.blue  * attr->intensity * 100) / (max_val * 255));

  if (endpoint == 1) {
    sl_pwm_set_duty_cycle(&sl_pwm_led1, 100-red);
    sl_pwm_set_duty_cycle(&sl_pwm_led2, 100-green);
    sl_pwm_set_duty_cycle(&sl_pwm_led3, 100-blue);
  } else if (endpoint == 2) {
    sl_pwm_set_duty_cycle(&sl_pwm_led4, red);
    sl_pwm_set_duty_cycle(&sl_pwm_led5, green);
    sl_pwm_set_duty_cycle(&sl_pwm_led6, blue);
  }
#endif
}
