/*
 * i2c-lcd.c
 *
 *  Created on: Nov 25, 2024
 *      Author: DELL
 */

#include "i2c-lcd.h"
#include <string.h>
#include <stdio.h>
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define addr_pcf8574 0x21<<1

void LCD_I2C_Write_CMD(uint8_t cmd)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (cmd & 0xF0);
    data_l = ((cmd << 4) & 0xF0);

    data_t[0] = data_u | 0x0C;  // EN=1, RS=0
    data_t[1] = data_u | 0x08;  // EN=0, RS=0
    data_t[2] = data_l | 0x0C;  // EN=1, RS=0
    data_t[3] = data_l | 0x08;  // EN=0, RS=0

    HAL_I2C_Master_Transmit(&hi2c1, addr_pcf8574, data_t, 4, HAL_MAX_DELAY);
}

void LCD_I2C_Write_DATA(uint8_t data)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = (data & 0xF0);
    data_l = ((data << 4) & 0xF0);

    data_t[0] = data_u | 0x0D;  // EN=1, RS=1
    data_t[1] = data_u | 0x09;  // EN=0, RS=1
    data_t[2] = data_l | 0x0D;  // EN=1, RS=1
    data_t[3] = data_l | 0x09;  // EN=0, RS=1

    HAL_I2C_Master_Transmit(&hi2c1, addr_pcf8574, data_t, 4, HAL_MAX_DELAY);
}
void LCD_I2C_Init()
{
	LCD_I2C_Write_CMD(0x33);
	LCD_I2C_Write_CMD(0x32);
	HAL_Delay(50);
	LCD_I2C_Write_CMD(0x28);
	HAL_Delay(50);
	LCD_I2C_Write_CMD(0x01);
	HAL_Delay(50);
	LCD_I2C_Write_CMD(0x06);
	HAL_Delay(50);
	LCD_I2C_Write_CMD(0x0C);
	HAL_Delay(50);
	LCD_I2C_Write_CMD (0x02); /* move cursor to home and set data address to 0 */
	HAL_Delay(50);
	LCD_I2C_Write_CMD (0x80);

}
void LCD_I2C_Clear()
{
	LCD_I2C_Write_CMD(0x01);
	HAL_Delay(50);
}
void LCD_I2C_Location(uint8_t x, uint8_t y)
{
	if(x==0)
	{
		LCD_I2C_Write_CMD(0x80+y);
	}
	else if(x==1)
	{
		LCD_I2C_Write_CMD(0xC0+y);
	}
}
void LCD_I2C_Write_String(char* string)
{
	for(uint8_t i=0;i<strlen(string); i++)
	{
		LCD_I2C_Write_DATA(string[i]);
	}
}
void LCD_I2C_Write_Number(int number)
{
	char buffer[8];
    sprintf(buffer,"%d",number);
    LCD_I2C_Write_String(buffer);
}

void lcd_init_display() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 2);
	LCD_I2C_Write_String("TRAFFIC LIGHT");
	LCD_I2C_Location(1, 5);
	LCD_I2C_Write_String("SYSTEM");
}

void lcd_auto_display() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 0);
	LCD_I2C_Write_String("TRAFFIC1: ");
	LCD_I2C_Location(0, 11);
	LCD_I2C_Write_Number(trafficCounters[0]/1000);
	LCD_I2C_Location(1, 0);
	LCD_I2C_Write_String("TRAFFIC2: ");
	LCD_I2C_Location(1, 11);
	LCD_I2C_Write_Number(trafficCounters[1]/1000);
}

void lcd_manual_display() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 0);
	LCD_I2C_Write_String("MANUAL MODE");
}

void lcd_tunning_display() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 2);
	LCD_I2C_Write_String("TUNNING MODE");
}

void lcd_tunning_red() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 0);
	LCD_I2C_Write_String("TUNNING MODE");
	LCD_I2C_Location(1, 0);
	LCD_I2C_Write_String("RED: ");
	LCD_I2C_Location(1, 6);
	LCD_I2C_Write_Number(trafficRedDuration / 1000);
}
void lcd_tunning_green() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 0);
	LCD_I2C_Write_String("TUNNING MODE");
	LCD_I2C_Location(1, 0);
	LCD_I2C_Write_String("GREEN: ");
	LCD_I2C_Location(1, 8);
	LCD_I2C_Write_Number(trafficGreenDuration/ 1000);
}
void lcd_tunning_yellow() {
	LCD_I2C_Clear();
	LCD_I2C_Location(0, 0);
	LCD_I2C_Write_String("TUNNING MODE");
	LCD_I2C_Location(1, 0);
	LCD_I2C_Write_String("YELLOW: ");
	LCD_I2C_Location(1, 9);
	LCD_I2C_Write_Number(trafficYellowDuration / 1000);
}
