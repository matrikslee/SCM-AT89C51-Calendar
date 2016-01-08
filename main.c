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
 
#include<reg51.h>
#include "time.h"
#include "lcd.h"
#include "pit.h"
#include "key.h"
#include "delay.h"

unsigned char displayData[8];

timeTypeDef time;
unsigned char tmp;
unsigned char mode;
unsigned char setStatus;

const unsigned int freqMode = 200;
unsigned int freqCnt;

void main(void){
	freqCnt = 0;
	mode = 0;
	setStatus = 0;
	Timer0Configuration();
	timeSet(&time, 2008, 2, 28, 23, 59, 56);
	while(1) {
		tmp = keyScan();
		switch(tmp){
			case 1:
				if(setStatus==0) { mode = (mode+1)%2; }
				break;
			case 2:
				setStatus = (setStatus+1)%7;
				mode = (setStatus>3?1:0);
				break;
			case 3:
				if(setStatus!=0){
					timeInc(&time, setStatus);
				}
				break;
			case 4:
				if(setStatus!=0){
					timeDec(&time, setStatus);
				}
				break;
			default:break;
		}
		timeTransferOutput(&time, mode, displayData);
		freqCnt = (freqCnt+1)%freqMode;
		if(setStatus!=0) {
			if(freqCnt>=freqMode/2) {
				DigStatusTransfer(setStatus, displayData);
			}
		}
		DigDisplay(displayData);
	}
}
