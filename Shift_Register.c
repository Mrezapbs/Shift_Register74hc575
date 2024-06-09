void Update_Shift_Register(void)               
{
	if (DesiredOutput != DesiredOutputPreviousValue)  
	{ 
		for(uint8_t LoopSize = 8 ; LoopSize > 0 ; LoopSize--)
		{
			if ((DesiredOutput & BV(LoopSize-1) ) == 0)      
			{
        HAL_GPIO_WritePin(SHIFT_REGISTER_SER_PORT_PORT, SHIFT_REGISTER_SER_PORT_PIN, RESET); 			     //setting SERIAL to Low
			}  
			else
			{
				HAL_GPIO_WritePin(SHIFT_REGISTER_SER_PORT_PORT, SHIFT_REGISTER_SER_PORT_PIN, SET);             //setting SERIAL to high 
			}		
      HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT_PORT, SHIFT_REGISTER_SCLK_PORT_PIN, SET);             //setting Clock to 1
      HAL_GPIO_WritePin(SHIFT_REGISTER_SCLK_PORT_PORT, SHIFT_REGISTER_SCLK_PORT_PIN, RESET);           //setting Clock to 0  
		}
    HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT_PORT, SHIFT_REGISTER_RCLK_PORT_PIN, SET);               // Printing data as output
    HAL_GPIO_WritePin(SHIFT_REGISTER_RCLK_PORT_PORT, SHIFT_REGISTER_RCLK_PORT_PIN, RESET);
		DesiredOutputPreviousValue = DesiredOutput;
	}
}
