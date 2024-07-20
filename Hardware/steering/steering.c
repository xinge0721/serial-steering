#include "steering.h"
#include "control.h"

void steering_Init(void)
{
	Serial_Init();
}
/**
  * 函    数：舵机校验和的计算
  * 参    数：舵机的ID号		
  * 参    数：旋转的角度		  范围 0~1000 ，对应舵机角度的0~240°
  * 参    数：旋转的时间			时间的范围 0~30000 毫秒。
	* 返 回 值：无
  */
char steering_Checksum(uint8_t ID ,uint8_t Length,uint8_t Cmd,int* Prm)
{
	int16_t Checksum = 0;
	for(int i = 0 ; i <= (Length - 1 )/ 2;i++)
	{
			Checksum += *(Prm + i);
	}
	Checksum += ID + Length + Cmd;
	return ~(char)Checksum;
}


void steering_ID(uint8_t ID,uint8_t RID)
{
	Serial_SendByte(0x55);		//发送帧头
	Serial_SendByte(0x55);
	
	Serial_SendByte(ID);			//发送ID
	
	Serial_SendByte(0x04);		//发送数据长度位
	Serial_SendByte(0x0D);		//发送指令位
	
  Serial_SendByte(RID);
	
	int Checksum[] = {RID};

	Serial_SendByte(steering_Checksum(ID,0x04,0x0D,Checksum));
}

/**
  * 函    数：串口发送一个旋转的指令
  * 参    数：舵机的ID号		
  * 参    数：旋转的角度		  范围 0~1000 ，对应舵机角度的0~240°
  * 参    数：旋转的时间			时间的范围 0~30000 毫秒。
	* 返 回 值：无
  */

void	steering_angle(uint8_t ID,uint16_t angle,uint16_t speed)
{
	Serial_SendByte(0x55);		//发送帧头
	Serial_SendByte(0x55);
	
	Serial_SendByte(ID);			//发送ID
	
	Serial_SendByte(0x07);		//发送数据长度位
	Serial_SendByte(0x01);		//发送指令位
	
	Serial_SendByte(angle      & 0x00ff);	//参数 1 ：角度的低八位。
	Serial_SendByte(angle >> 8 & 0x00ff);	//参数 2 ：角度的高八位。
	
	Serial_SendByte(speed      & 0x00ff);	//参数 3 ：时间低八位。
	Serial_SendByte(speed >> 8 & 0x00ff);	//参数 4 ：时间高八位。
	
	int Checksum[] = {angle&0x00ff,angle>> 8 & 0x00ff,speed& 0x00ff,speed >> 8 & 0x00ff};
	Serial_SendByte(steering_Checksum(ID,0x07,0x01,Checksum));
}

