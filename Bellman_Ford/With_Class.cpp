#include<bits/stdc++.h>
using namespace std;
const int N=3e5+9;
const int INF=2e9;
class Node{
    public:
    int u,v,w;
}node[N];

int main(){

    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){

        cin>>node[i].u>>node[i].v>>node[i].w;
    }

    int src;
    cin>>src;

    vector<int> d(v,INF);

    d[src]=0;

    int x;

    for(int i=0; i<v; i++){
        x=-1;
        for(int j=0; j<e; j++){
            if(d[node[j].u]<INF && d[node[j].u]+node[j].w<d[node[j].v]){
                d[node[j].v]=d[node[j].u]+node[j].w;
                x=node[j].v;
            }
        }
    }

    if(x!=-1){
        cout<<"Negative Weighted Cycle Detected"<<endl;
    }
    else{
        for(int i=0; i<v; i++){
            cout<<i<<" : "<<d[i]<<endl;
        }
    }

    return 0;
}
