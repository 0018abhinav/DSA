#include <bits/stdc++.h>
using namespace std;

//matrix representation
const int N= 1e3+10;
//int graph1[N][N];

//list representation
vector<int> graph2[N];
//vector<pair<int,int>> graph2[N]; //for weighted graph

bool vis[N];

void dfs(int vertex){
    //take action on vertex after entering the vertex
    cout<<vertex<<endl;
    vis[vertex]= true;
    for(int child : graph2[vertex]){
        //cout<<"parent"<<vertex<<", child"<<child<<endl;
        if(vis[child]){
            continue;
        }
        //take action on child before entering child node

        dfs(child);
        //take action on child after exiting child node

    }
    //take action on vertex before exiting vertex

}

int main(){
    int n,m;
    cin>>n>>m;
    int v1,v2;
    for(int i=0; i<m ;i++){
        
        cin>>v1>>v2;
        //cin>>wt;

        // graph1[v1][v2]=1;
        // graph1[v2][v1]=1;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

        // graph2[v1].push_back({v2,wt});
        // graph2[v2].push_back({v1,wt});
        

    }
    dfs(1);
    //space complexity = O(N^2)
}
