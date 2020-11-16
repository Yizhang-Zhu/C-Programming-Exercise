//实验3 基本计算器-指针
//编写一个程序，实现基本的“计算器”功能，即计算输出 x ? y 的结果，其中x和y是从键盘输入的浮点数，
//？表示某种计算方式，比如加法、乘法等。请考虑用函数指针来实现，思考程序的可扩展性。
//Please input two numbers: 20 50
//Please input the operation (1)add, (2) subtraction, (3) multiplication, (4) division: 1
//输出： 70

#include<iostream>
using namespace std;
//1.加法
double add(double a, double b){
    return a+b;
}
//2.减法
double sub(double a, double b){
    return a-b;
}
//3.乘法
double mul(double a, double b){
    return a*b;
}
//4.除法
double div(double a, double b){
    return a/b;
}


int main(){
    double x;
    double y;
    double result;  //运算结果
    cout<<"Please input two numbers: "<<endl;
    cin>>x>>y;
    //定义函数指针
    double (*compute)(double, double) = nullptr;
    int t;  //t表示运算符的标号
    cout<<"Please input the operation (1)add, (2) subtraction, (3) multiplication, (4) division: "<<endl;
    cin>>t; 
    switch (t)
    {
    case 1:
        compute = add;
        break;
    case 2:
        compute = sub;
        break;
    case 3:
        compute = mul;
        break;
    case 4:
        compute = div;
        break;
    default:
        break;
    }
    result = compute(x, y);
    cout<<"the result is "<<result<<endl;
}

