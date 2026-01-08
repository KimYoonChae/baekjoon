#include <iostream>
using namespace std;
static int dx[8]={0,1,1,1,0,-1,-1,-1};
static int dy[8]={1,1,0,-1,-1,-1,0,1};

static int visited[51][51];
static int A[51][51];
void DFS(int i, int j, int w, int h);

int main(){
    int w,h;int numbers[51]={0};
    while(1){
        cin>>w>>h;
        if(w==0&&h==0) break;
        int count=0;
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                visited[i][j]=0;
                A[i][j]=-1;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>A[i][j];
            }
        }
         for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(visited[i][j]==0&&A[i][j]==1){
                     DFS(i,j,w,h);
                     count++;
                }
            }
        }
        cout<<count<<"\n";
    }
}

void DFS(int i, int j, int w, int h){
    
    for(int k=0;k<8;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<h&&y<w){
            if(A[x][y]==1&&visited[x][y]==0){
                visited[x][y]=1;
                DFS(x,y,w,h);
            }
        }
    }

}