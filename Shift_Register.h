#ifndef _SHIFT_REGISTER_H_
#define _SHIFT_REGISTER_H_

#define   SHIFT_REGISTER_SER_PORT    GPIOC
#define   SHIFT_REGISTER_SCLK_PORT   GPIOC
#define   SHIFT_REGISTER_RCLK_PORT   GPIOC

#define   SHIFT_REGISTER_SER_PIN    GPIO_PIN_11
#define   SHIFT_REGISTER_SCLK_PIN   GPIO_PIN_12
#define   SHIFT_REGISTER_RCLK_PIN   GPIO_PIN_13

void Shift_Register_Config(void);
void Reset_Shift_Register(void);      
void Update_Shift_Register(void);

#endif
