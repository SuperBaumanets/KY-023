/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KY023_VAL_H
#define KY023_VAL_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
  
/** @defgroup KY023_VAL_Exported_Types Exported Types
  * @{
  */ 
typedef uint32_t (*KY023_ReadADC_Func)  (void*, uint8_t);
typedef uint8_t  (*KY023_ReadGPIO_Func) (void*);

typedef struct
{
  KY023_ReadADC_Func   ReadADC;
  KY023_ReadGPIO_Func  ReadGPIO;
  void                 *handle;
} KY023_ctx_t;
/**
 * @}
 */


/** @defgroup KY023_VAL_Exported_Functions Exported Functions
  * @{
  */ 
uint32_t KY023_read_adc_val(KY023_ctx_t *ctx, uint8_t channel);
uint8_t KY023_read_gpio_val(KY023_ctx_t *ctx);
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* KY023_VAL_H */