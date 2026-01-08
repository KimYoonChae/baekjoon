#include <iostream>
#include <algorithm>
using namespace std;
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
void DFS(int i, int j, int h);
static int A[101][101];
static int visited[101][101];
static int N;

int main(){

    cin>>N; //안전한 영역의 최대 개수
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
           cin>> A[i][j];
        }
    }
   int numbers[101]={0};
    
    for(int h=0;h<=100;h++){ 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                visited[i][j]=0;
            }
        }
        int count=0;
        for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j]>h&&visited[i][j]==0){
                    DFS(i,j,h);
                    count++;
            }
        }
    }numbers[h] = count;

    }
cout << *max_element(numbers, numbers + 101);

 



}

void DFS(int i, int j, int h){
    visited[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0&&x<N&&y<N){
            if(A[x][y]>h&&visited[x][y]==0){
                DFS(x,y,h);
                visited[x][y]=1;
            }
        }
    }
    
}