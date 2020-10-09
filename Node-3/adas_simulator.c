/******************************************************************************
 * Module      : ADAS Simulator                                               *
 * File Name   : adas_simulator.h                                             *
 * Description : Source file for ADAS received module                         *
 * Created on  : Aug 12, 2020                                                 *
 ******************************************************************************/

#include "adas_simulator.h"

/******************************************************************************
 *                                                                            *
 *                              Global Variables                              *
 *                                                                            *
 ******************************************************************************/

/* ADAS received flag */
bool g_ADASReceived = false;

/******************************************************************************
 * Name         : ADASCarControl                                              *
 * Inputs       : distance                                                    *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : ADAS simulator o/p on UART.                                 *
 ******************************************************************************/
void ADASSimulator_Control(void)
{

    if (true == g_ADASReceived)
    {
        g_ADASReceived = false;

        switch (g_ReceivedDistance)
        {
        case ADAS_SENSOR_ERROR:
            UART_printf(ADAS_T0);
        break;
        case ADAS_SENSOR_METER_1:
            UART_printf(ADAS_T1);
        break;
        case ADAS_SENSOR_METER_2:
            UART_printf(ADAS_T2);
        break;
        case ADAS_SENSOR_METER_3:
            UART_printf(ADAS_T3);
        break;
        default: /* NO OBSTACLE */
            UART_printf(ADAS_T4);
        }
    }
    else
    {
        /* MISRA */
    }
}
