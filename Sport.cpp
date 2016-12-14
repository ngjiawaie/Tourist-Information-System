/*************************************
Program: Sport.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "Sport.h"
#include <iostream>
using namespace std;

string sport::getname(){
	return more;
}

string sport::getcat(){
	return det;
}

sport::sport(string det,string more):attraction(300),det(det),more(more){}
void sport::display(){
	cout<<"\nSport\n";
	cout<<det<<endl;
	cout<<more<<endl<<endl;
}