#include "steering.h"
#include "control.h"

void steering_Init(void)
{
	Serial_Init();
}
/**
  * ��    �������У��͵ļ���
  * ��    ���������ID��		
  * ��    ������ת�ĽǶ�		  ��Χ 0~1000 ����Ӧ����Ƕȵ�0~240��
  * ��    ������ת��ʱ��			ʱ��ķ�Χ 0~30000 ���롣
	* �� �� ֵ����
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
	Serial_SendByte(0x55);		//����֡ͷ
	Serial_SendByte(0x55);
	
	Serial_SendByte(ID);			//����ID
	
	Serial_SendByte(0x04);		//�������ݳ���λ
	Serial_SendByte(0x0D);		//����ָ��λ
	
  Serial_SendByte(RID);
	
	int Checksum[] = {RID};

	Serial_SendByte(steering_Checksum(ID,0x04,0x0D,Checksum));
}

/**
  * ��    �������ڷ���һ����ת��ָ��
  * ��    ���������ID��		
  * ��    ������ת�ĽǶ�		  ��Χ 0~1000 ����Ӧ����Ƕȵ�0~240��
  * ��    ������ת��ʱ��			ʱ��ķ�Χ 0~30000 ���롣
	* �� �� ֵ����
  */

void	steering_angle(uint8_t ID,uint16_t angle,uint16_t speed)
{
	Serial_SendByte(0x55);		//����֡ͷ
	Serial_SendByte(0x55);
	
	Serial_SendByte(ID);			//����ID
	
	Serial_SendByte(0x07);		//�������ݳ���λ
	Serial_SendByte(0x01);		//����ָ��λ
	
	Serial_SendByte(angle      & 0x00ff);	//���� 1 ���ǶȵĵͰ�λ��
	Serial_SendByte(angle >> 8 & 0x00ff);	//���� 2 ���Ƕȵĸ߰�λ��
	
	Serial_SendByte(speed      & 0x00ff);	//���� 3 ��ʱ��Ͱ�λ��
	Serial_SendByte(speed >> 8 & 0x00ff);	//���� 4 ��ʱ��߰�λ��
	
	int Checksum[] = {angle&0x00ff,angle>> 8 & 0x00ff,speed& 0x00ff,speed >> 8 & 0x00ff};
	Serial_SendByte(steering_Checksum(ID,0x07,0x01,Checksum));
}

