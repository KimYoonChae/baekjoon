#include <iostream>
#include <memory.h>
using namespace std;
static int dx[]={0,1,0}, dy[]={1,0,-1},A[1001][1001],B[1001][1001],C[1001][1001],N,M;
int DFS(int a, int b){
    if(C[a][b]!=0) return C[a][b];
    C[a][b]=A[a][b];
    B[a][b]=1;
    for(int i=0;i<3;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(a<1||b<1||a>N||b>M) continue;
        if(B[a][b]!=0) continue;
        C[a][b]+=DFS(x,y);
    }
    return C[a][b];
}
int main(){
    cin>>N>>M;
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>A[i][j];
        }
    }
    cout<<DFS(1,1)<<"\n";
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<C[i][j];
        }cout<<"\n";
    }
}