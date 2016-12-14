/*************************************
Program: Culture.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#ifndef _CULTURE
#define _CULTURE

#include "Att.h"

using namespace std;

class culture:public attraction{
private:
	string det;//detail
	string loc;//location name XXX
public:
	culture(string det, string loc);
	void display();
	string getname();
	string getcat();
};

#endif