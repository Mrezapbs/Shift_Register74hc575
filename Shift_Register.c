#include "Shift_Register.h"
void Shift_Register_Config(void)				
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIO_InitStruct.Pin = SHIFT_REGISTER_SER_PIN|SHIFT_REGISTER_SCLK_PIN|SHIFT_REGISTER_RCLK_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void Reset_Shift_Register(void)                    
{
	Shift_Register_Config();
	HAL_GPIO_WritePin(SHIFT_REGISTER_SER_PORT, SHIFT_REGISTER_SER_PIN, RESET); 	//setting SERIAL to Low
	for(uint8_t LoopSize = 8 ; LoopSize > 0 ; LoopSize--)
	{
		HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT, SHIFT_REGISTER_SCLK_PIN, SET);             //setting Clock to 1
		HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT, SHIFT_REGISTER_SCLK_PIN, RESET);           //setting Clock to 0  
	}
	HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT, SHIFT_REGISTER_RCLK_PIN, SET);               // Printing data as output
	HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT, SHIFT_REGISTER_RCLK_PIN, RESET);
}


void Update_Shift_Register(void)               
{
	if (DesiredOutput != DesiredOutputPreviousValue)  
	{ 
		for(uint8_t LoopSize = 8 ; LoopSize > 0 ; LoopSize--)
		{
			if ((DesiredOutput & (1<<(LoopSize-1)) == 0)      
			{
				HAL_GPIO_WritePin(SHIFT_REGISTER_SER_PORT, SHIFT_REGISTER_SER_PIN, RESET);     //setting SERIAL to Low
			}  
			else
			{
				HAL_GPIO_WritePin(SHIFT_REGISTER_SER_PORT, SHIFT_REGISTER_SER_PIN, SET);       //setting SERIAL to high 
			}		
			HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT, SHIFT_REGISTER_SCLK_PIN, SET);             //setting Clock to 1
			HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT, SHIFT_REGISTER_SCLK_PIN, RESET);           //setting Clock to 0  
		}
		HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT, SHIFT_REGISTER_RCLK_PIN, SET);               // Printing data as output
		HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT, SHIFT_REGISTER_RCLK_PIN, RESET);
		DesiredOutputPreviousValue = DesiredOutput;
	}
}
