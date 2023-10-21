#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateEdge(vector<vector<int>>graph){
    int n = graph.size();
    int m = graph[0].size();
    vector<vector<int>>edges;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < m; j++) {
            if(graph[i][j]==1){
                edges.push_back({i,j});
            }
        }
    }
    return edges;
   
}
vector<vector<int>> removeEdges(vector<vector<int>>edges,int u,int v){
    vector<vector<int>>ans;
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        if(edges[i][0] == u ||edges[i][1]==u || edges[i][0]==v || edges[i][1] ==v){
           
        }  else ans.push_back({edges[i][0],edges[i][1]});
    }
    return ans;
}
void print(vector<vector<int>>edge){
        for(auto &i:edge){
        for(auto &j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
vector<int> randomizedApproximationMVC(vector<vector<int>>graph){
    vector<vector<int>>edge = generateEdge(graph);
    // print(edge);
    vector<int>ans;
    while(edge.size()!=0){
        int i = rand()%edge.size();
        ans.push_back(edge[i][0]);
        ans.push_back(edge[i][1]);
        edge = removeEdges(edge,edge[i][0],edge[i][1]);
        // print(edge);
    }
    return ans;
}
int main() {
    srand(time(NULL));
    vector<vector<int>>graph =
    {
        {0,1,0,1,0,0},
        {1,0,1,1,0,0},
        {0,1,0,0,1,1},
        {1,1,0,0,1,0},
        {0,0,1,1,0,0},
        {0,0,1,0,0,0},
       
    };
     vector<vector<int>>graph2 =
    {
        {0,1,0,1,0,0},
        {1,0,1,1,0,0},
        {0,1,0,0,1,1},
        {1,1,0,0,1,0},
        {0,0,1,1,0,0},
        {0,0,1,0,1,0},
       
    };

    vector<int>mvc = randomizedApproximationMVC(graph2);
    for(auto &i:mvc){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
