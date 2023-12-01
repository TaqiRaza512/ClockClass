#pragma once
#include<iostream>
using namespace std;

struct Position
{
	int row, col;
};
class Clock
{
private:
	int hour, min, sec;
	string TimeZone;
	string timecon;

	Position Pos{};
public:
	Clock(int hour=0, int min=0, int sec=0, string TZ="",string timecon="", Position pos={});
	void Init(int hour = 0, int min = 0, int sec = 0, string TZ = "",string timecon="", Position pos = {});
	void IncrementOneSecond();
	void DisplayClock();
	static void Wait(int sec);
	static void gotoRowCol (int row,int col);


};

