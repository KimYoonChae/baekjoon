#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
static int A[1001][1001],visited[1001][1001]; //원래배열, 도착점에서 몇칸 떨어졌는지 기록하는 배열
int main(){
    
    int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
    memset(visited,-1,sizeof(visited));
    queue<pair<int,int>>q;
    int R,C;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
            if(A[i][j]==2){
                visited[i][j]=0;
                q.push({i,j});
            }
            if(A[i][j]==0) {
                    visited[i][j]=0;
                }
        }
    }

    while(!q.empty()){
        pair<int,int>cur=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=0&&y>=0&&x<R&&y<C){
                if(A[x][y]!=0&&visited[x][y]==-1){
                     q.push({x,y});
                    visited[x][y]=visited[cur.first][cur.second]+1;
                }
                
            }
            /*
            if(x<0||y<0||x>=R||y>=C) continue;
            if(A[x][y]==0) continue;
            if(visited[x][y]!=-1) continue;
            q.push({x,y});
            visited[x][y]=visited[cur.first][cur.second]+1;*/
        }
    }
/* 
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
        if(visited[i][j]==-1) visited[i][j]=0;
        }
        
    }*/

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }


}