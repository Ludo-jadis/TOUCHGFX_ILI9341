#include "IR_RC5.h"
#include "stm32f7xx_hal.h"

/**
 * @brief  Initializes DWT_Clock_Cycle_Count for DWT_Delay_us function
 * @return Error DWT counter
 *         1: clock cycle counter not started
 *         0: clock cycle counter works
 */
 
 	uint16_t code ;
	uint16_t volume = 0;
	uint16_t old_volume = 0;
	int i = 0;
	uint32_t clk_cycle_start = 0 ;
	int detection =0;
	uint32_t microseconds;
	uint32_t cycle_micro=0;
	

 
uint16_t IR_RC5_Init(void) {
	
	  /* Disable TRC */
  CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk; // ~0x01000000;
  /* Enable TRC */
  CoreDebug->DEMCR |=  CoreDebug_DEMCR_TRCENA_Msk; // 0x01000000;
	DWT->LAR = 0xC5ACCE55;
	  /* Reset the clock cycle counter value */
  DWT->CYCCNT = 0;
	
  /* Disable clock cycle counter */
  DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk; //~0x00000001;
  /* Enable  clock cycle counter */
  DWT->CTRL |=  DWT_CTRL_CYCCNTENA_Msk; //0x00000001;



     /* 3 NO OPERATION instructions */
     __ASM volatile ("NOP");
     __ASM volatile ("NOP");
  __ASM volatile ("NOP");	
	
	microseconds = 1500; //1500 en debug 
		microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);
    return 1; 
  
}


uint16_t Decode_RC5(void)
{
		cycle_micro = (DWT->CYCCNT - clk_cycle_start);
		if ( (i == 14) || cycle_micro > 10821920)
		{
			i = 0;
			old_volume = volume;
			if( code == 0x2FBC || code == 0x0FBC)
				{
					volume++;
				}else if(code == 0x2FB8 || code == 0x0FB8)
					{
						volume--;				
					}
				
			for (int i2=0; i2<15; i2++)
			{
				code &= ~(1UL << (15-i2));
			}
		}
		
		if ( cycle_micro > microseconds)
		{	
			DWT->CYCCNT = 0;
			clk_cycle_start =0;
			detection = 0;
		}
		if ((detection == 0 ) & (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 1 ))
	{	
		code |= (1UL << (15-i)); // write 1
		i++;
		detection = 1;
		clk_cycle_start = DWT->CYCCNT;
	}
	
	if ((detection == 0 ) & (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) == 0 ))
	{
		code &= ~(1UL << (15-i)); // write 0
		i++;
		detection = 1;
		clk_cycle_start = DWT->CYCCNT;
	}
	if (volume > 100 )
	{
		volume = 100;
	}
	if((volume < 0) || ((volume - old_volume)> 5) )
		{
			volume = 0;
		}
return volume;
}

