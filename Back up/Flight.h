/*************************************
Program: Flight.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#ifndef _FLIGHT
#define _FLIGHT

// This class represents a directed graph using adjacency list
// representation
class Graph
{   
    LinkedList<string> ct;
    bool direct;
    int V;    // No. of vertices
    int **adj;    // 2D array
public:
    Graph();  // Constructor
    bool isReachable(int ORI, int DES);
    bool isDirect();
    void display();
};
#endif