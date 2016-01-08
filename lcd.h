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
 
#ifndef __LCD_H__
#define __LCD_H__

#include<reg51.h>

#define GPIO_DIG_NUM P0
#define GPIO_DIG_POS P2

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void DigStatusTransfer(unsigned char status, unsigned char* DisplayData);
void DigDisplay(unsigned char* DisplayData); //¶¯Ì¬ÏÔÊ¾º¯Êý

#endif
