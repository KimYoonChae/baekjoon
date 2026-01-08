#include <iostream>
using namespace std;
static int M,N;
static int visited[501][501];
static int A[501][501];
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};

int DFS(int i, int j);


int DFS(int i, int j){
    visited[i][j]=1;
    int size=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<M&&y<N){
            if(visited[x][y]==0&&A[x][y]==1){
                 
                size+=DFS(x,y);
            }
        }
    }
    return size;
}



int main(){
    cin>>M>>N;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
  ;int max=0;
    int count=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0&&A[i][j]==1){
                count++;
                int cursize=DFS(i,j);
                if(cursize>max) max=cursize;
               
            }
        }
    }


    
    cout<<count<<" "<<max;

}