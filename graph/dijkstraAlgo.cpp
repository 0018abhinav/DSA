#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N];

void dijkstra(int source){
    vector<int> dist(N,INF);
    vector<int> vis(N,0);

    set<pair<int,int>>st; //first int represent weight and second int represent node
    st.insert({0,source});
    dist[source] =0;

    while(st.size() >0){
        auto node = *st.begin();
        int topNode = node.second;
        int nodeDist = node.first;
        st.erase(st.begin());
        if(vis[topNode])continue;
        vis[topNode]=1;

        for(auto  child: g[topNode]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[topNode] + wt < dist[child_v]){
                dist[child_v] = dist[topNode] + wt;
                st.insert({dist[child_v] , child_v});
            }
        }
    }
    for(auto i:dist){
        cout<<i<<" ";
    }
    //time complexity = O(V+Elog(V))

}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    dijkstra(1);

}