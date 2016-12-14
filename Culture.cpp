/*************************************
Program: Culture.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "Culture.h"
#include <iostream>
using namespace std;
culture::culture(string det, string loc):attraction(100),det(det), loc(loc){}

void culture::display(){//display
	cout<<"\nCulture\n";
	cout<<det<<endl;
	cout<<loc<<endl<<endl;
}


string culture::getname(){
	return loc;
}

string culture::getcat(){
	return det;
}