/*
 * ice_send.h
 *
 *  Created on: Dec 21, 2019
 *      Author: ADMIN
 */



#ifndef _ICE_SEND_H_
#define _ICE_SEND_H_
#include "wrapper.h"

void ice_init_send();
void ice_send(YoloData data) ;
void ice_end_send();

#endif /* _ICE_SEND_H_ */