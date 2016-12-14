/*************************************
Program: Shopping.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "Shopping.h"
#include <iostream>
using namespace std;
string shopping::getname(){
	return mall;
}

string shopping::getcat(){
	return det;
}

shopping::shopping(string det, string mall):attraction(200),det(det),mall(mall){}
void shopping::display(){//display
	cout<<"\nShopping\n";
	cout<<det<<endl;
	cout<<mall<<endl<<endl;
}