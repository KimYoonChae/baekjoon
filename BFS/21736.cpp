#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int N,M;
static char A[601][601];
static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},visited[601][601],cnt=0;
void dfs(int a, int b){ 
    if(A[a][b]=='P') cnt++;
    visited[a][b]=1;
   // cout<<A[a][b];
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x<0||y<0||x>=N||y>=M) continue;
        if(visited[x][y]!=0) continue;
        if(A[x][y]=='X') continue;
        if(A[x][y]=='O'||A[x][y]=='P'){ dfs(x,y);
           
           
       }
    }

}
int main(){
    cin>>N>>M;
    int sx,sy;
    queue <pair<int,int>> q;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            if(A[i][j]=='I'){
                sx=i; sy=j;
            }
        }
    }
   // dfs(sx,sy);
   
    
    
    visited[sx][sy]=1;
    q.push({sx,sy});
    int cnt=0;

    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];

            if(x<0||y<0||x>=N||y>=M) continue;
            if(A[x][y]=='X') continue;
            if(visited[x][y]!=0) continue;
            
            if(A[x][y]=='P') cnt++;
            visited[x][y]=1;
            q.push({x,y});
        }
    } 
    if(cnt==0) cout<<"TT";
    else
    cout<<cnt;

}