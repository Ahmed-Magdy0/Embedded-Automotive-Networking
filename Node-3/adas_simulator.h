/******************************************************************************
 * Module      : ADAS Simulator                                               *
 * File Name   : adas_simulator.h                                             *
 * Description : Header file for ADAS received module                         *
 * Created on  : Aug 12, 2020                                                 *
 ******************************************************************************/

#ifndef ADAS_SIMULATOR_H_
#define ADAS_SIMULATOR_H_

#include "uart_stdio.h"
#include "message_services.h"

/******************************************************************************
 *                                                                            *
 *                              Shared Variables                              *
 *                                                                            *
 ******************************************************************************/

/* ADAS received flag */
extern bool g_ADASReceived;

/****************************************************************************** 
 *                                                                            * 
 *                                Definitions                                 * 
 *                                                                            * 
 ******************************************************************************/

/* Conditions */
#define ADAS_SENSOR_ERROR       (0)
#define ADAS_SENSOR_METER_1     (1)
#define ADAS_SENSOR_METER_2     (2)
#define ADAS_SENSOR_METER_3     (3)
#define ADAS_SENSOR_NO_OBSTACLE (4)

/* UART output simulation */
#define ADAS_T0 "\n(0) CAR STOP!"
#define ADAS_T1 "\n(1) CAR TURN!"
#define ADAS_T2 "\n(2) MOVE FWD, REDUCE SPEED!"
#define ADAS_T3 "\n(3) MOVE FWD!"
#define ADAS_T4 "\n(4) MOVE FWD, INCREASE SPEED!"

/****************************************************************************** 
 *                                                                            * 
 *                            Function Prototypes                             * 
 *                                                                            * 
 ******************************************************************************/

/* Outputs command on UART console */
extern void ADASSimulator_Control(void);


#endif /* ADAS_SIMULATOR_H_ */
