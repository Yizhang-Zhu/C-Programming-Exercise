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

class A_iterator{
public:
    A_iterator(){}
    A_iterator(int* it){
        iter=it;
    }
    int& operator*(){
        return *iter;
    }
    A_iterator& operator++(){
        iter++;
        return *this;
    }
    A_iterator operator++(int){
        int* old = iter;
        iter++;
        return A_iterator(old);
    }
    bool operator!=(const A_iterator& b){
        return iter != b.iter;
    }
    bool operator==(const A_iterator& b){
        return iter == b.iter;
    }

private:
    int* iter;
};

class A{
    
public:
    typedef A_iterator iterator;
    A(){
        size=0;
    }
    void push_back(int x){
        _data[size]=x;
        size++;
    }
    int get_back() const{
        return _data[size-1];
    }
    A::iterator begin(){
        return A_iterator(_data);
    }
    A::iterator end(){
        return A_iterator(_data+size);
    }
private:
    int _data[10];
    int size;
};

int main(){
    A a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);
    a1.push_back(4);
    a1.push_back(5);
    
    for(A::iterator iter=a1.begin(); iter!=a1.end(); iter++){
        
        cout<<*iter<<" ";
    }
    cout<<endl;
       
    
    return 0;
}
