#include "Clock.h"
#include<iomanip>
#include<iostream>
#include<windows.h>
#include<time.h>
#include<string>
using namespace std;

Clock ::Clock(int hour, int min, int sec, string TZ,string timecon, Position pos)
{
	Init(hour, min, sec, TZ,timecon ,pos);
}
void Clock::Init(int hour, int min, int sec, string TZ,string timecon, Position pos)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
	this->TimeZone = TZ;
	this->timecon = timecon;
	this->Pos = pos;

}
void Clock::IncrementOneSecond()
{
	sec++;
	if (hour == 12 && min == 59 && sec == 59)
	{
		hour = 1;
		min = 0;
		sec = 0;

	}
	else if (hour == 11 && min == 59 && sec == 59)
	{
		hour = 12;
		min = 0;
		sec = 0;
		if (timecon == "AM")
		{
			timecon = "PM";
		}
		else
		{
			timecon = "AM";

		}
	}
	else
	{
		if (sec == 60)
		{
			sec = 0;
			min++;
		}
		if (min == 60)
		{
			min = 0;
			hour++;
		}
	}

}
void Clock:: DisplayClock()
{
	gotoRowCol(Pos.row, Pos.col);
	cout << this->TimeZone;
	gotoRowCol(Pos.row+1,Pos.col);
	cout <<setw(2) << left << this->hour << " : " <<
		setw(2)<<left<< this->min
		<< " : "<<setw(2)<<left<<
		this->sec<<setw(2)<<right<<timecon;

}
void Clock:: gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void Clock::Wait(int sec)
{
	long long prevClock = time(0);
	long long currClock = time(0);
	while (currClock-prevClock<=sec)
	{
		currClock = time(0);
	}

}
