#include <iostream>
#include <memory.h>
using namespace std;

static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},dp[501][501],A[501][501],B[501][501],R,C;
int DFS(int i, int j){
    if(i==R-1&&j==C-1) return 1;
    if(B[i][j]!=0) return dp[i][j];
    dp[i][j]=0; B[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||y<0||x>=R||y>=C) continue;
        if(A[x][y]<A[i][j]) {
            dp[i][j]+=DFS(x,y);
        }
    }return dp[i][j];
}
int main(){
    memset(B,0,sizeof(B));memset(dp,0,sizeof(dp));
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
        }
    }
    DFS(0,0);
    cout<<dp[0][0];
}