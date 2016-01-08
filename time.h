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
 

#ifndef __USER_H__
#define __USER_H__

typedef struct {
	short year;
	char month;
	char day;	
	char hour;
	char minute;
	char second;
} timeTypeDef;

typedef void(*timeModifyType)(timeTypeDef* t);

void timeSet(timeTypeDef* t, short y, char mon, char d, char h, char m, char s);
void timeTransferOutput(const timeTypeDef* t, unsigned char mode, unsigned char* displayData);

char isLeapYear(char year);
void incSecond(timeTypeDef* t);
void incMinute(timeTypeDef* t);
void incHour(timeTypeDef* t);
void incDay(timeTypeDef* t);
void incMonth(timeTypeDef* t);
void incYear(timeTypeDef* t);

void setSecondZero(timeTypeDef* t);
void decMinute(timeTypeDef* t);
void decHour(timeTypeDef* t);
void decDay(timeTypeDef* t);
void decMonth(timeTypeDef* t);
void decYear(timeTypeDef* t);

void timeInc(timeTypeDef* t, unsigned char modifyTypeIndex);
void timeDec(timeTypeDef* t, unsigned char modifyTypeIndex);

#endif
