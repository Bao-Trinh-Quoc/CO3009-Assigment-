/*
 * i2c-lcd.h
 *
 *  Created on: Nov 25, 2024
 *      Author: DELL
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "stm32f1xx_hal.h"
#include "traffic.h"

void LCD_I2C_Write_CMD(uint8_t cmd);
void LCD_I2C_Write_DATA(uint8_t data);
void LCD_I2C_Init();
void LCD_I2C_Clear();
void LCD_I2C_Location(uint8_t x, uint8_t y);
void LCD_I2C_Write_String(char* string);
void LCD_I2C_Write_Number(int number);

void lcd_init_display();
void lcd_auto_display();
void lcd_manual_display();
void lcd_tunning_display();
void lcd_tunning_red();
void lcd_tunning_green();
void lcd_tunning_yellow();

#endif /* INC_I2C_LCD_H_ */
