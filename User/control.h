#ifndef __control_H
#define __control_H
#include "stm32f10x.h"                  // Device header

#include "Delay.h"
#include "Timer.h"
#include "Encoder.h"
#include "Key.h"
#include "OLED.h"
#include "sys.h"
#include "Serial.h"
#include "steering.h"

//标准库头文件声明

#include <math.h>
#include <stdio.h>
#include <string.h> 
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//函数声明
void main_Init(void);
void OLED_menu(void);

#endif
