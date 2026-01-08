#include <iostream>
#include <memory.h>
using namespace std;
static int n, dx[]={0,1,0,-1},dy[]={1,0,-1,0};
static int A[501][501],dp[501][501];

int DFS(int i, int j);
int DFS(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||y<0||x>=n||y>=n) continue;
        if(A[x][y]>A[i][j]){
            int d=DFS(x,y)+1;
            if(d>dp[i][j]) dp[i][j]=d;
        }
    }
    return dp[i][j];
}


int main(){memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }int max=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int cur=DFS(i,j);
        if(cur>max) max=cur;
    }
  }
  cout<<max;
}