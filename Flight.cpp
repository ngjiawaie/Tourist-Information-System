/*************************************
Program: Flight.cpp
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#include "Flight.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "LinkedList.h"
#include "LinkedStack.h"
using namespace std;


void Graph::display(){
    for(int i=1;i<=ct.getLength();i++)
            cout<<" "<<i<<" "<<ct.getEntry(i)<<endl;
}

bool Graph::isDirect(){
    return direct;
}

Graph::Graph()
{
    ifstream infile ("fff.txt");
    string valid;
    getline(infile,valid,'\n');
    stringstream P(valid);
    while(getline(P,valid,'\t')){
        ct.push(valid);
    }
    V = ct.getLength();
    adj = new int *[V];
    for(int i=0;i<V;i++){
        adj[i] = new int[V];
    }

    for(int j=0;j<V;j++){
        for(int k=0;k<V;k++){
            adj[j][k] = 0;
        }
    }

    int a=0,b=0;

    while(getline(infile,valid,'\n')){
        stringstream Z(valid);
        while(getline(Z,valid,'\t')){
            adj[a][b]=atoi(valid.c_str());
            b++;
        }
        b=0;
        a++;
    }

}

bool Graph::isReachable(int ORI, int DES)
{
    direct = false;
    ORI = ORI - 1;
    DES = DES - 1;
    int asd;
    if (ORI == DES){
        direct = true;
      return true;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    LinkedStack<int> okay;
    visited[ORI] = true;
    okay.push(ORI);
    while(!okay.isEmpty()){
        asd = okay.peek();
        okay.pop();
        for(int i=0;i<V;i++){
            if(adj[asd][i] == 1  && i == DES && !visited[i]){
                if(asd == ORI)
                    direct = true;
                return true;
            }
            if (adj[asd][i] == 1 && !visited[i]){
                visited[i] = true;
                okay.push(i);
            }
        }
    }
    return false;

}