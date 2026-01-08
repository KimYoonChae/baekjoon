#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
    int dx[]={-2,-2,0,2,2,0}, dy[]={-1,1,2,1,-1,-2};
    int n;
    cin>>n;

    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    int visited[201][201];
    memset(visited,-1,sizeof(visited));
    queue<pair<int,int>> q;
    q.push({r1,c1}); visited[r1][c1];

    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        if(cur.first==r2&&cur.second==c2){
            cout<<visited[r2][c2]+1;
            return 0;
        }

        for(int i=0;i<6;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];


            if(x<0||y<0||x>=n||y>=n) continue;
            if(visited[x][y]!=-1) continue;

            q.push({x,y});
            visited[x][y]=visited[cur.first][cur.second]+1;
        }
    }
    cout<<-1;
}