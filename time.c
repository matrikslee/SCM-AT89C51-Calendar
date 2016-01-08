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
 
#include "time.h"

code const char daysPerMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
code const timeModifyType timeIncList[7] = {0x00, setSecondZero, incMinute, incHour, incDay, incMonth, incYear};
code const timeModifyType timeDecList[7] = {0x00, setSecondZero, decMinute, decHour, decDay, decMonth, decYear};
	
void timeSet(timeTypeDef* t, short y, char mon, char d, char h, char m, char s){
	t->year = y;
	t->month = mon;
	t->day = d;
	t->hour = h;
	t->minute = m;
	t->second = s;
}

char isLeapYear(char year){
	if((year%400==0) || (year%4==0&&year%100!=0)){ return 1; }
	return 0;
}

void incSecond(timeTypeDef* t){
	if(++t->second >= 60) {
		t->second = 0;
		incMinute(t);
	}
}

void incMinute(timeTypeDef* t){
	if(++t->minute >= 60) {
		t->minute = 0;
		incHour(t);
	}
}

void incHour(timeTypeDef* t){
	if(++t->hour >= 24){
		t->hour = 0;
		incDay(t);
	}
}

void incDay(timeTypeDef* t){
	char daysInThisMonth = daysPerMonth[t->month]+((t->month==2&&isLeapYear(t->year)==1)?1:0);
	if(++t->day > daysInThisMonth){
		t->day = 1;
		incMonth(t);
	}
}

void incMonth(timeTypeDef* t){
	if(++t->month > 12){
		t->month = 1;
		incYear(t);
	}
}

void incYear(timeTypeDef* t){
	++t->year;
}

void setSecondZero(timeTypeDef* t){
	t->second = 0;
}
void decMinute(timeTypeDef* t){
	if(--t->minute < 0){
		t->minute = 59;
	}
}
void decHour(timeTypeDef* t){
	if(--t->hour < 0){
		t->hour = 23;
	}
}
void decDay(timeTypeDef* t){
	if(--t->day < 0){
		t->day = daysPerMonth[t->month]+((t->month==2&&isLeapYear(t->year)==1)?1:0);
	}
}
void decMonth(timeTypeDef* t){
	if(--t->month < 0){
		t->month = 12;
	}
}

void decYear(timeTypeDef* t){
	if(--t->year < 1970){
		t->year = 1970;
	}
}

void timeTransferOutput(const timeTypeDef* t, unsigned char mode, unsigned char* displayData){
	if(mode==0){
		displayData[0] = (t->hour/10)%10;
		displayData[1] = (t->hour)%10;
		displayData[2] = 16;
		displayData[3] = (t->minute/10)%10;
		displayData[4] = (t->minute)%10;
		displayData[5] = 16;
		displayData[6] = (t->second/10)%10;
		displayData[7] = (t->second)%10;
	} else {
		displayData[0] = (t->year/1000)%10;
		displayData[1] = (t->year/100)%10;
		displayData[2] = (t->year/10)%10;
		displayData[3] = (t->year)%10;
		displayData[4] = (t->month/10)%10;
		displayData[5] = (t->month)%10;
		displayData[6] = (t->day/10)%10;
		displayData[7] = (t->day)%10;
	}
}

void timeInc(timeTypeDef* t, unsigned char modifyTypeIndex){
	timeIncList[modifyTypeIndex](t);
}
void timeDec(timeTypeDef* t, unsigned char modifyTypeIndex){
	timeDecList[modifyTypeIndex](t);
}