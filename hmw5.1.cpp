//
//  main.cpp
//  hmw5.1
//
//  Created by Rita Dang on 3/13/19.
//  Copyright © 2019 Rita Dang. All rights reserved.
//


#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;


//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
vector<int> two_sum(int a[], int a_size, int target){
    vector<int> result;
    map<int,int>::iterator pos;
    map<int,int> solutions; //map key is the number in the array, map value is the index of that number
    for(int i=0; i<a_size; i++){
        int complement= target-a[i];
        pos=solutions.begin();
        pos=solutions.find(complement);
        //if we cannot find that complementary number in the map(we haven't seen it yet), we save the number and its index to the map for later
        if(pos==solutions.end()){
            solutions[a[i]]=i;
        }
        else{//if we find its complementary in the map(we have seen it before)
            result.push_back(solutions[complement]);
            result.push_back(i);
            return result;
        }
    }
    
    return result;
}

int main() {
    
    int nums[]={2,7,11,15};
    int size=4;
    int sum=9;
    
    vector<int> indices=two_sum(nums,size,sum);
    
    //print the given array and results
    cout << "Given nums = [";
    for(int i=0; i<size-1; i++){
        cout<<nums[i]<<", ";
    }
    cout << nums[size-1]<<"], target = " << sum << ",\n";
    cout << "Because nums[" << indices[0] << "] + nums[" << indices[1] << "] = " << nums[indices[0]] << " + " << nums[indices[1]] << " = " << sum << ",\n";
    
    cout<<"return [" << indices[0] << ", " << indices[1] << "]." <<endl;
    
    
    
    return 0;
}
