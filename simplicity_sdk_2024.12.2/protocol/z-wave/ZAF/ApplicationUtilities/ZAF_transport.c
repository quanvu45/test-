/**
 * @file ZAF_transport.c
 * @brief Various transport functionality in the Z-Wave Framework.
 * @copyright 2021 Silicon Laboratories Inc.
 */

/****************************************************************************/
/*                              INCLUDE FILES                               */
/****************************************************************************/

#include <assert.h>
#include <ZAF_Common_interface.h>

//#define DEBUGPRINT
#include "DebugPrint.h"

bool
ZAF_transportSendDataAbort(void)
{
  SZwaveCommandPackage CommandPackage = {
    .eCommandType = EZWAVECOMMANDTYPE_SEND_DATA_ABORT
  };

  DPRINT("\nSendDataAbort\n");

  EQueueNotifyingStatus Status = QueueNotifyingSendToBack(ZAF_getAppHandle()->pZwCommandQueue, (uint8_t*)&CommandPackage, 500);
  assert(EQUEUENOTIFYING_STATUS_SUCCESS == Status);
  return (EQUEUENOTIFYING_STATUS_SUCCESS == Status);
}
