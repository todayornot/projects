#include "stm32f10x.h"                  // Device header
#include "MyI2C.h"


#define MLX90614_ADDRESS 0x5A<<1

uint16_t Data=0;

uint16_t MLX90614_ReadReg(uint8_t RegAddress)
{
	
	uint8_t Pec;
	//uint8_t arr[6];
	
	MyI2C_Start();
	MyI2C_SendByte(MLX90614_ADDRESS);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(RegAddress);
	MyI2C_ReceiveAck();
	
	MyI2C_Start();
	MyI2C_SendByte(MLX90614_ADDRESS|0x01);
	MyI2C_ReceiveAck();
	Data=MyI2C_ReceiveByte();
	MyI2C_SendAck(1);
	Data|=MyI2C_ReceiveByte()<<8;
	MyI2C_SendAck(1);
	Pec=MyI2C_ReceiveByte();
	MyI2C_SendAck(1);
	MyI2C_Stop();
	
	return Data;
}

float MLX90614_ReadTemp(void)
{
	float temp;
	temp=MLX90614_ReadReg(0x07)*0.02-273.15;
	return temp;
}

void MLX90614_Init(void)
{
	MyI2C_Init();
}

uint16_t MLX90614_GetData(void)
{
	return Data;
}
