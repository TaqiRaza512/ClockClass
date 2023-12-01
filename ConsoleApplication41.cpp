#include<iostream>
#include"Clock.h"
#include<fstream>
using namespace std;

void ReadAllClock(Clock* &Cs,int &size,ifstream &rdr)
{
	int hour, min, sec;
	Position pos;
	string TZ;
	string timecon;

	rdr >> size;
	Cs = new Clock[size];

	for (int ri=0;ri<size;ri++)
	{
		rdr >> hour >> min >> sec >> TZ>>timecon>>pos.row >> pos.col;
	
		Cs[ri].Init(hour,min,sec,TZ,timecon,pos);
	}
}
void DisplayAllClock(Clock* Cs,int size)
{
	for (int i=0;i<size;i++)
	{
		Cs[i].DisplayClock();
	}
}
void IncrementAllClocks(Clock* Cs,int size)
{
	for (int i=0;i<size;i++)
	{
		Cs[i].IncrementOneSecond();

	}
}
int main()
{
	int size=0;
	Clock* Cs;
	ifstream rdr("Clock.txt");
	ReadAllClock(Cs, size, rdr);
	
	while (true)
	{
		DisplayAllClock(Cs, size);
		Clock::Wait(0.5);
		IncrementAllClocks(Cs, size);
		
	}
}