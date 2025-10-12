/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KY023_H
#define KY023_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>
#include "ky023_val.h"

/** @defgroup KY023_Exported_Types Exported Types
  * @{
  */
typedef int32_t  (*KY023_Init_Func)         (void);
typedef int32_t  (*KY023_DeInit_Func)       (void);
typedef uint32_t (*KY023_ReadValADC_Func)   (uint8_t);
typedef uint8_t  (*KY023_ReadValGPIO_Func)  (void);

typedef struct
{
  KY023_Init_Func          Init;
  KY023_DeInit_Func        DeInit;
  KY023_ReadValADC_Func    ReadValADC;
  KY023_ReadValGPIO_Func   ReadValPin;
} KY023_IO_t;

 
typedef struct
{
  KY023_IO_t           IO;
  KY023_ctx_t          Ctx;
  uint32_t             ResolutionADC; // TODO: delete
} KY023_Object_t;
/**
 * @}
 */

/** 
  * @brief  KY023 SW Event  
  */  
typedef enum  
{
  KY023_SW_NotPress,      // KY023 SW not press
  KY023_SW_Press,     		// KY023 SW press
  KY023_SW_ShortPress,		// KY023 SW short press
  KY023_SW_LongPress,  		// KY023 SW long press
}KY023_SW_Event_t;
/**
 * @}
 */
  
/** @defgroup KY023_Exported_Functions Exported Functions
  * @{
  */ 
int32_t           KY023_RegisterBusIO (KY023_Object_t *pObj, KY023_IO_t *pIO);
int32_t           KY023_Init(KY023_Object_t *pObj);
uint32_t          KY023_GetValVRX(KY023_Object_t* pObj);
uint32_t          KY023_GetValVRY(KY023_Object_t* pObj);
int32_t           KY023_SetExtremeValVRX(KY023_Object_t*, uint32_t minVRX, uint32_t maxVRX);
int32_t           KY023_SetExtremeValVRY(KY023_Object_t*, uint32_t minVRY, uint32_t maxVRY);
KY023_SW_Event_t  KY023_GetEventSW(KY023_Object_t* pObj);
int32_t           KY023_DeInit(KY023_Object_t* pObj);

void              KY023_UpdateButton(KY023_Object_t* pObj); 
void              KY023_UpdateValVRXVRY(KY023_Object_t* pObj);
/**
 * @}
 */
      
#ifdef __cplusplus
}
#endif

#endif /* KY023_H */