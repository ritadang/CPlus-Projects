//
//  IntList.cpp
//  
//
//  Created by Rita Dang on 2/26/19.
//  Copyright © 2019 Rita Dang. All rights reserved.
//

#include <string>
#include <iostream>
#include <cassert>
#include "IntList.h"

using namespace std;

Node::Node(int num): number(num), previous(NULL), next(NULL){}

List::List(): first(NULL), last(NULL){}

void List::push_back(int num)
{
    Node* new_node = new Node(num);
    if (last == NULL) // List is empty
    {
        first = new_node;
        last = new_node;
    }
else
{
    new_node->previous = last;
    last->next = new_node;
    last = new_node;
}

}

void List::insert(Iterator iter, int num)
{
    if (iter.position == NULL)
    {
        push_back(num);
        return;
    }
    
    Node* after = iter.position;
    Node* before = after->previous;
    Node* new_node = new Node(num);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == NULL) // if inserting at beginning
        first = new_node;
    else
        before->next = new_node;
}

Iterator List::erase(Iterator iter)
{
    assert(iter.position != NULL);
    Node* remove = iter.position;
    Node* before = remove->previous;
    Node* after = remove->next;
    if (remove == first)
        first = after;
    else
        before->next = after;
    if (remove == last)
        last = before;
    else
        after->previous = before;
    delete remove;
    Iterator r;
    r.position = after;
    r.container = this;
    return r;
}

Iterator List::begin()
{
    Iterator iter;
    iter.position = first;
    iter.container = this;
    return iter;
}

Iterator List::end()
{
    Iterator iter;
    iter.position = NULL;
    iter.container = this;
    return iter;
}

void List::print() 
{
    assert(last != NULL); //make sure the list is not empty
    for(Iterator iter=begin(); iter.position!=NULL; iter.next()){
        cout<< iter.position->number << " ";
    }
    cout<<endl;
}

void List::reverse()
{
    assert(last != NULL); //make sure the list is not empty
    
    if(first==last){return;} //if the list contains only 1 element, return the original list
    
    Iterator iter=end();
    iter.previous(); //point to the last element of the list
    
    for(Iterator i=iter; i.position->previous != NULL; i.next()){
        Node* pos=i.position;
        Node* before=pos->previous;//make a copy of the pointer is originally before the element
        pos->previous=pos->next;
        pos->next=before;
    }
    
    first->previous=first->next;
    first->next=NULL;
    
    Node* pos=last; //make a copy of the pointer that points to the previously last element of the list
    last=first;
    first=pos;
    
}

Iterator::Iterator()
{
    position = NULL;
    container = NULL;
}

int Iterator::get() const
{
    assert(position != NULL);
    return position->number;
}

void Iterator::next()
{
    assert(position != NULL);
    position = position->next;
}

void Iterator::previous()
{
    assert(position != container->first);
    if (position == NULL)
        position = container->last;
    else
        position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
    return position == b.position;
}



