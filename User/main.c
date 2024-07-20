#include "control.h"



int main()
{
//	main_Init();			//Ó²¼þ³õÊ¼»¯
	steering_Init();
	for(int i = 0 ; i < 253 ; i++)
	{
		steering_ID(i,1);  
	}
	while(1)
	{
		steering_angle(1,0xE803,0xE803);
	}
}



//void TIM4_IRQHandler(void)//10ms
//{
//	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)//1ms
//	{

//	}
//	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
//}

