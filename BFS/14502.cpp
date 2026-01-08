#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0},R,C,virus[9][9],A[9][9];

int main(){
    queue <pair<int,int>>q;
    memset(virus,-1,sizeof(virus));
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
            if(A[i][j]==2){
                virus[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];

            if(x<0||y<0||x>=R||y>=C) continue;
            if(virus[x][y]!=-1) continue;
            if(A[x][y]==1) continue;

            virus[x][y]=virus[cur.first][cur.second]+1;
            q.push({x,y});
        }
    }
    cout<<"\n";
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
        
           
                cout<<virus[i][j]<<" ";
             
        }cout<<"\n";
    }
}