#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int INF=10000;
vector<pair<int,int>> g[N+1]; //<to vertex, weight>

void dijkstra(int src){

    vector<int> dis(N+1,INF);
    vector<bool> vis(N+1,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //<weight, vertex>
    
    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty()){

        auto node=pq.top();
        int cur_v=node.second;
        pq.pop();

        if(vis[cur_v]==true){
            continue;
        }

        vis[cur_v]=true;

        for(auto child:g[cur_v]){

            int child_v=child.first;
            int wt=child.second;

            if(dis[cur_v]+wt<dis[child_v]){
                dis[child_v]=dis[cur_v]+wt;
                pq.push({dis[child_v],child_v});
            }
        }
    }

    for(int i=0; i<=N; i++){
        if(g[i].size()!=0){
            cout<<i<<" : "<<dis[i]<<endl;
        }
    }

}

int main(){

    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int x,y,wt;
        cin>>x>>y>>wt;

        g[x].push_back({y,wt});
    }

    int src;
    cin>>src;

    dijkstra(src);

    return 0;
}
