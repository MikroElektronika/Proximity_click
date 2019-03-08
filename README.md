![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Proximity Click

---

- **CIC Prefix**  : PROXIMITY
- **Author**      : MikroE Team
- **Verison**     : 1.0.0
- **Date**        : Jul 2018.

---

### Software Support

We provide a library for the Proximity Click on our [LibStock](https://libstock.mikroe.com/projects/view/751/proximity-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data from register.
The library includes function for proximity data and ambient light data.
The user also has the function for sets chip on the default mode and functions for sets upper threshold.

Key functions :

- ``` uint16_t proximity_readAmbientLight() ``` - Functions for reads Ambient light
- ``` uint16_t proximity_readProxData() ``` - Functions for reads Proximity data 
- ``` void proximity_setDefaultMode() ``` - Functions for sets default mode

**Examples Description**

The application is composed of three sections :

- System Initialization - Initalizes I2C module and sets INT pin as INPUT
- Application Initialization - Initialization driver init and sets chip on the default mode
- Application Task - (code snippet) - Reads Proximity data and Ambient light data adn logs data to USBUART every 500 ms.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/751/proximity-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
