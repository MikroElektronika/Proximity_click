/*
    __proximity_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __proximity_driver.h
@brief    Proximity Driver
@mainpage Proximity Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   PROXIMITY
@brief      Proximity Click Driver
@{

| Global Library Prefix | **PROXIMITY** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _PROXIMITY_H_
#define _PROXIMITY_H_

/** 
 * @macro T_PROXIMITY_P
 * @brief Driver Abstract type 
 */
#define T_PROXIMITY_P    const uint8_t*

/** @defgroup PROXIMITY_COMPILE Compilation Config */              /** @{ */

//  #define   __PROXIMITY_DRV_SPI__                            /**<     @macro __PROXIMITY_DRV_SPI__  @brief SPI driver selector */
   #define   __PROXIMITY_DRV_I2C__                            /**<     @macro __PROXIMITY_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __PROXIMITY_DRV_UART__                           /**<     @macro __PROXIMITY_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup PROXIMITY_VAR Variables */                           /** @{ */
extern const uint8_t _PROXIMITY_SLAVE_ADDR;

extern const uint8_t _PROXIMITY_REGISTER_COMMAND;
extern const uint8_t _PROXIMITY_REGISTER_ID;
extern const uint8_t _PROXIMITY_REGISTER_PROX_RATE;
extern const uint8_t _PROXIMITY_REGISTER_PROX_CURRENT;
extern const uint8_t _PROXIMITY_REGISTER_AMBI_PARAMETER;
extern const uint8_t _PROXIMITY_REGISTER_AMBI_VALUE;
extern const uint8_t _PROXIMITY_REGISTER_PROX_VALUE;
extern const uint8_t _PROXIMITY_REGISTER_INTERRUPT_CONTROL;
extern const uint8_t _PROXIMITY_REGISTER_INTERRUPT_LOW_THRES;
extern const uint8_t _PROXIMITY_REGISTER_INTERRUPT_HIGH_THRES;
extern const uint8_t _PROXIMITY_REGISTER_INTERRUPT_STATUS;
extern const uint8_t _PROXIMITY_REGISTER_PROX_TIMING;
extern const uint8_t _PROXIMITY_REGISTER_AMBI_IR_LIGHT_LEVEL;

extern const uint8_t _PROXIMITY_COMMAND_ALL_DISABLE;
extern const uint8_t _PROXIMITY_COMMAND_SELFTIMED_MODE_ENABLE;
extern const uint8_t _PROXIMITY_COMMAND_PROX_ENABLE;
extern const uint8_t _PROXIMITY_COMMAND_AMBI_ENABLE;
extern const uint8_t _PROXIMITY_COMMAND_PROX_ON_DEMAND;
extern const uint8_t _PROXIMITY_COMMAND_AMBI_ON_DEMAND;
extern const uint8_t _PROXIMITY_COMMAND_MASK_PROX_DATA_READY;
extern const uint8_t _PROXIMITY_COMMAND_MASK_AMBI_DATA_READY;
extern const uint8_t _PROXIMITY_COMMAND_MASK_LOCK;

extern const uint8_t _PROXIMITY_PRODUCT_MASK_REVISION_ID;
extern const uint8_t _PROXIMITY_PRODUCT_MASK_PRODUCT_ID;

extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_2;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_4;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_8;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_16;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_31;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_62;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_125;
extern const uint8_t _PROXIMITY_MEASUREMENT_RATE_250;
extern const uint8_t _PROXIMITY_MASK_MEASUREMENT_RATE;

extern const uint8_t _PROXIMITY_MASK_LED_CURRENT;
extern const uint8_t _PROXIMITY_MASK_FUSE_PROG_ID;

extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_1;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_2;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_4;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_8;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_16;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_32;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_64;
extern const uint8_t _PROXIMITY_AMBI_PARA_AVERAGE_128;
extern const uint8_t _PROXIMITY_AMBI_MASK_PARA_AVERAGE;
extern const uint8_t _PROXIMITY_AMBI_PARA_AUTO_OFFSET_ENABLE;
extern const uint8_t _PROXIMITY_AMBI_MASK_PARA_AUTO_OFFSET;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_1;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_2;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_3;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_4;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_5;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_6;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_8;
extern const uint8_t _PROXIMITY_AMBI_PARA_MEAS_RATE_10;
extern const uint8_t _PROXIMITY_AMBI_MASK_PARA_MEAS_RATE;
extern const uint8_t _PROXIMITY_AMBI_PARA_CONT_CONV_ENABLE;
extern const uint8_t _PROXIMITY_AMBI_MASK_PARA_CONT_CONV;

extern const uint8_t _PROXIMITY_INTERRUPT_THRES_SEL_PROX;
extern const uint8_t _PROXIMITY_INTERRUPT_THRES_SEL_ALS;
extern const uint8_t _PROXIMITY_INTERRUPT_THRES_ENABLE;
extern const uint8_t _PROXIMITY_INTERRUPT_ALS_READY_ENABLE;
extern const uint8_t _PROXIMITY_INTERRUPT_PROX_READY_ENABLE;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_1;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_2;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_4;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_8;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_16;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_32;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_64;
extern const uint8_t _PROXIMITY_INTERRUPT_COUNT_EXCEED_128;
extern const uint8_t _PROXIMITY_INTERRUPT_MASK_COUNT_EXCEED;

extern const uint8_t _PROXIMITY_INTERRUPT_STATUS_THRES_HI;
extern const uint8_t _PROXIMITY_INTERRUPT_STATUS_THRES_LO;
extern const uint8_t _PROXIMITY_INTERRUPT_STATUS_ALS_READY;
extern const uint8_t _PROXIMITY_INTERRUPT_STATUS_PROX_READY;
extern const uint8_t _PROXIMITY_INTERRUPT_MASK_STATUS_THRES_HI;
extern const uint8_t _PROXIMITY_INTERRUPT_MASK_THRES_LO;
extern const uint8_t _PROXIMITY_INTERRUPT_MASK_ALS_READY;
extern const uint8_t _PROXIMITY_INTERRUPT_MASK_PROX_READY;

                                                                       /** @} */
/** @defgroup PROXIMITY_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup PROXIMITY_INIT Driver Initialization */              /** @{ */

#ifdef   __PROXIMITY_DRV_SPI__
void proximity_spiDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P spiObj);
#endif
#ifdef   __PROXIMITY_DRV_I2C__
void proximity_i2cDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P i2cObj, uint8_t slave);
#endif
#ifdef   __PROXIMITY_DRV_UART__
void proximity_uartDriverInit(T_PROXIMITY_P gpioObj, T_PROXIMITY_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void proximity_gpioDriverInit(T_PROXIMITY_P gpioObj);
                                                                       /** @} */
/** @defgroup PROXIMITY_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] wAddr    Register in which the data will be written
 * @param[in] wData  Data which be written in the register
 */
void proximity_writeByte(uint8_t wAddr, uint8_t wData);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] rAddr    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t proximity_readByte(uint8_t rAddr);

/**
 * @brief Functions for read data from register
 *
 * @param[in]   rAddr       Register which will be read
 * @param[out]  rcvData     Output buffer
 * @param[in]   nLen        Number of bytes will be reads
 */
void proximity_readData(uint8_t rAddr, uint8_t* rcvData, uint8_t nLen);

/**
 * @brief Functions for write data
 *
 * @param[in]   rAddr       Register
 * @param[in]   wrData      Buffer with data
 * @param[in]   nLen        Number of bytes will be writting
 */
void proximity_writeData(uint8_t wAddr, uint8_t* wrData, uint8_t nLen);

/**
 * @brief Functions for sets default mode
 */
void proximity_setDefaultMode();

/**
 * @brief Functions for sets upper threshold
 */
void proximity_setUpperThreshold();

/**
 * @brief Functions for reads Proximity data
 *
 * @retval Proximity data
 */
uint16_t proximity_readProxData();

/**
 * @brief Functions for reads Ambient light
 *
 * @retval Ambient Light data
 */
uint16_t proximity_readAmbientLight();


                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Proximity_STM.c
    @example Click_Proximity_TIVA.c
    @example Click_Proximity_CEC.c
    @example Click_Proximity_KINETIS.c
    @example Click_Proximity_MSP.c
    @example Click_Proximity_PIC.c
    @example Click_Proximity_PIC32.c
    @example Click_Proximity_DSPIC.c
    @example Click_Proximity_AVR.c
    @example Click_Proximity_FT90x.c
    @example Click_Proximity_STM.mbas
    @example Click_Proximity_TIVA.mbas
    @example Click_Proximity_CEC.mbas
    @example Click_Proximity_KINETIS.mbas
    @example Click_Proximity_MSP.mbas
    @example Click_Proximity_PIC.mbas
    @example Click_Proximity_PIC32.mbas
    @example Click_Proximity_DSPIC.mbas
    @example Click_Proximity_AVR.mbas
    @example Click_Proximity_FT90x.mbas
    @example Click_Proximity_STM.mpas
    @example Click_Proximity_TIVA.mpas
    @example Click_Proximity_CEC.mpas
    @example Click_Proximity_KINETIS.mpas
    @example Click_Proximity_MSP.mpas
    @example Click_Proximity_PIC.mpas
    @example Click_Proximity_PIC32.mpas
    @example Click_Proximity_DSPIC.mpas
    @example Click_Proximity_AVR.mpas
    @example Click_Proximity_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __proximity_driver.h

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