/*
Example for Proximity Click

    Date          : Jul 2018.
    Author        : MikroE Team

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : vCANT_FIND_VERSION

---

Description :

The application is composed of three sections :

- System Initialization - Initalizes I2C module and sets INT pin as INPUT
- Application Initialization - Initialization driver init and sets chip on the default mode
- Application Task - (code snippet) - Reads Proximity data and Ambient light data adn logs data to USBUART every 500 ms.

*/

#include "Click_Proximity_types.h"
#include "Click_Proximity_config.h"

char demoText[ 50 ];
uint16_t proximity_proxiValue;
uint16_t proximity_ambiValue;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_i2cInit( _MIKROBUS1, &_PROXIMITY_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite( "Initializing...", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationInit()
{
    proximity_i2cDriverInit( (T_PROXIMITY_P)&_MIKROBUS1_GPIO, (T_PROXIMITY_P)&_MIKROBUS1_I2C, _PROXIMITY_SLAVE_ADDR );
    proximity_setDefaultMode();
    Delay_ms( 300 );
}

void applicationTask()
{
    proximity_ambiValue = proximity_readAmbientLight();
    proximity_proxiValue = proximity_readProxData();

    WordToStr(proximity_proxiValue, demoText);
    mikrobus_logWrite("Proximity:   ", _LOG_TEXT);
    mikrobus_logWrite( demoText, _LOG_LINE );

    WordToStr(proximity_ambiValue, demoText);
    mikrobus_logWrite("Ambient:     ", _LOG_TEXT);
    mikrobus_logWrite( demoText, _LOG_LINE );

    mikrobus_logWrite( " ", _LOG_LINE );
    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}