#ifndef __steering_H
#define __steering_H

#include "control.h"

void steering_Init(void);

void	steering_angle(uint8_t ID,uint16_t angle,uint16_t speed);
void steering_ID(uint8_t ID,uint8_t RID);

#endif
