#include <iostream>
#include <memory.h>
using namespace std;
static int wcnt=0,bcnt=0,dx[]={0,1,0,-1},dy[]={1,0,-1,0},N,M;
static char A[101][101],visited[101][101];
void dfs(int a, int b,char c){
    visited[a][b]=1;
    if(A[a][b]=='W')wcnt++;
    if(A[a][b]=='B')bcnt++;
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x<0||y<0||x>=M||y>=N)continue;
        if(visited[x][y]!=0) continue;
        if(A[x][y]==c)dfs(x,y,c);

    }
}
int main(){
cin>>N>>M;
memset(visited,0,sizeof(visited));
for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
        cin>>A[i][j];
    }
}
int result[2]={0};

for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
        if(visited[i][j]==0&&A[i][j]=='W')
        {
            wcnt=0;
        dfs(i,j,'W');
      result[0]+=wcnt*wcnt;
        }
        
    }
}
memset(visited,0,sizeof(visited));
for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
        if(visited[i][j]==0&&A[i][j]=='B')
        {
            bcnt=0;
        dfs(i,j,'B');
      result[1]+=bcnt*bcnt;
        }
        
    }
}



cout<<result[0]<<" "<<result[1];
}