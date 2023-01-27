/* mbed Microcontroller Library
 * Copyright (c) 2023 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "ST7701s.h"

SPI spi(PA_7, PB_4, PA_5);

ST7701s display(&spi, PA_4);

int main()
{
    display.initDisplay();
    while(1);
    return 0;
}
