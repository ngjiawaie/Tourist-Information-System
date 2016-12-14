/*************************************
Program: Att.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "Att.h"
using namespace std;

int attraction::gettypeid(){
	return typeID;
}
int attraction::getid(){
	return id;
}
void attraction::setid(int id){
	this->id=id;
}
	
attraction::attraction(int typeID):typeID(typeID){}