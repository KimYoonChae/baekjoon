#include <iostream>
using namespace std;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[101][101];
static int A[101][101];int n,m,k;
int DFS(int i, int j);

int DFS(int i, int j){
    visited[i][j]=1;
    int size=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=1&&y>=1&&x<=n&&y<=m){
            if(visited[x][y]==0&&A[x][y]==1){
                
                size+=DFS(x,y);
               
            }
        }
    }
    return size;
}

int main(){
    cin>>n>>m>>k;
    int a,b;
 for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            visited[i][j]=0;
            A[i][j]=0;
        }
    }

    for(int i=1;i<=k;i++){
      cin>>a>>b;
      A[a][b]=1;
    }


  
    int max=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]==0&&A[i][j]==1){
               
                int Cnt=DFS(i,j);
                if(max<Cnt) max=Cnt;
            }
        }
    }
    cout<<max;


}