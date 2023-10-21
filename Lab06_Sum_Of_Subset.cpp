
#include <stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool knapsack(vector<int>s,vector<int>p,int d ,int f);

bool sumofsubset(vector<int>s,int sum){
    s.insert(s.begin(),0);
    return knapsack(s,s,sum,sum);
}

bool knapsack(vector<int>p,vector<int>w,int c,int v){
    int m = p.size();
    int n = c+1;
    vector<vector<int>>dp(m,vector<int>(n,0));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if(j < w[i]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
            }
        }
    }
    for(auto &r:dp){
        for(auto d:r){
            cout<<d<<" ";
        }
        cout<<endl;
    }
    return dp[m-1][n-1] == v;
}
int main()
{
    vector<int>s = {2,4,6,8};
    cout<<sumofsubset(s,8)<<endl;
    return 0;
}

