#include "secure_nsc.h"

#include "stm32u5xx.h"

#define CMSE_NS_ENTRY __attribute((cmse_nonsecure_entry))

CMSE_NS_ENTRY void
SECURE_ToggleLed2 (void)
{
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
}
