//
//  main.cpp
//  
//
//  Created by Rita Dang on 2/19/19.
//  Copyright © 2019 Rita Dang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//recursive function that tests whether a string t is contained in a string s
bool find(string s, string t){
    
    //base condition
    if(s.length()<t.length()){
        return false;
    }
    
    
    if(s.substr(0,t.length())==t){
        return true;
    }
    else {
        string s_short=s.substr(1);
        return find(s_short,t); //must use return
    }
    
}

int main() {
    
    bool b=find("Mississippi!", "sip");
    cout << b << endl;
    
    return 0;
}
