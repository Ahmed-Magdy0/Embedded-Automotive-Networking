/******************************************************************************
 * Module      : ADAS Sensor Simulator                                        *
 * File Name   : adas_sensor_simulator.c                                      *
 * Description : Source file for ADAS Sensor Simulator module                 *
 * Created on  : Aug 12, 2020                                                 *
 ******************************************************************************/

#include "adas_sensor_simulator.h"

/******************************************************************************
 *                                                                            *
 *                              Global Variables                              *
 *                                                                            *
 ******************************************************************************/

/* Duty cycle */
uint8_t g_SensorDutyCycle = 0;

/* Distance */
uint8_t g_SensorDistance = 0;

/******************************************************************************
 * Name         : ADASSensorSimulator_UpdateDutyCycle                         *
 * Inputs       : None                                                        *
 * Outputs      : g_SensorDutyCycle                                           *
 * Return Value : None                                                        *
 * Description  : Receive duty cycle by UART.                                 *
 ******************************************************************************/
extern void ADASSensorSimulator_UpdateDutyCycle(void)
{
uint8_t ReceivedByte;   /* received duty cycle */
        
    /* Get received byte. */
    ReceivedByte = UART_ReceiveByte();
        
    /* Check if UART has sent. */
    if (true == g_UART_available)
    {
        /* Store received byte. */
        g_SensorDutyCycle = ReceivedByte;
    }
    else /* UART NOT AVAILABLE */
    {
        /* MISRA */
    }
}

/******************************************************************************
 * Name         : ADASSensorSimulator_UpdateDistance                          *
 * Inputs       : g_SensorDutyCycle                                           *
 * Outputs      : g_SensorDistance                                            *
 * Return Value : None                                                        *
 * Description  : Calculates distance based on duty cycle                     *
 ******************************************************************************/
extern void ADASSensorSimulator_UpdateDistance(void)
{
    /* Update distance based on duty cycle. */
    if (g_SensorDutyCycle <= ADAS_LIMIT_0)
    {
        /* Update stored distance. */
        g_SensorDistance = ADAS_SENSOR_ERROR;
    }
    else if (g_SensorDutyCycle <= ADAS_LIMIT_1)
    {
        /* Update stored distance. */
        g_SensorDistance = ADAS_SENSOR_METER_1;
    }
    else if (g_SensorDutyCycle <= ADAS_LIMIT_2)
    {
        /* Update stored distance. */
        g_SensorDistance = ADAS_SENSOR_METER_2;
    }
    else if (g_SensorDutyCycle <= ADAS_LIMIT_3)
    {
        /* Update stored distance. */
        g_SensorDistance = ADAS_SENSOR_METER_3;
    }
    else if (g_SensorDutyCycle <= ADAS_LIMIT_4)
    {
        /* Update stored distance. */
        g_SensorDistance = ADAS_SENSOR_NO_OBSTACLE;
    }
    else
    {
        /* More than 100% (IMPOSSIBLE VALUE) */
        /* DO NOTHING */
    }
}

/******************************************************************************
 * Name         : ADASSensorSimulator_SendDistance                            *
 * Inputs       : g_SensorDistance                                            *
 * Outputs      : None                                                        *
 * Return Value : None                                                        *
 * Description  : Sends distance over CANBUS.                                 *
 ******************************************************************************/
extern void ADASSensorSimulator_SendDistance(void)
{
    /* Update duty cycle readings. */
    ADASSensorSimulator_UpdateDutyCycle();

    /* Update distance to be sent. */
    ADASSensorSimulator_UpdateDistance();

    /* Compress message to be sent. */
    MessageServices_Compress(&g_txCAN, DISTANCE_MSG_ID);

    /* Transmit over CAN. */
    CAN_TransmitByte();
}
