#include <iostream>
using namespace std;

static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int visited[101][101];
static char A[101][101];
static int N;
void DFS(int i, int j);

void DFS(int i, int j){
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<N&&y<N){
            if(visited[x][y]==0&&A[x][y]==A[i][j]){
                visited[x][y]=1;
                DFS(x,y);
            }
        }
    }
}

int main(){
    cin>>N;
    
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<N;j++){
            A[i][j]=s[j];
        }
    }

    int count[2]={0}; 

    for(int m=0;m<2;m++){
        if(m==1){
            for(int e=0;e<N;e++){
                for(int r=0;r<N;r++){
                    if(A[e][r]=='G'){
                        A[e][r]='R';
                    }
                }
            }
        }
         for(int i=0;i<N;i++){
             for(int j=0;j<N;j++){
                    visited[i][j]=0;
                    }
                    }
   
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0){
                DFS(i,j);
                count[m]++;
            }
        }
    }


    }
    
   
    cout<<count[0]<<" "<<count[1];

}
