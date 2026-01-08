#include <iostream>
#include <algorithm>
using namespace std;

static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int A[101][101];
static int visited[101][101];
static int M,N,K;
static int s=0;
void DFS(int i, int j);

int main(){
    int count=0;
   
    cin>>M>>N>>K;//세로,가로, 직사각형 개수
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            A[i][j]=1;
            visited[i][j]=0;
        }
    }
    int x,y,x2,y2;/*핵심!!!!*/
    for(int i=0;i<K;i++){ //직사각형 개수 동안
        cin>>y>>x>>y2>>x2;
         for(int r=x; r<x2; r++){
        for(int j=y;j<y2;j++){
            A[r][j]=0;
        }}
    }
    int numbers[101];
    int idx = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0&&A[i][j]==1)
            {
                s = 0;
                DFS(i, j);
                numbers[idx++] = s; //connected componenet안의 요소들의 개수
                count++; //connected componenet 개수
            }
        }
    }
    sort(numbers, numbers + idx);

    cout << count << "\n";
    for (int i = 0; i < idx; i++) {
        cout << numbers[i] << " ";
    }

    /*
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<A[i][j]<<" ";
        }cout<<"\n";
    }*/
}

void DFS(int i, int j){
    visited[i][j]=1;
    s++;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<M&&y<N){
            if(visited[x][y]==0&&A[x][y]==1){
                
                DFS(x,y);
            }
        }
    }
}