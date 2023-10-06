#include<bits/stdc++.h>
using namespace std;
const int N=1000;
bool vis[N];
vector<int> g[N];

void bfs(int src){

    queue<int> q;
    q.push(src);
    vis[src]=true;

    while(!q.empty()){
        int cur_node=q.front();
        q.pop();

        cout<<cur_node<<' ';

        for(auto child:g[cur_node]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int src;
    cin>>src;

    bfs(src);

    return 0;
}
