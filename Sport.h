/*************************************
Program: Sport.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#ifndef _SPORT
#define _SPORT
#include "Att.h"

class sport:public attraction{
private:
	string det;//detail
	string more;//more detail of sport XXX
public:
	string getname();
	string getcat();
	sport(string det,string more);
	void display();
};

#endif