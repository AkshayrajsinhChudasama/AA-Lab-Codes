#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a,unsigned long long b){
    unsigned long long c;
    while(b!=0){
        c=a%b;  
        a = b;
        b = c;
    }
    return a;
}
unsigned long long powermod(unsigned long long a,unsigned long long x,unsigned long long n){
    unsigned long long res = 1;
    while(x>0){
        if((x & 1)){
            res = (res*a)%n;
        }
        x = x>>1;
        a = (a*a)%n;
    }
    return res;
}
bool primality_testing(unsigned long long n){
    int k = 100;
    if(n==1){
        return false;
    }
    if(n == 2 || n==3){
        return true;
    }
    if(n==4){
        return false;
    }
    while(k--){
        unsigned long long random = 2 + rand() % (n-4);
        if(gcd(random,n)!=1){
            return false;
        }
        if(powermod(random,n-1,n)!=1){
            return false;
        }
    }
    return true;
}
double findLiers(unsigned long long n){
    unsigned long long count = 1;
    for (unsigned long long i = 5; i < n-1; i++) {
        if(powermod(i,n-1,n)==1){
            count+=1;
        }
    }
    return double(count)/n;
}
int main()
{
    srand(time(0));
    cout<<primality_testing(1000000007)<<endl;
    cout<<primality_testing(100000019)<<endl;
    cout<<primality_testing(1000000087)<<endl;
    cout<<primality_testing(100000003)<<endl;
    cout<<primality_testing(567)<<endl;
    cout<<findLiers(561)<<endl;
    cout<<powermod(145,47,48);

    return 0;
