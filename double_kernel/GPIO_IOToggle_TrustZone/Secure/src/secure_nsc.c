#include <assert.h>
#include <stdint.h>

#include "secure_nsc.h"

#include "main.h"

#include "stm32u5xx.h"

#include "FreeRTOS.h"
#include "task.h"

#define CMSE_NS_ENTRY __attribute((cmse_nonsecure_entry))

static void
SECURE_assert (void)
{
	extern TaskHandle_t nsEntryThreadHandle;

    TaskHandle_t handle;

    /* Get current handle in execution. */
    handle = xTaskGetCurrentTaskHandle ();

    /* Coming from non secure domain? */
    assert (nsEntryThreadHandle == handle);
}

CMSE_NS_ENTRY void
SECURE_ToggleLed2 (void)
{
	SECURE_assert ();

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}

CMSE_NS_ENTRY void
SECURE_ToggleLed3 (void)
{
	SECURE_assert ();

	HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
}
