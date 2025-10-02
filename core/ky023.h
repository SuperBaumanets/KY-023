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
typedef int32_t  (*KY023_Init_Func)     (void);
typedef int32_t  (*KY023_DeInit_Func)   (void);
typedef uint32_t (*KY023_ReadADC_Func)  (uint8_t);
typedef uint8_t  (*KY023_ReadGPIO_Func) (void);

typedef struct
{
  KY023_Init_Func          Init;
  KY023_DeInit_Func        DeInit;
  KY023_ReadADC_Func       ReadADC;
  KY023_ReadGPIO_Func      ReadPin;
} KY023_IO_t;

 
typedef struct
{
  KY023_IO_t           IO;
  KY023_ctx_t          Ctx;
  uint32_t             ResolutionADC;
} KY023_Object_t;

typedef struct
{
  /* Control functions */
  int32_t   (*Init                )(KY023_Object_t*);
  uint32_t  (*GetValVRX           )(KY023_Object_t*);
  uint32_t  (*GetValVRY           )(KY023_Object_t*);
  int32_t   (*SetExtremeValVRX    )(KY023_Object_t*, uint32_t minVRX, uint32_t maxVRX);
  int32_t   (*SetExtremeValVRY    )(KY023_Object_t*, uint32_t minVRY, uint32_t maxVRY);
  int8_t    (*GetEventSW          )(KY023_Object_t*);
  int32_t   (*DeInit              )(KY023_Object_t*);

  /* Update functions*/
  void  (*UpdateButton    ) (KY023_Object_t*); 
  void  (*UpdateADC       ) (KY023_Object_t*);
}KY023_Drv_t;
/**
 * @}
 */

/** 
  * @brief  ST7735S Status  
  */  
#define ST7735S_OK                (0)
#define ST7735S_ERROR             (-1)
/**
 * @}
 */

/** 
  * @brief  ST7735S Size  
  */  
#define  ST7735S_WIDTH           128U
#define  ST7735S_HEIGHT          160U
/**
 * @}
 */
  
/** @defgroup ST7735S_Exported_Functions Exported Functions
  * @{
  */ 
int32_t  KY023_RegisterBusIO (KY023_Object_t *pObj, KY023_IO_t *pIO);
int32_t  KY023_Init(KY023_Object_t *pObj);
uint32_t KY023_GetValVRX(KY023_Object_t*);
uint32_t KY023_GetValVRY(KY023_Object_t*);
int32_t  KY023_SetExtremeValVRX(KY023_Object_t*, uint32_t minVRX, uint32_t maxVRX);
int32_t  KY023_SetExtremeValVRY(KY023_Object_t*, uint32_t minVRY, uint32_t maxVRY);
int8_t   KY023_GetEventSW(KY023_Object_t*);
int32_t  KY023_DeInit(KY023_Object_t*);

void     KY023_UpdateButton(KY023_Object_t*); 
void     KY023_UpdateADC(KY023_Object_t*);
/**
 * @}
 */


/** @defgroup ST7735S_Exported_Variable Exported Variable
  * @{
  */ 
extern KY023_Drv_t   KY023_Driver;
/**
 * @}
 */
      
#ifdef __cplusplus
}
#endif

#endif /* KY023_H */