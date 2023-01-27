/*
 * st7701s.cpp
 *
 *  Created on: 26.01.2023
 *      Author: Markus
 */

#include "ST7701s.h"




ST7701s::ST7701s(SPI *spi, PinName cs):m_spi(spi)
{
    m_cs = new DigitalOut(cs);
    m_spi->format(16u,0u);
    DISABLE_SPI;
}


void ST7701s::initDisplay() {
    // Software Reset
        writeComm(ST7701S_CMD_SWRESET);
        wait_ms(150);

        // Exit Sleep
        writeComm(ST7701S_CMD_SLEEP_OUT);
        wait_ms(500);

        // Set Color Format
        writeComm(ST7701S_CMD_SET_PIXEL_FORMAT);
        writeData(0x55);

        // Set Address Mode
        writeComm(ST7701S_CMD_SET_ADDRESS_MODE);
        writeData(0x00);

        // Set Display On
        writeComm(ST7701S_CMD_DISP_ON);
        wait_ms(200);

        // Set Gamma Curve
        writeComm(ST7701S_CMD_SET_GAMMA_CURVE);
        writeData(0x01);

        // Set Display Clock Divide
        writeComm(ST7701S_CMD_SET_DISPLAY_CLOCK_DIV);
        writeData(0xF0);

        // Set Tear On
        writeComm(ST7701S_CMD_SET_TEAR_OFF);
        writeData(0x00);

        // Set Scanline
        writeComm(ST7701S_CMD_SET_TEAR_SCANLINE);
        writeData(0x00);
        writeData(0x00);

        // Set Scroll Start
        writeComm(ST7701S_CMD_SET_SCROLL_START);
        writeData(0x00);
        writeData(0x00);

        // Set Partial Area
        writeComm(ST7701S_CMD_SET_PARTIAL_AREA);
        writeData(0x00);
        writeData(0x00);
        writeData(0x00);
        writeData(0x00);

        writeComm(ST7701S_CMD_All_Pixel_ON);

}

// Array containing the bitmap data for the smiley face

void ST7701s::wait_ms(int time)
{
    rtos::ThisThread::sleep_for(time);
}


void ST7701s::writeComm(uint8_t data)
{
    uint16_t spidata = data & 0x00FF;
    spidata = spidata << 7;
    ENABLE_SPI;
    m_spi->write(spidata);
    DISABLE_SPI;
}


void ST7701s::writeData(uint8_t data)
{
    uint16_t spidata = data & 0x00FF;
    spidata = spidata << 7;
    spidata |= 0x8000;
    ENABLE_SPI;
    m_spi->write(spidata);
    DISABLE_SPI;
}


