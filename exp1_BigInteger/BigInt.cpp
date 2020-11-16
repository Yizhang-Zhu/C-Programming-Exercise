#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

//加法
vector<int> add(vector<int> &x, vector<int> &y)
{
	vector<int> result;  //运算结果
	int t = 0;
	for(int i = 0; i<x.size() || i<y.size(); i++){
		if(i<x.size()){
			t += x[i];
		}
		if(i<y.size()){
			t += y[i];
		}
		result.push_back(t % 10);
		t = t/10;
	}
	if(t != 0){
		result.push_back(1);
	}
	return result;
}

//减法
vector<int> sub(vector<int> &x, vector<int> &y)
{
	vector<int> result;  //运算结果
	int t = 0;
	for(int i = 0; i<x.size(); i++){
		t = x[i] - t;
		if(i<y.size()){
			t -= y[i];
		}
		result.push_back((t+10)%10);
		if(t<0){
			t = 1;
		}else{
			t = 0;
		}
	}
	while(result.size()>1 && result.back() == 0){
		result.pop_back();
	}
	return result;
}

//乘法
vector<int> mul(vector<int> &x, vector<int> &y){
    vector<int> result(1000); //运算结果
    //各位相乘
    for(int i = 0; i<x.size(); i++){
        for(int j = 0; j<y.size(); j++){
            result[i+j] += x[i]*y[j];
        }
    }
    //carry
    for(int k = 0; k<x.size()+y.size(); k++){
        if(result[k]>=10){
            result[k+1] += (result[k]/10);
            result[k] % 10;
        }
    }
    //去掉前面一堆没用的0
    while(result.size()>1 && result.back() == 0){
        result.pop_back();
    }
    return result;
}

//除法 如果除不尽就舍弃余数（被除数高精度vector，除数低精度int）
vector<int> div(vector<int> &A,int b,int &r){
    vector<int> result;
    r = 0;
    for(int i = A.size() - 1;i >= 0;i--){
        r = r * 10 + A[i];
        result.push_back(r/b);
        r %= b;
    }
    reverse(result.begin(), result.end());
    while(result.size() > 1 && result.back() == 0){
        result.pop_back();
    }
    return result;
}

//main函数
int main()
{
    string a,b,optr;  //a,b是输入的大整数对应的字符串,optr是operator
    vector<int> A,B;  //A,B是大整数字符串存入的vector容器
    cout<<"input(example: 12345 add/sub/mul/div 12345): "<<endl;
    cin>>a>>optr>>b;
    if(optr!="div"){
    for(int i=a.size()-1; i>=0; i--){
        A.push_back(a[i]-'0');
    }//把string转成数字并存进vector数组容器中
    for(int i=b.size()-1; i>=0; i--){
        B.push_back(b[i]-'0');
    }
    if(optr=="add"){
        vector<int> C;
        C = add(A,B);
        for(int i=C.size()-1; i>=0; i--){
            cout<<C[i];
        }
    }
    if(optr=="sub"){
        vector<int> C;
        C = sub(A,B);
        for(int i=C.size()-1;i>=0;i--){
            cout<<C[i];
        }
    }
    if(optr=="mul"){
        vector<int> C;
        C = mul(A,B);
        for(int i=C.size()-1; i>=0; i--){
            cout<<C[i];
        }
    }
    }else{
        string a,op;
        vector<int> A;
        int b;
        cin >> a >> op >> b;
        for(int i=a.size()-1;i>=0;i--){
            A.push_back(a[i]-'0');
        }
        int k=0;
        auto C = div(A,b,k);
        cout << "商：";
        for(auto c:C) cout << c;
        if(k!=0){
            cout << " 余: " << k <<endl;
        }
    }


}