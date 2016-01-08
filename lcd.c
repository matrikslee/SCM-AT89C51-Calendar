/* -----------------------------------------------------------
Copyright (C) 2016 Cheng Lyeec. All rights reserved.
 This software may be distributed and modified under the terms of the GNU
 General Public License version 2 (GPL2) as published by the Free Software
 Foundation and appearing in the file GPL2.TXT included in the packaging of
 this file. Please note that GPL2 Section 2[b] requires that all works based
 on this software must also be made publicly available under the terms of
 the GPL2 ("Copyleft").
 Contact information
 -------------------
 Cheng Lyeec
 Web      :  http://lyeec.me
 e-mail   :  hucxarch@gmail.com
 --------------------------------------------------------------*/
 
#include "lcd.h"

const unsigned char code DIG_CODE[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71, 0x40, 0x00};
//0、1、2、3、4、5、6、7、8、9、A、b、C、d、E、F

void DigDisplay(unsigned char* DisplayData){
	unsigned char i;
	unsigned int j;
	for(i=0;i<8;i++){
		GPIO_DIG_POS = (7-i)<<2; 
		GPIO_DIG_NUM = DIG_CODE[DisplayData[i]];
		for(j=10;j>0;j--);
		GPIO_DIG_NUM = 0x00;
	}
}

void DigStatusTransfer(unsigned char status, unsigned char* DisplayData){
	switch(status){
		case 1:
		case 4:
			DisplayData[7] = 17;
			DisplayData[6] = 17;
			break;
		case 2:
			DisplayData[3] = 17;
			DisplayData[4] = 17;
			break;
		case 3:
			DisplayData[0] = 17;
			DisplayData[1] = 17;
			break;
		case 5:
			DisplayData[5] = 17;
			DisplayData[4] = 17;			
			break;
		case 6:
			DisplayData[0] = 17;
			DisplayData[1] = 17;
			DisplayData[2] = 17;
			DisplayData[3] = 17;
		default:
			break;
	}
}