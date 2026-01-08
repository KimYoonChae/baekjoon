#include<iostream>
#include <memory.h>
using namespace std;
/*DFS+DP*/
static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},N,M,B[51][51],C[51][51];
static char A[51][51];
int DFS(int a,int b);
int DFS(int a,int b){
   if(a<0||b<0||a>=N||b>=M||A[a][b]=='H'){
    return 0;
   } if(B[a][b]!=0) {
    cout<<-1; exit(0);
   }
   if(C[a][b]!=0) return C[a][b];
  
   B[a][b]=1; C[a][b]=1;
   for(int i=0;i<4;i++){
    int x=a+dx[i]*(A[a][b]-'0');
    int y=b+dy[i]*(A[a][b]-'0');
    C[a][b]=max(C[a][b],DFS(x,y)+1);
   }
   B[a][b]=0;
   return C[a][b];
}
int main(){
    cin>>N>>M;
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    DFS(0,0);
    cout<<C[0][0];
}