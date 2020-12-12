//
//  main.cpp
//  
//
//  Created by Rita Dang on 2/26/19.
//  Copyright © 2019 Rita Dang. All rights reserved.
//


#include <iostream>
#include <cassert>
#include "IntList.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the input integer n: ";
    cin >> n;
    
    if(n<=0){
        cout<<"The list is empty."<<endl;
    }
    else{
    
    List integers; //construct an empty list of integers
    
    for(int i=1; i<=n; i++){
        integers.push_back(i);
    }
    
    integers.print(); //print the constructed linked list
    
    integers.reverse(); //reverse the linked list
    
    integers.print(); //print all the elements in the reversed-list
    }
    
    return 0;
}
