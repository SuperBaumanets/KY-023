/* Includes ------------------------------------------------------------------*/
#include "ky023_val.h"

/**
  * @brief  Read the ADC value changed by the ky023
  * @param  ctx    Component context
  * @param  channel adc channel
  * @retval ADC value
  */
uint32_t KY023_read_adc_val(KY023_ctx_t *ctx, uint8_t channel)
{
    return ctx->ReadADC(ctx->handle, channel);
}

/**
  * @brief  Read the GPIO state
  * @param  ctx    Component context
  * @retval GPIO state
  */
uint8_t KY023_read_gpio_val(KY023_ctx_t *ctx)
{
    return ctx->ReadGPIO(ctx->handle);
}