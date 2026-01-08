#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
static int R,C;//행과열
static int dx[]={0,1,0,-1},dy[]={1,0,-1,0},scount=0,wcount=0;
static char A[251][251],visited[251][251];

void dfs(int a, int b){
    if(A[a][b]=='o') scount++;
    if(A[a][b]=='v') wcount++;
    visited[a][b]=1;
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];
        if(x<0||y<0||x>=R||y>=C)continue;
        if(visited[x][y]!=0) continue;
        //if(A[x][y]=='#') continue;
        if(A[x][y]=='.'||A[x][y]=='o'||A[x][y]=='v') {dfs(x,y);}

    }
}

int main(){
    cin>>R>>C;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
        }
    }
    int result[2]={0};
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(visited[i][j]==0) {
                if(A[i][j]=='v'||A[i][j]=='o'){
                    scount=0; wcount=0;
                    dfs(i,j);
                  // cout<<scount<<" "<<wcount<<"\n";
                   if(scount>wcount) result[0]+=scount;
                   else result[1]+= wcount;
                }
                
          
            }
       
        }
    }
   
   
   
    cout<<result[0]<<" "<<result[1];




}