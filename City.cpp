/*************************************
Program: City.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "City.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
using namespace std;
city::city(string name, LinkedList <attraction*> attractions) :name(name),attractions(attractions){}

void city::showshow(){
	bool match;
	LinkedList<int> uni;
	LinkedList<attraction*> att; 
	for(int i=1;i<=attractions.getLength();i++){
		match = true;
		for(int j=1;j<=uni.getLength();j++){
			if(attractions[i]->gettypeid() == uni[j])
				match = false;
		}
		if(match)
			uni.push_back(attractions[i]->gettypeid());
	}
	int num = 1;
	int input;
	bool ass = true;
	while(ass){
		for(int j=1;j<=uni.getLength();j++){
			if(uni[j] == 100 )
				cout<<j<<". Culture\n\n";
			else if(uni[j] == 200 )
				cout<<j<<". Shopping\n\n";
			else if(uni[j] == 300 )
				cout<<j<<". Sport\n\n";
		}
		break;
	}
}


void city::showadd(){
	system("cls");
	bool match;
	LinkedList<int> uni;
	LinkedList<attraction*> att; 

	for(int i=1;i<=attractions.getLength();i++){
		match = true;
		for(int j=1;j<=uni.getLength();j++){
			if(attractions[i]->gettypeid() == uni[j])
				match = false;
		}
		if(match)
			uni.push_back(attractions[i]->gettypeid());
	}
	int num = 1;
	int input;
	string s;
	bool ass = true;
	while(ass){
		do{
			system("cls");
			for(int j=1;j<=uni.getLength();j++){
				if(uni[j] == 100 )
					cout<<j<<". Culture\n\n";
				else if(uni[j] == 200 )
					cout<<j<<". Shopping\n\n";
				else if(uni[j] == 300 )
					cout<<j<<". Sport\n\n";
			}
			cout<<" 999 ----> Show ALL\n\n";
			cin.sync();
			cin>>input;
			if(input == 999){
				break;
			}else if(!cin.fail() && input>0  && input <= uni.getLength())
				break;
			else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n Invalid input, Please input again \n";
				system("pause");
			}
		}while(true);

		for(int i=1;i<=attractions.getLength();i++){
			if(input == 999){
				ass = false;
				attractions[i]->display();
			}else{
				if(uni[input] == attractions[i]->gettypeid()){
					system("cls");
					ass = false;
					att.push_back(attractions[i]);
					cout<<att.getLength()<<" "<<attractions[i]->getname()<<endl;
				}
			}
		}
	}
	if(input != 999){
		int jk = 0;
		do{
			system("cls");
			cout<<att.getLength()<<" "<<attractions[input]->getname()<<endl;
			cin.sync();
			cin>>jk;
			if(!cin.fail() && jk>0  && jk <= att.getLength())
				break;
			else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n Invalid input, Please input again \n";
				system("pause");
				cout<<"\n Please input again \n";
			}
		}while(true);

		att[jk]->display();

	}
	system("pause");
}

string city::getName(){
	return name;
}


void city::addAttraction(LinkedList <attraction*> addOn){
	for(int i=1;i<=addOn.getLength();i++)
		attractions.push_back(addOn[i]);
}


void city::revAttraction(){
	int size = attractions.getLength();
		for (int i = 1; i <= size; ++i)
		{
			attractions.remove(1);
		}
}


void city::delspec(int input){
	attractions.remove(input);
}


void city::getATT(LinkedList <attraction*> &adx){
	for(int i=1;i<=attractions.getLength();i++)	{
		adx.push_back(attractions[i]);
	}
}


int city::ATTSIZE(){
	return attractions.getLength();
}
