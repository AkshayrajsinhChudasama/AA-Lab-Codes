#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> makeLPS(string pattern){
    cout<<"String is : "<<pattern<<endl;
    int m = pattern.size(),k = -1,cnt = 0;
    vector<int>lps(m,-1);
    for (int i = 1; i < m; i++) {
        bool t = (pattern[k+1]!=pattern[i]);
        cnt++;
        while(k>=0 && t){
            k = lps[k];
            t = (pattern[k+1]!=pattern[i]);
            cnt++;
        }
        if(!t){
            k++;
        }
        lps[i] = k;
    }
    cout<<"Total count is : "<<cnt<<endl;
    int j = 1;
    for(auto i:lps){
        cout<<j++<<" --> "<<i<<endl;
    }
    cout<<endl<<endl;
    return lps;
}
void KMP_Mathcing(string text,string pattern){
    int m = pattern.size(),n = text.size(),q = -1;
    vector<int>lps = makeLPS(pattern);
    for (int i = 0; i < n; i++) {
        while(q>=0 && pattern[q+1]!=text[i]){
            q = lps[q];
        }
        if(text[i] == pattern[q+1])q++;
        if(q==m-1){
            cout<<"Match found at : "<<i-m+1<<endl;
            q = lps[q];
        }
    }
}
void KMP_Mathcing_complexity(string text,string pattern){
    int m = pattern.size(),n = text.size(),q = -1,cnt = 0;
    vector<int>lps = makeLPS(pattern);
    for (int i = 0; i < n; i++) {
        bool t = (pattern[q+1]!=text[i]);
        cnt++;
        while(q>=0 && t){
            q = lps[q];
            t = (pattern[q+1]!=text[i]);
            cnt++;
        }
        if(text[i] == pattern[q+1])q++;
        if(q==m-1){
            q = lps[q];
        }
    }
    cout<<"Total comparision required : "<<cnt<<endl;
}
vector<int>findClosestPoints(vector<vector<int>>points){
    int n = points.size(),index1 = -1,index2 = -1,mini = INT_MAX;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            long long d = pow((points[i][0] - points[j][0]),2) + pow((points[i][1] - points[j][1]),2);
            if(d < mini){
                mini = d;
                index1 = i;
                index2 = j;
            }
        }
    }
    return {index1,index2,mini};
}
int main()
{
    //KMP ALGORITHM
   
    // makeLPS("ababa");
    // makeLPS("aaaaa");
    // makeLPS("abcda");
    // makeLPS("aaaba");
    // makeLPS("abaab");
    // makeLPS("aabba");
    string text = "aaaaaaaaaaaa";
    string pattern = "aaaa";
    string te = "acacacacac";
    string pat = "acac";
    KMP_Mathcing(text,pattern);
    KMP_Mathcing_complexity(text,pattern);
    KMP_Mathcing_complexity(te,pat);
   
    vector<vector<int>>points = {
        {6,6},
        {2,8},
        {2,2},
    };
    vector<int>ans = findClosestPoints(points);
    cout<<"Two closest points are ( "<<points[ans[0]][0]<<" , "<<points[ans[0]][1]<<" ) and ( "<<points[ans[1]][0]<<" , "<<points[ans[1]][1]<<" )"<<endl;
    cout<<"Distance bewteen them is : "<<sqrt(ans[2]);
    return 0;
}
