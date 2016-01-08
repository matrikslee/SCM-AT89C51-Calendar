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
 
#include "key.h"
#include "delay.h"

sbit K1 = P3^1;
sbit K2 = P3^0;
sbit K3 = P3^2;
sbit K4 = P3^3;

unsigned char keyScan(){
	unsigned char i, j;
	i = j = 0;
	if(K1==0){
		Delay10ms();
		if(K1==0) { i = 1; }
		while((j<50)&&(K1==0))
		{
			Delay10ms();
			j++;
		}
	}
	if(K2==0){
		Delay10ms();
		if(K2==0) { i = 2; }
		while((j<50)&&(K2==0))
		{
			Delay10ms();
			j++;
		}
	}
	if(K3==0){
		Delay10ms();
		if(K3==0) { i = 3; }
		while((j<50)&&(K3==0))
		{
			Delay10ms();
			j++;
		}
	}
	if(K4==0){
		Delay10ms();
		if(K4==0) { i = 4; }
		while((j<50)&&(K4==0))
		{
			Delay10ms();
			j++;
		}
	}	
	return i;
}