#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N];

vector<vector<int,int>> 


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    prims(1);

}