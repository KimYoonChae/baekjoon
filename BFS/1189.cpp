#include <iostream>
#include <memory.h>
using namespace std;
static char A[6][6];
static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},visited[6][6],R,C,K,cnt=0;
void DFS(int a, int b,int depth){
   
    if(a==0&&b==C-1){
       if(depth==K) cnt++;
       return;
    }
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x<0||y<0||x>=R||y>=C) continue;
        if(visited[x][y]!=0) continue;
        if(A[x][y]=='T') continue;
         visited[x][y]=1;
        DFS(x,y,depth+1); 
        visited[x][y]=0;
    }
}
int main(){

    cin>>R>>C>>K;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
        }
    }
    visited[R-1][0]=1;
    DFS(R-1,0,1);
    cout<<cnt;
    

}