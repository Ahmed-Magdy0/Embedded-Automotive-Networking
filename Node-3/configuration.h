/****************************************************************************** 
 * Module      : None                                                         * 
 * File Name   : configuration.h                                              * 
 * Description : Header file for configuration                                * 
 * Created on  : Mar 23, 2020                                                 * 
 ******************************************************************************/

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "indicator_led_control_system.h"

/****************************************************************************** 
 *                                                                            * 
 *                                Definitions                                 * 
 *                                                                            * 
 ******************************************************************************/

/* NODE_IDs for indicator LED system */
#define NODE_ID                     ( NODE_3 )
#define NODE_ID_AFTER               ( NODE_1 )
#define NODE_ID_PREV                ( NODE_2 )

/* Initial conditions */
#define NODE_DEFAULT_COLOR          (COLOR_BLUE)
#define NODE_INITIAL_TOKEN_STATE    (false)

#endif /* CONFIGURATION_H_ */
