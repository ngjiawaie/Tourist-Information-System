/*************************************
Program: LinkedLish.h
Course: OOPDS
Year: 2015/16 Trimester 2
Name: NG JIA WAIE
ID: 11427 00826
Lecture: TC02
Lab: TT04
Email: ngjiawaie@gmail.com
Phone: 016-950 1305
*************************************/
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"

template<class ItemType>
class LinkedList
{
private:
   Node<ItemType>* headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   Node<ItemType>* getNodeAt(int position) const;

public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   ItemType getEntry(int position) const;
   void setEntry(int position, const ItemType& newEntry);
   bool push_back(const ItemType& newEntry);
   ItemType operator[] (int position);
   bool push(const ItemType& newEntry);
   void pop();
   void swap(int a,int b);
   
}; // end LinkedList

#include "LinkedList.cpp"
#endif 
