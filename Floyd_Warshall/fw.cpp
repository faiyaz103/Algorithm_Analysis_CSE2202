#include<bits/stdc++.h>
using namespace std;
#define inf 10000
void print(int g[][4]){

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(g[i][j]==inf){
                cout<<"Inf"<<' ';
            }
            else{
                cout<<g[i][j]<<' ';
            }
        }
        cout<<endl;
    }
}



void floyd_warshall(int g[][4]){

    for(int k=0; k<4; k++){ //k as intermediate vertex
        for(int i=0; i<4; i++){ //row
            for(int j=0; j<4; j++){ //column
                g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}



int main(){

    int g[4][4]={{0,3,inf,7},
                {8,0,2,inf},
                {5,inf,0,1},
                {2,inf,inf,0}};

    cout<<"The matrix before applying Floyd-Warshall Algo: "<<endl;
    print(g);

    cout<<"The matrix after applying Floyd-Warshall Algo: "<<endl;
    floyd_warshall(g);
    print(g);
    
    return 0;
}
