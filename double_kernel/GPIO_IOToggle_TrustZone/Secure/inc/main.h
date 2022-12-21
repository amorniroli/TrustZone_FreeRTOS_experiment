#include "stm32u5xx.h"

#define LED1_Pin 		GPIO_PIN_7
#define LED1_GPIO_Port  GPIOC
#define LED2_Pin 		GPIO_PIN_7
#define LED2_GPIO_Port  GPIOB
#define LED3_Pin 		GPIO_PIN_0 //should be 2 but pin is burnt -> jumper between pin0/pin2
#define LED3_GPIO_Port  GPIOG
