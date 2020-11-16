//只有加减，无乘除。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

struct BigInteger{
    //BASE为vector数组中一位中最大存储的数字，前面都是以10计算的
    //WIDTH为宽度
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
    //正数为1，负数为-1
    int flag = 1;
    
    //构造函数
    BigInteger(ll num = 0){*this = num;}
    BigInteger(string str){*this = str;}
    BigInteger(const BigInteger& t){
        this->flag = t.flag;
        this->s = t.s;
    }
    //赋值函数重载
    BigInteger operator = (ll num){
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator = (string &str){
        s.clear();
        int x,len = (str.length()-1)/WIDTH + 1;
        for(int i=0;i<len;i++){
            int end = str.length() - i*WIDTH;
            int start = max(0,end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }

    //基本比较函数 A < B
    bool cmp( vector<int> &A, vector<int> & B){
        if(A.size() != B.size())return A.size() < B.size();
        for(int i=A.size()-1;i>=0;i--){
            if(A[i] != B[i]){
                return A[i] < B[i];
            }
        }
        return false;
    }
    //比较函数如果小于则返回真
    bool operator < ( BigInteger & b){
        return cmp(s,b.s);
    }
    bool operator > ( BigInteger& b){
        return b < *this;
    }
    bool operator <= ( BigInteger &b){
        return !(b < *this);
    }
    bool operator >= ( BigInteger &b){
        return !(*this < b);
    }
    bool operator == ( BigInteger &b){
        return !(b < *this) && (*this < b);
    }
    //基本四则运算
    vector<int> add(vector<int> &A, vector<int> &B);
    vector<int> sub(vector<int> &A, vector<int> &B);


    //重载运算符
    BigInteger operator + (BigInteger &b);
    BigInteger operator - (BigInteger &b);

};
//重载输出
ostream& operator << (ostream &out,const BigInteger& x) {
    if(x.flag == -1)out << '-';
    out << x.s.back();
    for(int i = x.s.size() - 2; i >= 0;i--){
        char buf[20];
        sprintf(buf,"%08d",x.s[i]);//08d此处的8应该与WIDTH一致
        for(int j=0;j<strlen(buf);j++)out<<buf[j];
    }
    return out;
}
//重载输入
istream& operator >> (istream & in,BigInteger & x){
    string s;
    if(!(in>>s))return in;
    x = s;
    return in;
}
vector<int> BigInteger::add( vector<int> &A, vector<int> &B){
    if(A.size() < B.size())return add(B,A);
    int t = 0;
    vector<int> C;
    for(int i=0;i<A.size();i++){
        if(i<B.size())t += B[i];
        t += A[i];
        C.push_back(t%BASE);
        t /= BASE;
    }
    if(t)C.push_back(t);
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
vector<int> BigInteger::sub( vector<int> &A, vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
        t = A[i] - t;
        if(i<B.size())t -= B[i];
        C.push_back((t+BASE)%BASE);
        if(t < 0)t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}


BigInteger BigInteger::operator + ( BigInteger & b){
    BigInteger c;
    c.s.clear();
    c.s = add(s,b.s);
    return c;
}

BigInteger BigInteger::operator - ( BigInteger & b) {
    BigInteger c;
    c.s.clear();
    if(*this < b){
        c.flag = -1;
        c.s = sub(b.s,s);
    }
    else{
        c.flag = 1;
        c.s = sub(s,b.s);
    }
    return  c;
}

int main(){
    BigInteger A, B;
    cin>>A>>B;
    cout<<A+B<<endl;
    cout<<A-B<<endl;
}