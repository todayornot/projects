#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MLX90614.h"

int main(void)
{
	float temp=0;
	uint16_t Data;
	OLED_Init();
	MLX90614_Init();
	
	
	
	while(1)
	{
		temp=MLX90614_ReadTemp();
		Data=MLX90614_GetData();
		OLED_ShowBinNum(1,1,Data,8);
		OLED_ShowFNum(2,1,temp,8,3);
		Delay_us(20);
	}
}
