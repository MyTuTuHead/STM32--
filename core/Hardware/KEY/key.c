/*
文件名：key.c
创建人：妙啊
创建时间：2022/3/20
功能：

占用资源:

修改日志：


现有问题：



*/


#include "key.h"
#include "delay.h"

void KEY_Init(void){ //
	GPIO_InitTypeDef  GPIO_InitStructure; //
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB,ENABLE); 
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//失能JTAG接口，使用PA15
      
    GPIO_InitStructure.GPIO_Pin = KEY1 | KEY2 | KEY3 | KEY4; //                     
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入        
	GPIO_Init(KEY_PORT,&GPIO_InitStructure);	
}
 
u8 Key_Read(void){

		if(GPIO_ReadInputDataBit(KEY_PORT,KEY1)==0){
			delay_ms(5);
			if(GPIO_ReadInputDataBit(KEY_PORT,KEY1)==0){
				while(!GPIO_ReadInputDataBit(KEY_PORT,KEY1));
				return 1;
			}
		}

		if(GPIO_ReadInputDataBit(KEY_PORT,KEY2)==0){
			delay_ms(5);
			if(GPIO_ReadInputDataBit(KEY_PORT,KEY2)==0){
				while(!GPIO_ReadInputDataBit(KEY_PORT,KEY2));
				return 2;
			}
		}

		if(GPIO_ReadInputDataBit(KEY_PORT,KEY3)==0){
			delay_ms(5);
			if(GPIO_ReadInputDataBit(KEY_PORT,KEY3)==0){
				while(!GPIO_ReadInputDataBit(KEY_PORT,KEY3));
				return 3;
			}
		}

		if(GPIO_ReadInputDataBit(KEY_PORT,KEY4)==0){
			delay_ms(5);
			if(GPIO_ReadInputDataBit(KEY_PORT,KEY4)==0){
				while(!GPIO_ReadInputDataBit(KEY_PORT,KEY4));
				return 4;
			}
		}
	return 0;
}







void ASR_Init(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);       
    GPIO_InitStructure.GPIO_Pin = ASR1 | ASR2 | ASR3 | ASR4 | ASR5 | ASR6 | ASR7; //                     
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //下拉输入        
	GPIO_Init(ASR_PORT,&GPIO_InitStructure);	
}


//读取一次ASR结果
 u8 Asr_Read(void){

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR1)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR1));
			return 1;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR2)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR2));
			return 2;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR3)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR3));
			return 3;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR4)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR4));
			return 4;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR5)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR5));
			return 5;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR6)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR6));
			return 6;
		}

		if(GPIO_ReadInputDataBit(ASR_PORT,ASR7)==1){
			while(GPIO_ReadInputDataBit(ASR_PORT,ASR7));
			return 7;
		}
	return 0;
}


/*
选锟斤拷IO锟接口癸拷锟斤拷锟斤拷式锟斤拷
GPIO_Mode_AIN 模锟斤拷锟斤拷锟斤拷
GPIO_Mode_IN_FLOATING 锟斤拷锟斤拷锟斤拷锟斤拷
GPIO_Mode_IPD 锟斤拷锟斤拷锟斤拷锟斤拷
GPIO_Mode_IPU 锟斤拷锟斤拷锟斤拷锟斤拷
GPIO_Mode_Out_PP 锟斤拷锟斤拷锟斤拷锟?
GPIO_Mode_Out_OD 锟斤拷漏锟斤拷锟?
GPIO_Mode_AF_PP 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
GPIO_Mode_AF_OD 锟斤拷锟矫匡拷漏锟斤拷锟?
*/
