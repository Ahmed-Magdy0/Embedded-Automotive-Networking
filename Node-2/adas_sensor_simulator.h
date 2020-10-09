/******************************************************************************
 * Module      : ADAS Sensor Simulator                                        *
 * File Name   : adas_sensor_simulator.c                                      *
 * Description : Header file for ADAS Sensor Simulator module                 *
 * Created on  : Aug 12, 2020                                                 *
 ******************************************************************************/

#ifndef ADAS_SENSOR_SIMULATOR_H_
#define ADAS_SENSOR_SIMULATOR_H_

#include <stdint.h>
#include <stdbool.h>
#include "can.h"
#include "uart_stdio.h"
#include "message_services.h"

/****************************************************************************** 
 *                                                                            * 
 *                                Definitions                                 * 
 *                                                                            * 
 ******************************************************************************/

/* Duty cycle limits */
#define ADAS_LIMIT_0    (10)
#define ADAS_LIMIT_1    (20)
#define ADAS_LIMIT_2    (40)
#define ADAS_LIMIT_3    (60)
#define ADAS_LIMIT_4    (100)

/* Duty cycle conversion */
#define ADAS_SENSOR_ERROR       (0)
#define ADAS_SENSOR_METER_1     (1)
#define ADAS_SENSOR_METER_2     (2)
#define ADAS_SENSOR_METER_3     (3)
#define ADAS_SENSOR_NO_OBSTACLE (4)

/****************************************************************************** 
 *                                                                            * 
 *                              Shared Variables                              * 
 *                                                                            * 
 ******************************************************************************/

/* Duty cycle */
extern uint8_t g_SensorDutyCycle;

/* Distance */
extern uint8_t g_SensorDistance;

/****************************************************************************** 
 *                                                                            * 
 *                            Function Prototypes                             * 
 *                                                                            * 
 ******************************************************************************/

/* Receive duty cycle by UART */
extern void ADASSensorSimulator_UpdateDutyCycle(void);

/* Calculates distance based on duty cycle */
extern void ADASSensorSimulator_UpdateDistance(void);

/* Sends distance over CANBUS */
extern void ADASSensorSimulator_SendDistance(void);


#endif /* ADAS_SENSOR_SIMULATOR_H_ */
