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
 
#include "pit.h"
#include "time.h"

void Timer0Configuration()
{
    TMOD = 0x01; //选择工作方式1
    TH0 = 0xB1;	 //设置初始值
    TL0 = 0xDF; 
    EA = 1;			 //打开总中断
    ET0 = 1;		 //打开定时器0中断
    TR0 = 1;		 //启动定时器0
}
 
void Timer0Per1Ms() interrupt 1
{
	static unsigned char x = 0;
	TH0 = 0xB1;	 //设置初始值 20MS
  TL0 = 0xDF;
	x = (x+1)%50;
	if(x==0){
		incSecond(&time);
	}
}