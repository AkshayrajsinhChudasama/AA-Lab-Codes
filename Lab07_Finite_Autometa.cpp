
#include<bits/stdc++.h>
using namespace std;

void stringMatching(vector<vector<int>>autometa,string text,string pattern){
    int state = 0;
    for (int i = 0; i < text.size(); i++)
    {
        state = autometa[state][text[i]-'a'];
        if(state == pattern.size()){
            cout<<"Match Found at "<<i-pattern.size()+1<<endl;
        }
    }
}

int main() {
    string pattern = "abb";
    string text = "abbabbbbbaaabbbabb";
    vector<vector<int>>autometa(pattern.size()+1,vector<int>(26));
    autometa[0]['b'-'a'] = 0;
    autometa[0]['a'-'a'] = 1;
    autometa[1]['b'-'a'] = 2;
    autometa[1]['a'-'a'] = 1;
    autometa[2]['b'-'a'] = 3;
    autometa[2]['a'-'a'] = 1;
    autometa[3]['b'-'a'] = 0;
    autometa[3]['a'-'a'] = 1;
    stringMatching(autometa,text,pattern);
    return 0;
}
