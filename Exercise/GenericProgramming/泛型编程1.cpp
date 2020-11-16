//
//  main.cpp
//  Test2
//
//  Created by 葛亮 on 2020/5/12.
//  Copyright  2020 葛亮. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <functional>
using namespace std;

template <
    typename compareFuncType,
    typename valueType,
    typename inputIterator,
    typename outputIterator
>
outputIterator filter(
                         inputIterator begin,
                         inputIterator end,
                         outputIterator at,
                         valueType compareValue,
                         compareFuncType compareFunc
                         ){
    
    
    for(inputIterator iter=begin; iter!=end; iter++){
        if(compareFunc(*iter, compareValue)){
            *at = *iter;
            at++;
        }
    }
    return at;
}

bool greaterThan(int x, int y){
    return x>y;
}

bool lessThan(int x, int y){
    return x<y;
}

class LessThanObj{
public:
    bool operator()(int x, int y){
        return x<y;
    }
};

class Box{
public:
    Box(int x1, int y1, int z1):x(x1),y(y1),z(z1){
    }
    bool operator<(const Box& b2) const{
        return x*y*z < b2.x*b2.y*b2.z;
    }
    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
    int getZ() const{
        return z;
    }
private:
    int x;
    int y;
    int z;
};

int main(){
    vector<int> a;
    a.push_back(10);
    a.push_back(3);
    a.push_back(2);
    a.push_back(4);
    a.push_back(8);
    a.push_back(9);
    a.push_back(6);
    
    cout<<"a: ";
    for(int x : a){
        cout<<x<<" ";
    }
    cout<<endl;
    
//    vector<int> b = filter(a, 7, lessThan);
//    LessThanObj lt;
    vector<int> b(7);
    filter(a.begin(), a.end(), b.begin(), 7, less<int>());
    cout<<"b: ";
    for(int x : b){
        cout<<x<<" ";
    }
    cout<<endl;
    
    char c1[5] = {'a', 'z', 'b', 'e', 'g'};
    cout<<"c1: ";
    for(char x : c1){
        cout<<x<<" ";
    }
    cout<<endl;
        
    char c2[5];
    filter(c1, c1+5, c2, 'f', less<char>());
    cout<<"c2: ";
    for(char x : c2){
        cout<<x<<" ";
    }
    cout<<endl;
    
//    list<Box> b1;
//    b1.push_back(Box(1,2,3));
//    b1.push_back(Box(2,2,3));
//    b1.push_back(Box(2,3,4));
//    b1.push_back(Box(3,4,5));
//    b1.push_back(Box(3,3,3));
//    cout<<"b1:";
//    for(Box b : b1){
//        cout<<"("<<b.getX()<<","<<b.getY()<<","<<b.getZ()<<")";
//    }
//    cout<<endl;
//
//    list<Box> b2 = filter(b1, Box(2,2,2), less<Box>());
//    cout<<"b2:";
//    for(Box b : b2){
//        cout<<"("<<b.getX()<<","<<b.getY()<<","<<b.getZ()<<")";
//    }
//    cout<<endl;
    
    
    return 0;
}
