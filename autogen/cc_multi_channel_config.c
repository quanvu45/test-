/**
 * @file
 * Auto-generated configuration file for Command Class Multi Channel.
 *
 * This file defines the number of endpoints in a multi channel device and the generic type and
 * specific type for each endpoint.
 *
 * @copyright 2023 Silicon Laboratories Inc.
 */
#include "cc_multi_channel_config_api.h"
#include "ZW_classcmd.h"
#include <assert.h>
#include "SizeOf.h"

/*
 * This array must be sorted by endpoint. The Z-Wave Command Class Configurator (Z3C) will sort
 * the array, but if modified manually after generation, make sure to keep it sorted by endpoint.
 */
static const cc_multi_channel_config_t endpoints[] = {
  {
    // Endpoint 1
    .generic_type  = GENERIC_TYPE_SWITCH_MULTILEVEL,
    .specific_type = SPECIFIC_TYPE_COLOR_TUNABLE_MULTILEVEL
  },
  {
    // Endpoint 2
    .generic_type  = GENERIC_TYPE_SWITCH_MULTILEVEL,
    .specific_type = SPECIFIC_TYPE_COLOR_TUNABLE_MULTILEVEL
  },
};

cc_multi_channel_config_t const * cc_multi_channel_get_config(void)
{
  return endpoints;
}

cc_multi_channel_config_t const * cc_multi_channel_get_config_endpoint(uint8_t endpoint)
{
  assert(sizeof_array(endpoints) > 0);
  assert(endpoint <= sizeof_array(endpoints));
  /*
   * CC:0060.03.00.21.004: For backwards compatibility, the Root Device MUST
   * mirror the application functionality of End Point 1.
   */
  if (endpoint == 0) {
    return &endpoints[0];
  } else {
    return &endpoints[endpoint - 1];
  }
}
