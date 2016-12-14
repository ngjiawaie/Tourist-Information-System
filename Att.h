/*************************************
Program: Att.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include <string>
using namespace std;
#ifndef _ATT
#define _ATT

class attraction{
private:
	int id;
	int typeID;
public:
	int gettypeid();
	int getid();
	void setid(int id);
	virtual string getname() = 0;
	virtual string getcat() = 0;
	attraction(int typeID);
	virtual void display() = 0;
}; 

#endif
