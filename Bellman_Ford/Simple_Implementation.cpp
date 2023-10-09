#include<bits/stdc++.h>
using namespace std;

void bellman_ford(int g[][3], int v, int e, int src){

    int dis[v];
    for(int i=0; i<v; i++){
        dis[i]=INT_MAX;
    }

    dis[src]=0;

    for(int i=0; i<v-1; i++){
        for(int j=0; j<e; j++){
            if(dis[g[j][0]]!=INT_MAX && dis[g[j][0]]+g[j][2]<dis[g[j][1]]){
                dis[g[j][1]]=dis[g[j][0]]+g[j][2];
            }
        }
    }

    int flag=1;
    for(int i=0; i<e; i++){
        int x=dis[g[i][0]];
        int y=dis[g[i][1]];
        int w=g[i][2];

        if(x!=INT_MAX && x+w<y){
            flag=0;
            break;
        }
    }

    if(flag==1){
        for(int i=0; i<v; i++){
            cout<<i<<" : "<<dis[i]<<endl;
        }
    }
    else{
        cout<<"Negative Weight Cycle Detected"<<endl;
    }
}



int main(){

    int v=5;
    int e=8;

    int g[][3]={
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    bellman_ford(g,v,e,0);

    return 0;
}
