#include<bits/stdc++.h>
using namespace std;

const int N=200;
vector<int> g[N];
int vis[N];

void dfs(int source){

    stack<int> s;

    s.push(source);

    while(!s.empty()){

        int cur_v=s.top();
        s.pop();

        if(!vis[cur_v]){
            cout<<cur_v<<' ';
            vis[cur_v]=1;
        }
        

        for(int child : g[cur_v]){
            if(!vis[child]){
                s.push(child);
            }
        }
    }
    cout<<endl;
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

    int ver;
    cin>>ver;

    dfs(ver);

    return 0;
}
