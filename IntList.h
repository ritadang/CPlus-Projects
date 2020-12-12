//
//  IntList.h
//  
//
//  Created by Rita Dang on 2/26/19.
//  Copyright © 2019 Rita Dang. All rights reserved.
//

#ifndef IntList_h
#define IntList_h

#include <iostream>


using namespace std;

class List;
class Iterator;

class Node
{
public:
    Node(int num);
private:
    int number;
    Node* previous;
    Node* next;
friend class List;
friend class Iterator;
};

class List
{
public:
    List(); //constructs an empty list
    void push_back(int num);
    void insert(Iterator iter, int num);
    void print();
    void reverse();
    Iterator erase(Iterator iter);
    Iterator begin();
    Iterator end();
private:
    Node* first;
    Node* last;
friend class Iterator;
};

class Iterator
{
public:
    Iterator(); //constructs an iterator that does not point into any list.
    int get() const;
    void next();
    void previous();
    bool equals(Iterator b) const;
private:
    Node* position;
    List* container;
friend class List;
};




#endif /* Int_list_h */
