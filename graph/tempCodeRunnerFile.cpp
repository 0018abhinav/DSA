#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int depth[N]={0};
int height[N];

void dfs(int vertex ,int par){
    for(int child: g[vertex]){
        if(vis[child]&& child== par)continue;
        depth[child] = depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]= max(height[vertex], height[child]+1);

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
    dfs(1,0);
    for(int i=1; i<=n; i++){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
}
