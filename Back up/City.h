/*************************************
Program: City.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include <vector>
#include <string>
#include "LinkedList.h"
#ifndef _CITY
#define _CITY

#include "Att.h"
using namespace std;

class city{
private:
	string name;
	LinkedList <attraction*> attractions;
public:
	city(string name, LinkedList <attraction*> attractions);
	void addAttraction(LinkedList <attraction*> attractions);
	void revAttraction();
	void showadd();
	string getName();
	void delspec(int input);
	void showshow();
	void getATT(LinkedList <attraction*> &attractions);
	int ATTSIZE();
};

#endif 