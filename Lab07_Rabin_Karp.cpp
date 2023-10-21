#include<vector>
#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> rabinKarp(string t,string p,int d,int prime){
    int m = p.size(),n = t.size(),pt = 0,tt = 0;
    if(m > n)return {};
    vector<int>ans;
    for(int i = 0;i < m;i++){
        pt = (pt * d + p[i] - '0') % prime;
        tt = (tt * d + t[i] - '0') % prime;
    }
    int j = 0, hash = pt % prime, mul = pow(10,m-1);
    mul %=prime;
    while(j+m <= n){
        if(tt % prime == hash && t.substr(j,m)==p){
            ans.push_back(j);
            cout<<j<<" ";
        }
        int now = t[j+m]-'0',first = t[j++]-'0';
        tt = ((((tt - (first * mul)) * d) % prime) + prime) % prime + now;
    }
    return ans;
}
int main(){
    string p = "26",p1 = "11",t1 = "1111111111",t = "3141592653589793";
    int d = 10,prime = 11;
    cout<<"shift values are : ";
    rabinKarp(t,p,d,prime);
    cout<<endl;
    cout<<"shift values are : ";
    rabinKarp(t1,p1,d,prime);
    return 0;
}
