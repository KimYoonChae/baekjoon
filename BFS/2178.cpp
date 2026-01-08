#include <iostream>
#include <queue>
using namespace std;

int m,n;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[101][101];
static int A[101][101];
void BFS(int i, int j);
void BFS(int i, int j){
  queue<pair<int,int>> q;
  q.push(make_pair(i,j));
  
  while(!q.empty()){
    int now[2];
    now[0]=q.front().first;
    now[1]=q.front().second;
    q.pop();
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int x=now[0]+dx[k];
        int y=now[1]+dy[k];
        if(x>=0&&y>=0&&x<m&&y<n){
            if(visited[x][y]==0&&A[x][y]==1){
                visited[x][y]=1;
                A[x][y]=A[now[0]][now[1]]+1;
                q.push(make_pair(x,y));
            }
        }
    }
  }
   

}


int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            A[i][j]=s[j]-'0';
        }
    }
    BFS(0,0);
    cout<<A[m-1][n-1];
}

