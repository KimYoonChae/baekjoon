#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
    int r,c,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
    cin>>r>>c;

    int A[51][51],visited[51][51];queue<pair<int,int>> q; 
    memset(visited,-1,sizeof(visited));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>A[i][j];
            if(A[i][j]==1){
                q.push({i,j});
                visited[i][j]=1;
            }
        }
    }
    int result;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();


        for(int i=0;i<8;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x<0||y<0||x>=r||y>=c) continue;
            if(visited[x][y]!=-1) continue;
            q.push({x,y});
            visited[x][y]=visited[cur.first][cur.second]+1;
            result=min(visited[x][y],visited[cur.first][cur.second]);
           // cout<<result;
        }
    }
    cout<<result;
    
    /*
cout<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
                cout<<visited[i][j]<<" ";
        }cout<<"\n";
    }*/



    
    
}