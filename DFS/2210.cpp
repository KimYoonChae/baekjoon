#include <iostream>
using namespace std;
static int A[6][6];
static int visited[6][6];
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
void DFS(int i, int j);

void DFS(int i, int j){
    cout<<A[i][j]<<" ";
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=1&&y>=1&&x<=5&&y<=5){
            if(visited[x][y]==0){
                visited[x][y]=1;
                DFS(x,y);
            }
            
        }
    }
}

int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            visited[i][j]=0;
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>A[i][j];
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            DFS(i,j);
    
        }
    }
   
   


}