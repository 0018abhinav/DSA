#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par){
    vis[vertex];
    bool isLoopFound =false;
    for(int child:g[vertex]){
        if(vis[child] && child == par)continue;
        if(vis[child]){
            return true;
        }
        isLoopFound |= dfs(child, vertex);

    }
    return isLoopFound;
}

int main(){
    int n ;
    cin>>n;
    for(int i=1; i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        
    }
    bool isLoopFound = false;
    for(int i=1 ;i<=n; i++){
        if(vis[i])continue;
        if(dfs(i,0)){
            isLoopFound == true;
            break;
        }cout<<isLoopFound<<endl;
    }

}