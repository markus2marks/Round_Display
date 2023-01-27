/*
 * st7701s.h
 *
 *  Created on: 26.01.2023
 *      Author: Markus
 */

#ifndef ST7701S_H_
#define ST7701S_H_

#include "mbed.h"


#define ENABLE_SPI *m_cs = 0
#define DISABLE_SPI *m_cs = 1

#define ST7701S_CMD_SWRESET  0x01  // Software reset command
#define ST7701S_CMD_SLEEP_OUT 0x11  // Sleep out command
#define ST7701S_CMD_DISP_ON  0x29  // Display on command
#define ST7701S_CMD_SET_COLUMN_ADDRESS 0x2A  // Set column address command
#define ST7701S_CMD_SET_PAGE_ADDRESS 0x2B  // Set page address command
#define ST7701S_CMD_RAM_WRITE  0x2C  // RAM write command
#define ST7701S_CMD_SET_GAMMA_CURVE   0x26   // set gamma curve command
#define ST7701S_CMD_SET_DISPLAY_OFF   0x28   // set display off command
#define ST7701S_CMD_SET_DISPLAY_CLOCK_DIV 0xB3 // set display clock divide command
#define ST7701S_CMD_SET_DISPLAY_OFFSET 0xD3  // set display offset command
#define ST7701S_CMD_SET_PARTIAL_AREA  0x30   // set partial area command
#define ST7701S_CMD_SET_TEAR_OFF   0x34   // set tear off command
#define ST7701S_CMD_SET_ADDRESS_MODE 0x36  // set address mode command
#define ST7701S_CMD_SET_SCROLL_START 0x37  // set scroll start command
#define ST7701S_CMD_SET_PIXEL_FORMAT   0x3A  // set pixel format command
#define ST7701S_CMD_SET_EXIT_SLEEP_MODE 0x11 // set exit sleep mode command
#define ST7701S_CMD_SET_DISPLAY_ON   0x29  // set display on command
#define ST7701S_CMD_SET_COLUMN_ADDRESS 0x2A // set column address command
#define ST7701S_CMD_SET_PAGE_ADDRESS  0x2B // set page address command
#define ST7701S_CMD_WRITE_MEMORY_START 0x2C // write memory start command
#define ST7701S_CMD_READ_MEMORY_START 0x2E // read memory start command
#define ST7701S_CMD_SET_TEAR_SCANLINE 0x44 // set tear scanline command
#define ST7701S_CMD_SET_DISPLAY_FUNCTION_CONTROL    0xB6  // set display function control command
#define ST7701S_CMD_Power_Control_1              0xB7  // set entry mode set command
#define ST7701S_CMD_SET_BACKLIGHT_CONTROL           0xB9  // set backlight control command
#define ST7701S_CMD_SET_CABC_CONTROL        0xBE  // set cabc control command
#define ST7701S_CMD_SET_POWER_CONTROL_1     0xC0  // set power control 1 command
#define ST7701S_CMD_SET_POWER_CONTROL_2     0xC1  // set power control 2 command
#define ST7701S_CMD_SET_VCOM_CONTROL        0xC5  // set vcom control command
#define ST7701S_CMD_SET_NV_MEMORY_WRITE     0xD0  // set nv memory write command
#define ST7701S_CMD_GET_NV_MEMORY_STATUS    0xD1  // get nv memory status command
#define ST7701S_CMD_All_Pixel_ON            0x23
class ST7701s
{
public:
    ST7701s(SPI *spi, PinName cs);
    void initDisplay();
    void writeComm(uint8_t data);
    void writeData(uint8_t data);
    void wait_ms(int time);
    void displaySmiley();
private:
    SPI *m_spi;
    DigitalOut *m_cs;

};


#endif /* ST7701S_H_ */
