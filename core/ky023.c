/* Includes ------------------------------------------------------------------*/
#include "ky023.h"

/** @defgroup KY023_Private_Types Private Types
 * @{
 */
typedef struct {
  uint32_t valVRX;
  uint32_t valVRY;
  KY023_SW_Event_t swEvent;
} KY023_Ctx_t;
/**
 * @}
 */