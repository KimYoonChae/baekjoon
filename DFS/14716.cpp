#include <iostream>
#include <memory.h>
using namespace std;

static int m,n,A[251][251],visited[251][251];
static int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};

void dfs(int a, int b){
visited[a][b]=1;

for(int i=0;i<8;i++){
    int x=a+dx[i];
    int y=b+dy[i];
    if(x<0||y<0||x>=m||y>=n)continue;
    if(visited[x][y]!=0) continue;
    if(A[x][y]==1)dfs(x,y);
}
}
int main(){
    int cnt=0;
    cin>>m>>n;
    memset(visited,0,sizeof(visited));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0&&A[i][j]==1){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt;

    
}