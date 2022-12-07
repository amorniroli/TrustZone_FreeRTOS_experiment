#include <assert.h>

#include "stm32u5xx.h"

#include "FreeRTOS.h"
#include "task.h"

#include "secure_nsc.h"

int
main (void)
{
	/* Set Interrupt Group Priority */
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	/* Update the SystemCoreClock global variable */
	SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR2 & RCC_CFGR2_HPRE) >> RCC_CFGR2_HPRE_Pos];

	/* Start non-secure domain FreeRTOS! */
	vTaskStartScheduler ();

	/* Should never get herre! */
	assert (0);
}

static void
nsThread (void* ptrArg)
{
    (void) ptrArg;

    while (1)
    {
    	vTaskDelay (10);

    	SECURE_ToggleLed2 ();
    }
}

void
vApplicationStackOverflowHook (TaskHandle_t xTask, char * pcTaskName)
{
	assert (0);
}

void
vApplicationDaemonTaskStartupHook (void)
{
	xTaskCreate ((TaskFunction_t)nsThread, "nonSecureThread", 1024, NULL, 20, NULL);
}

void
__wrap___assert_func (const char* ptrFileName, int line, const char* ptrFuncName, const char* ptrExpression)
{
	while (1)
	{
		;
	}
}
