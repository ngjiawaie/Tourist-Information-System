/*************************************
Program: MAIN.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "City.h"
#include "City.cpp"
#include "Culture.h"
#include "Culture.cpp"
#include "Shopping.h"
#include "Shopping.cpp"
#include "Sport.h"
#include "Sport.cpp"
#include "LinkedStack.h"
#include "LinkedList.h"
#include "Flight.h"
#include "Att.cpp"
#include "Flight.cpp"
using namespace std;


void menu(){
	system("cls");
	cout<<"\t    		 	 Tourist Information System		    \n";
	cout<<"\t 		Please Enter the no. for choose the option,\n ";
	cout<<"\n\t\t\t\t Enter 911 to Quit Program,";
	cout<<"\n\t\t\t\t Enter 100 to Check Flight, ";
	cout<<"\n\t\t\t\t Enter 101 to Administration \n\n";
}


int main(){
	while(true){
		string CT;
		menu();
		ifstream infile ("data.txt"); //import file
		LinkedList<attraction*> aaa; //new attraction
		LinkedList<city*> x; // new city
		LinkedList<string> data;//store temp data
		string b;

		while(getline(infile,b,'\n')){
			data.push_back(b);
		for(int i=1;i<=3 && getline(infile,b,'\n');i++){ //sync all data
			data.push_back(b);
		}

		if(data[2]== "Sport")
			aaa.push_back(new sport(data[3],data[4])); // inputtt
		else if(data[2]== "Culture")//display
			aaa.push_back(new culture(data[3],data[4]));
		else if(data[2]== "Shopping")
			aaa.push_back(new shopping(data[3],data[4]));

		bool exist = false;
		for(int i = 1;i<=x.getLength() && !exist;i++){
			if(data[1] == x[i]->getName()){
				x[i]->addAttraction(aaa);// add attraction, get from textfile
				exist = true;
			}
		}
		if(!exist)
			x.push_back(new city(data[1],aaa));

		data.clear();
		aaa.clear();
	}
	infile.close();

	for(int i=1;i<=x.getLength();i++){
		for(int z=x.getLength();z>i;z--){
			if(toupper(x[i]->getName()[0]) > toupper(x[z]->getName()[0])){ // compare the first alphabet of the city
				x.swap(i,z); // CALL SORT FUNCTION
			}
		}
	}

	for(int i=1;i<=x.getLength();i++)
		cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;

	int input;
	int toedit;
	cout<<endl;
	cin.sync();
	cin>>input;
	cin.clear();
	cin.sync();

	if (input == 911){
		cout<< "\n Goodbye... \n"; //end
		exit(0);

	}else if (input == 100){
		
			int u,v;
			Graph g;//create a graph for flight

		do{
			system("cls");
			cout<< "\n Flight Path \n  ";
			cout<<"\n";
			for(int i=1;i<=x.getLength();i++)
					cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;
			cout<<"\n Origin --->";
			cin.sync();
			cin>>u;
			cout<<"\n Destination --->";
			cin.sync();
			cin>>v;

			if(!cin.fail() && v>0 && u>0 && u<= x.getLength() && v<= x.getLength())
				break;
			else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n Invalid input, Please input again \n";
				system("pause");
			}
		}while(true);

		if(g.isReachable(u, v)){
			if(g.isDirect())
				cout<< "\n There is direct path from " << u << " to " << v<<endl;
			else
				cout<< "\n There is an indirect path from " << u << " to " << v<<endl;
		}
		else
			cout<< "\n There is no path from " << u << " to " << v<<endl;
		system("pause");
	}
	else if(input == 101){ // Admin MODE
		system("cls");
		bool okay = false;
		int in; //option
		int newinput =0;

		do{
			system("cls");
			cout<<"            Admin Panel            \n";
			cout<<" 1.   Add new City    \n";
			cout<<" 2.   Remove Existing City \n";
			cout<<" 3.   Edit Existing City  &  Attraction\n";
			cout<<" 4.   Edit Flight\n";
			cin.sync();
			cin>>in;
			if(!cin.fail() && in > 0 && in < 5)
				break;
			else{
				cin.clear();
				cin.ignore(1000,'\n');
				cout<<"\n Invalid input, Please input again \n";
				system("pause");
			}
		}while(true);

		if(in == 1){ //Add new City 
			system("cls");// Excatly Same with the early part load city from txt file
			cout<<" Add New City :    \n";
			string ctname;  
			string typeatt;
			string detail;
			string ttt;

			cout<<" Add City's Name\n";
			cin.sync();
			cin>>ctname;

			cout<<"\n City Attraction Type Option : Culture, Shopping, Sport";
			cout<<"\n Input either 1 Of the 3 option Above Exactly\n\n";
			cout<<" Add City Attraction Type\n";

			do{
				cin.sync();
				cin>>typeatt;
			}while(!(typeatt == "Sport" || typeatt == "Culture" || typeatt == "Shopping"));
			cout<<endl;
			cout<<" Add Attraction's Detail\n";
			cin.sync();
			cin>>detail;
			cout<<endl;
			cout<<" Add Attraction's Catogories\n";
			cin.sync();
			cin>>ttt;
			cout<<endl;
			string adding;
			int getok;
			if(typeatt == "Sport")
				aaa.push_back(new sport(detail,ttt));
			else if(typeatt == "Culture")
				aaa.push_back(new culture(detail,ttt));
			else if(typeatt == "Shopping")
				aaa.push_back(new shopping(detail,ttt));
			x.push_back(new city(ctname,aaa));
			aaa.clear();

			fstream readz("data.txt");
			ofstream writez("temp.txt");
			LinkedList<attraction*> ioi; // store temp city attraction
			for(int i=1;i<=x.getLength();i++){
				x[i]->getATT(ioi);
				for (int j = 1; j <= ioi.getLength(); ++j)
				{
					string a;
					if(ioi[j]->gettypeid() == 100)
						a = "Culture";
					else if(ioi[j]->gettypeid() == 200)
						a = "Shopping";
					else if(ioi[j]->gettypeid() == 300)
						a = "Sport";
					writez<<x[i]->getName()<<endl<<a<<endl<<ioi[j]->getcat()<<endl<<ioi[j]->getname()<<endl;
				}
				ioi.clear();
			}

			readz.close();
			writez.close();
			remove ("data.txt");
			rename("temp.txt","data.txt");
			cout<<"\n Operation Successfull And Saved \n";
			system("pause");
			system("cls");
			cout<< "\n  Add Flight\n";
			cin.sync();
				
			LinkedList<int> flighto;//to save temp flight data
			ifstream read("fff.txt");
			ofstream write("temp.txt");
			getline(read,adding,'\n');
			write <<adding<<"\t"<< x[x.getLength()]->getName() <<endl;

			for(int i = 1;i<=x.getLength();i++){
				do{
					system("cls");
					cout<< "\n 1 - Connected\t\t 0 - Not Connected      \n";
					cout<<"\n Is " << x[x.getLength()]->getName()<<" connected with "<<x[i]->getName()<<"  ";
					cin.sync();
					cin>>getok;

					if(!cin.fail() && getok <= 1 && in >=0 )
						break;
					else{
						cin.clear();
						cin.ignore(1000,'\n');
						cout<<"\n Invalid input, Please input again \n";
						system("pause");
					}
				}while(true);
				flighto.push_back(getok);
			}
			
			int c = 1;
			while(getline(read,adding,'\n')){
				write<<adding<<"\t"<<flighto[c]<<endl;
				c++;
			}

			for(int j=1;j<=flighto.getLength();j++){
				write<<flighto[j]<<"\t";
			}
			read.close();
			write.close();
			remove ("fff.txt");
			rename("temp.txt","fff.txt");
			cout<<"\n Added Successfully And Saved\n";
			system("pause");
		}else if(in == 2){//Remove Existing City
			string masuk;
			do{
				system("cls");
				cout<<" Remove Existing City :\n";
				for(int i=1;i<=x.getLength();i++)
					cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;
				cout<<" \nEnter City to Delete---> \n";
				cin.sync();
				cin>>newinput;
				if(!cin.fail() && newinput >=1 && newinput <= x.getLength())
					break;
				else{
					cin.clear();
					cin.ignore(1000,'\n');
				}
			}while(true);

			x[newinput]->revAttraction(); // remove all attraction
			string savename;
			savename = x[newinput]->getName();
			x.remove(newinput);
			ifstream readd("data.txt"); // save the city and all data to the data file
			ofstream writee("temp.txt");
			LinkedList<attraction*> ioi;

			for(int i=1;i<=x.getLength();i++){
				x[i]->getATT(ioi);
				for (int j = 1; j <= ioi.getLength(); ++j)
				{
					string a;
					if(ioi[j]->gettypeid() == 100)
						a = "Culture";
					else if(ioi[j]->gettypeid() == 200)
						a = "Shopping";
					else if(ioi[j]->gettypeid() == 300)
						a = "Sport";
					writee<<x[i]->getName()<<endl<<a<<endl<<ioi[j]->getcat()<<endl<<ioi[j]->getname()<<endl;
				}
				ioi.clear();
			}
			readd.close();
			writee.close();
			remove ("data.txt");
			rename("temp.txt","data.txt");

			ifstream ak("fff.txt"); // save the flight txt file
			ofstream bk("temp.txt");
			int count = 0;
			int position;	
			int plpl = 0;
			int token = 0;
			getline(ak,masuk,'\n');
			stringstream Z(masuk);
			while(getline(Z,masuk,'\t')){
				token++;
				if(masuk == savename){
					position = token;
					continue;
				}
				bk <<masuk <<"\t";
			}
			bk<<endl;

			while(getline(ak,masuk,'\n')){
					plpl++;
				if(plpl == position){
					continue;
				}
				istringstream L(masuk);
				while(getline(L,masuk,'\t')){
					count++;
					if(count == position){
						continue;
					}
					bk<<masuk<<"\t";
				}
				bk<<endl;
				count = 0;
			}
			ak.close();
			bk.close();
			remove ("fff.txt");
			rename("temp.txt","fff.txt");
			cout<<"\n Delete Successfully And Saved\n";
			cout<<"\n Operation Successfull And Saved \n";
			system("pause");

		}else if(in==3){//Edit Existing City  &  Attraction
			do{
				system("cls");
				cout<<" City to be Edit\n";
				for(int i=1;i<=x.getLength();i++)
					cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;
				cin.sync();
				cin>>newinput;
				if(!cin.fail() && newinput>0 && newinput<=x.getLength())
					break;
				else{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"\n Invalid input, Please input again \n";
					system("pause");
				}
			}while(true);
			system("cls");
			int qwerty;
			int todel;
			do{
				system("cls");
				cout<<"\t City : "<<x[newinput]->getName()<<endl;
				cout<<"\n  1 --->    To Delete Specific Attraction\n  2 --->    To Delete All Attraction\n  3 --->    To Edit Specific Attraction\n  4 --->    To Add New Attraction\n\n";
				cin.sync();
				cin>>qwerty;
				if(!cin.fail() && qwerty > 0 && qwerty<5)
					break;
				else{
					cin.clear();
					cin.ignore(1000,'\n');
					cout<<"\n Invalid input, Please input again \n";
					system("pause");
				}
			}while(true);
				if(qwerty == 2){//To Delete Specific attraction
					x[newinput]->revAttraction();
					cout<<"\n Delete All Attraction Successfully And Saved\n";
				}else if(qwerty == 1){ //To Delete Specific attraction
					do{
						system("cls");
						cout<<"\t City : "<<x[newinput]->getName()<<endl;
						x[newinput]->showshow();
						cout<<"\n Attraction to Delete \n";
						cin.sync();
						cin>>todel;

						if(!cin.fail() && todel <= x[newinput]->ATTSIZE() && todel >0)
							break;
						else{
							cin.clear();
							cin.ignore(1000,'\n');
							cout<<"\n Invalid input, Please input again \n";
							system("pause");
						}
					}while(true);
					x[newinput]->delspec(todel);
					cout<<"\n Delete Successfully And Saved\n";
				}else if(qwerty == 3){//To Edit Specific attraction
					do{
						system("cls");
						cout<<"\t City : "<<x[newinput]->getName()<<endl;
						x[newinput]->showshow();
						cout<<"\n Attraction to Edit \n";
						cin.sync();
						cin>>toedit;
						x[newinput]->delspec(toedit);

						if(!cin.fail() && toedit <= x[newinput]->ATTSIZE() && toedit >0)
							break;
						else{
							cin.clear();
							cin.ignore(1000,'\n');
							cout<<"\n Invalid input, Please input again \n";
							system("pause");
						}

					}while(true);
					system("cls");
					cout<<"\t City : "<<x[newinput]->getName()<<endl;
					string typeatt;
					string detail;
					string ttt;
					cout<<"\n City Attraction Type Options : Culture, Shopping, Sport";
					cout<<"\n Input either 1 option from the options Above Exactly\n\n";
					cout<<" Add City Attraction Type\n";
					do{
						cin.sync();
						cin>>typeatt;
					}while(!(typeatt == "Sport" || typeatt == "Culture" || typeatt == "Shopping"));
					cout<<" Add Attraction's Detail\n";
					cin.sync();
					cin>>detail;
					cout<<" Add Attraction's Catogories\n";
					cin.sync();
					cin>>ttt;
					if(typeatt == "Sport")
						aaa.push_back(new sport(detail,ttt));
					else if(typeatt == "Culture")
						aaa.push_back(new culture(detail,ttt));
					else if(typeatt == "Shopping")
						aaa.push_back(new shopping(detail,ttt));
					x[newinput]->addAttraction(aaa);
					aaa.clear();
				}else if (qwerty == 4){//To Add New Attraction
					system("cls");
					cout<<"\t City : "<<x[newinput]->getName()<<endl;
					string typeatt;
					string detail;
					string ttt;
					cout<<"\n City Attraction Type Options : Culture, Shopping, Sport";
					cout<<"\n Input either 1 option from the options Above Exactly\n\n";
					cout<<" Add City Attraction Type\n";

					do{
						cin.sync();
						cin>>typeatt;
					}while(!(typeatt == "Sport" || typeatt == "Culture" || typeatt == "Shopping"));

					cout<<" Add Attraction's Detail\n";
					cin.sync();
					cin>>detail;

					cout<<" Add Attraction's Catogories\n";
					cin.sync();
					cin>>ttt;

					if(typeatt == "Sport")
						aaa.push_back(new sport(detail,ttt));
					else if(typeatt == "Culture")
						aaa.push_back(new culture(detail,ttt));
					else if(typeatt == "Shopping")
						aaa.push_back(new shopping(detail,ttt));
					x[newinput]->addAttraction(aaa);
					aaa.clear();
				}

				ifstream read("data.txt");
				ofstream write("temp.txt");
				LinkedList<attraction*> ioi;

				for(int i=1;i<=x.getLength();i++){
					x[i]->getATT(ioi);
					for (int j = 1; j <= ioi.getLength(); ++j)
					{
						string a;
						if(ioi[j]->gettypeid() == 100)
							a = "Culture";
						else if(ioi[j]->gettypeid() == 200)
							a = "Shopping";
						else if(ioi[j]->gettypeid() == 300)
							a = "Sport";
						write<<x[i]->getName()<<endl<<a<<endl<<ioi[j]->getcat()<<endl<<ioi[j]->getname()<<endl;
					}
					ioi.clear();
				}

				read.close();
				write.close();
				remove ("data.txt");
				rename("temp.txt","data.txt");
				cout<<"\n Operation Successfull And Saved \n";
				system("pause");
				system("cls");
				menu();
				for(int i=1;i<=x.getLength();i++)
					cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;
				cin.sync();
				cin>>newinput;
				if(x[newinput]->ATTSIZE() != 0)
					x[newinput]->showadd();
				else{
					cout<<"\n No Attractions is In "<<x[newinput]->getName()<<endl;
					cout<<" "<<x[newinput]->getName()<<" is Deleted"<<endl;
					system("pause");
				}
			}else if(in==4){ //Edit Flight
				int count = 0;
				int position=1;	
				int plpl = 0;
				int token = 0;
				int getok;
				string savename;
				string masuk;
				LinkedList<int> flightoo;
				do{
					system("cls");
					cout<< "\n Edit City's Flight\n\n";
					for(int i=1;i<=x.getLength();i++)
						cout<<"\t\t\t\t "<<i<<". "<<x[i]->getName()<<endl;
					cin.sync();
					cin>>newinput;
					if(!cin.fail() && newinput <= x.getLength() && newinput >0)
							break;
						else{
							cin.clear();
							cin.ignore(1000,'\n');
							cout<<"\n Invalid input, Please input again \n";
							system("pause");
						}
				}while(true);
				savename = x[newinput]->getName();
				ifstream oppen("fff.txt");
				getline(oppen,masuk,'\n');
				istringstream aaaaa(masuk);
				while(getline(aaaaa,masuk,'\t')){
					if(masuk == savename){
						break;
					}
					position++;
				}
				oppen.close();
				for(int i = 1;i<=x.getLength();i++){
					system("cls");
					cout<< "\n 1 - Connected\t\t 0 - Not Connected      \n";
					cout<<"\n Is "<<savename<<" connected with "<<x[i]->getName()<<" city  ";
					cin.sync();
					cin>>getok;
					if(getok == 1)
						flightoo.push_back(1);
					else
						flightoo.push_back(0);
				}
				ifstream read("fff.txt");
				ofstream write("temp.txt");
				getline(read,masuk,'\n');
				write <<masuk <<"\n";
				int countz;
				int ggg=0;
				int x =1;
				while(getline(read,masuk,'\n')){
					ggg++;
					if(position == ggg){
						for(int i=1;i<=flightoo.getLength();i++){
							write << flightoo[i] << "\t";
						}
						write << endl;
						x++;
					} else {
						countz = 0;
						istringstream ssss(masuk);
						while(getline(ssss,masuk,'\t')){
							countz++;
							if(countz == position)
								write << flightoo[x++] << "\t";
							else
								write << masuk << "\t";						
						}
						write << endl;
					}
				}
				read.close();
				write.close();
				remove ("fff.txt");
				rename("temp.txt","fff.txt");
				cout<<"\n Success \n";
				system("pause");				
			}
				menu();
		}else if(input>=1 && input <= x.getLength()) // Go into the city's attraction
			x[input]->showadd();
		else{
			cout<<"\n Invalid input... Enter Input Again \n";
			system("pause");
		}
	}
}