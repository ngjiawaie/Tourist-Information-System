/*************************************
Program: Shopping.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/

#ifndef _SHOPPING
#define _SHOPPING
#include "Att.h"
class shopping:public attraction{
private:
	string det;//detail
	string mall;//mall name XXX
public:
	string getname();
	string getcat();
	shopping(string det, string mall);
	void display();
};

#endif