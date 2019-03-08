/*
    __proximity_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__proximity_driver.h"
#include "__proximity_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t _PROXIMITY_SLAVE_ADDR = 0x13;
// registers
const uint8_t _PROXIMITY_REGISTER_COMMAND               = 0x80;
const uint8_t _PROXIMITY_REGISTER_ID                    = 0x81;
const uint8_t _PROXIMITY_REGISTER_PROX_RATE             = 0x82;
const uint8_t _PROXIMITY_REGISTER_PROX_CURRENT          = 0x83;
const uint8_t _PROXIMITY_REGISTER_AMBI_PARAMETER        = 0x84;
const uint8_t _PROXIMITY_REGISTER_AMBI_VALUE            = 0x85;
const uint8_t _PROXIMITY_REGISTER_PROX_VALUE            = 0x87;
const uint8_t _PROXIMITY_REGISTER_INTERRUPT_CONTROL     = 0x89;
const uint8_t _PROXIMITY_REGISTER_INTERRUPT_LOW_THRES   = 0x8a;
const uint8_t _PROXIMITY_REGISTER_INTERRUPT_HIGH_THRES  = 0x8c;
const uint8_t _PROXIMITY_REGISTER_INTERRUPT_STATUS      = 0x8e;
const uint8_t _PROXIMITY_REGISTER_PROX_TIMING           = 0xf9;
const uint8_t _PROXIMITY_REGISTER_AMBI_IR_LIGHT_LEVEL   = 0x90;

const uint8_t _PROXIMITY_COMMAND_ALL_DISABLE           = 0x00;
const uint8_t _PROXIMITY_COMMAND_SELFTIMED_MODE_ENABLE = 0x01;
const uint8_t _PROXIMITY_COMMAND_PROX_ENABLE           = 0x02;
const uint8_t _PROXIMITY_COMMAND_AMBI_ENABLE           = 0x04;
const uint8_t _PROXIMITY_COMMAND_PROX_ON_DEMAND        = 0x08;
const uint8_t _PROXIMITY_COMMAND_AMBI_ON_DEMAND        = 0x10;
const uint8_t _PROXIMITY_COMMAND_MASK_PROX_DATA_READY  = 0x20;
const uint8_t _PROXIMITY_COMMAND_MASK_AMBI_DATA_READY  = 0x40;
const uint8_t _PROXIMITY_COMMAND_MASK_LOCK             = 0x80;

const uint8_t _PROXIMITY_PRODUCT_MASK_REVISION_ID = 0x0f;
const uint8_t _PROXIMITY_PRODUCT_MASK_PRODUCT_ID  = 0xf0;

const uint8_t _PROXIMITY_MEASUREMENT_RATE_2    = 0x00; // DEFAULT
const uint8_t _PROXIMITY_MEASUREMENT_RATE_4    = 0x01;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_8    = 0x02;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_16   = 0x03;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_31   = 0x04;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_62   = 0x05;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_125  = 0x06;
const uint8_t _PROXIMITY_MEASUREMENT_RATE_250  = 0x07;
const uint8_t _PROXIMITY_MASK_MEASUREMENT_RATE = 0x07;

const uint8_t _PROXIMITY_MASK_LED_CURRENT  = 0x3f; 
const uint8_t _PROXIMITY_MASK_FUSE_PROG_ID = 0xc0;

const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_1          = 0x00;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_2          = 0x01;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_4          = 0x02;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_8          = 0x03;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_16         = 0x04;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_32         = 0x05; // DEFAULT
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_64         = 0x06;
const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_128        = 0x07;
const uint8_t _PROXIMITY_AMBI_MASK_PARA_AVERAGE       = 0x07;
const uint8_t _PROXIMITY_AMBI_PARA_AUTO_OFFSET_ENABLE = 0x08; // DEFAULT enable
const uint8_t _PROXIMITY_AMBI_MASK_PARA_AUTO_OFFSET   = 0x08;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_1        = 0x00;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_2        = 0x10; // DEFAULT
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_3        = 0x20;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_4        = 0x30;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_5        = 0x40;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_6        = 0x50;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_8        = 0x60;
const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_10       = 0x70;
const uint8_t _PROXIMITY_AMBI_MASK_PARA_MEAS_RATE     = 0x70;
const uint8_t _PROXIMITY_AMBI_PARA_CONT_CONV_ENABLE   = 0x80;
const uint8_t _PROXIMITY_AMBI_MASK_PARA_CONT_CONV     = 0x80; // DEFAULT disable

const uint8_t _PROXIMITY_INTERRUPT_THRES_SEL_PROX     = 0x00;
const uint8_t _PROXIMITY_INTERRUPT_THRES_SEL_ALS      = 0x01;
const uint8_t _PROXIMITY_INTERRUPT_THRES_ENABLE       = 0x02;
const uint8_t _PROXIMITY_INTERRUPT_ALS_READY_ENABLE   = 0x04;
const uint8_t _PROXIMITY_INTERRUPT_PROX_READY_ENABLE  = 0x08;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_1     = 0x00; // DEFAULT
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_2     = 0x20;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_4     = 0x40;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_8     = 0x60;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_16    = 0x80;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_32    = 0xa0;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_64    = 0xc0;
const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_128   = 0xe0;
const uint8_t _PROXIMITY_INTERRUPT_MASK_COUNT_EXCEED  = 0xe0;

const uint8_t _PROXIMITY_INTERRUPT_STATUS_THRES_HI      = 0x01;
const uint8_t _PROXIMITY_INTERRUPT_STATUS_THRES_LO      = 0x02;
const uint8_t _PROXIMITY_INTERRUPT_STATUS_ALS_READY     = 0x04;
const uint8_t _PROXIMITY_INTERRUPT_STATUS_PROX_READY    = 0x08;
const uint8_t _PROXIMITY_INTERRUPT_MASK_STATUS_THRES_HI = 0x01;
const uint8_t _PROXIMITY_INTERRUPT_MASK_THRES_LO        = 0x02;
const uint8_t _PROXIMITY_INTERRUPT_MASK_ALS_READY       = 0x04;
const uint8_t _PROXIMITY_INTERRUPT_MASK_PROX_READY      = 0x08;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __PROXIMITY_DRV_I2C__
static uint8_t _slaveAddress;
#endif


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __PROXIMITY_DRV_SPI__

void proximity_spiDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __PROXIMITY_DRV_I2C__

void proximity_i2cDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __PROXIMITY_DRV_UART__

void proximity_uartDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */


void proximity_writeByte(uint8_t wAddr, uint8_t wData)
{
    uint8_t buffer[2];
    buffer[0] = wAddr;
    buffer[1] = wData;
  
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 2, END_MODE_STOP );
}

uint8_t proximity_readByte(uint8_t rAddr)
{
    uint8_t regAddr;
    regAddr = rAddr;
  
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, &regAddr, 1, END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, &regAddr, 1, END_MODE_STOP );

    return regAddr;
}

void proximity_readData(uint8_t rAddr, uint8_t* rcvData, uint8_t nLen)
{
    uint8_t regAddr;
    regAddr = rAddr;
  
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, &regAddr, 1, END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, rcvData, nLen, END_MODE_STOP );
}

void proximity_writeData(uint8_t wAddr, uint8_t* wrData, uint8_t nLen)
{
    uint8_t iLoop;
    uint8_t buffer[256];
  
    buffer[0] = wAddr;
    for(iLoop = 1; iLoop <= nLen; iLoop++)
    {
        buffer[iLoop] = wrData[iLoop - 1];
    }
  
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, nLen + 1, END_MODE_STOP );
}

void proximity_setDefaultMode()
{
    proximity_writeByte(_PROXIMITY_REGISTER_PROX_CURRENT, 20);
    proximity_writeByte(_PROXIMITY_REGISTER_PROX_RATE, _PROXIMITY_MEASUREMENT_RATE_31);
    proximity_writeByte(_PROXIMITY_REGISTER_COMMAND, _PROXIMITY_COMMAND_PROX_ENABLE | _PROXIMITY_COMMAND_AMBI_ENABLE | _PROXIMITY_COMMAND_SELFTIMED_MODE_ENABLE);
    proximity_writeByte(_PROXIMITY_REGISTER_INTERRUPT_CONTROL, _PROXIMITY_INTERRUPT_THRES_SEL_PROX | _PROXIMITY_INTERRUPT_THRES_ENABLE | _PROXIMITY_INTERRUPT_COUNT_EXCEED_1);
    proximity_writeByte(_PROXIMITY_REGISTER_AMBI_PARAMETER, _PROXIMITY_AMBI_PARA_AVERAGE_32 | _PROXIMITY_AMBI_PARA_AUTO_OFFSET_ENABLE | _PROXIMITY_AMBI_PARA_MEAS_RATE_2);
    Delay_100ms();
}

void proximity_setUpperThreshold()
{
    uint8_t iLoop;
    uint16_t proxiValue;
    uint8_t command;
    uint8_t loByte, hiByte;
    uint32_t summProxiValue = 0;
    uint16_t proximity_averageProxiValue;
    uint8_t proximity_data_[ 2 ];

    for (iLoop = 0; iLoop < 16; iLoop++)
    {
        do
        {
            command = proximity_readByte(_PROXIMITY_REGISTER_COMMAND);
        } while (0 == (command & _PROXIMITY_COMMAND_MASK_PROX_DATA_READY));
        
        proximity_readData(_PROXIMITY_REGISTER_PROX_VALUE, &proximity_data_[0], 2);
        proxiValue = proximity_data_[0];
        proxiValue <<= 8;
        proxiValue |= proximity_data_[1];
        summProxiValue += proxiValue; // Summ of all measured prox values
    }
    proximity_averageProxiValue = summProxiValue / 16;

    loByte = (uint8_t)((proximity_averageProxiValue + 20) & 0x00FF);
    hiByte = (uint8_t)(((proximity_averageProxiValue + 20) & 0xFF00) >> 8);
    proximity_writeByte(_PROXIMITY_REGISTER_INTERRUPT_HIGH_THRES, hiByte);
    proximity_writeByte(_PROXIMITY_REGISTER_INTERRUPT_HIGH_THRES + 1, loByte);
}

uint16_t proximity_readProxData()
{
    uint8_t proximity_command;
    uint16_t proximity_proxiValue;
    uint8_t proximity_interruptStatus;
    uint8_t proximity_data_[ 2 ];
    
    do
    {
        proximity_command = proximity_readByte(_PROXIMITY_REGISTER_COMMAND);
    }while (0 == (proximity_command & _PROXIMITY_COMMAND_MASK_PROX_DATA_READY));

    proximity_interruptStatus = proximity_readByte(_PROXIMITY_REGISTER_INTERRUPT_STATUS);
    if(proximity_interruptStatus & _PROXIMITY_INTERRUPT_MASK_STATUS_THRES_HI)
    {
        proximity_writeByte(_PROXIMITY_REGISTER_INTERRUPT_STATUS, proximity_interruptStatus);
    }

    if((proximity_command & _PROXIMITY_COMMAND_MASK_PROX_DATA_READY) != 0)
    {
        proximity_readData(_PROXIMITY_REGISTER_PROX_VALUE, &proximity_data_[0], 2);
        proximity_proxiValue = proximity_data_[0];
        proximity_proxiValue <<= 8;
        proximity_proxiValue |= proximity_data_[1];
        return  proximity_proxiValue;
    }
    return 0;
}

uint16_t proximity_readAmbientLight()
{
    uint8_t proximity_command;
    uint16_t proximity_ambiValue;
    uint8_t proximity_interruptStatus;
    uint8_t proximity_data_[ 2 ];

    do
    {
        proximity_command = proximity_readByte(_PROXIMITY_REGISTER_COMMAND);
    }while (0 == (proximity_command & _PROXIMITY_COMMAND_MASK_AMBI_DATA_READY));

    proximity_interruptStatus = proximity_readByte(_PROXIMITY_REGISTER_INTERRUPT_STATUS);
    if(proximity_interruptStatus & _PROXIMITY_INTERRUPT_MASK_STATUS_THRES_HI)
    {
        proximity_writeByte(_PROXIMITY_REGISTER_INTERRUPT_STATUS, proximity_interruptStatus);
    }

    if((proximity_command & _PROXIMITY_COMMAND_MASK_AMBI_DATA_READY) != 0 )
    {
         proximity_readData(_PROXIMITY_REGISTER_AMBI_VALUE, &proximity_data_[0], 2);
         proximity_ambiValue = proximity_data_[0];
         proximity_ambiValue <<= 8;
         proximity_ambiValue |= proximity_data_[1];
         return proximity_ambiValue;
    }
    return 0;
}

/* -------------------------------------------------------------------------- */
/*
  __proximity_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */