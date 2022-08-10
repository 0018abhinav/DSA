#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int depth[N];

void dfs(int vertex, int par=0){
    for(int child: g[vertex]){
        if(child== par)continue;
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
    }
}

int main(){

    int n;
    cin>>n;
    for(int i=1; i<n ;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);

    }
    int mx_depth=-1;
    int mx_depth_node;
    dfs(1);
    for(int i=1; i<=n;i++){
        if(depth[i]> mx_depth){
            mx_depth= depth[i];
            mx_depth_node=i;
        }
        depth[i] =0;
    }
    dfs(mx_depth_node);
    mx_depth=-1;

    for(int i=1; i<=n; i++){
        if(depth[i]> mx_depth){
            mx_depth= depth[i];
        }
    }
    cout<<mx_depth;


}