#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

static int R,C,visited[251][251], dx[]={0,1,0,-1},dy[]={1,0,-1,0};
static char A[251][251];
static int sheep=0,wolf=0;

void DFS(int a,int b){
    visited[a][b]=1;
    if(A[a][b]=='v') wolf++;
    if(A[a][b]=='k') sheep++;
    for(int i=0;i<4;i++){
        int x=a+dx[i];
        int y=b+dy[i];

        if(x<0||y<0||x>=R||y>=C) continue;
        if(visited[x][y]!=0) continue;
         if(A[x][y]=='.'||A[x][y]=='v'||A[x][y]=='k'){
            DFS(x,y);
         }
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

    vector<int>snums,wnums;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(A[i][j]!='#'&&visited[i][j]==0){
                if(A[i][j]=='.'||A[i][j]=='v'||A[i][j]=='k'){
                    sheep=0; wolf=0;
                    DFS(i,j);
                   
                   snums.push_back(sheep);
                    wnums.push_back(wolf);
                }
            }
        }
    }

    int result[2]={0};
    for(int i=0;i<snums.size();i++){
        if(snums[i]>wnums[i]){
        wnums[i]=0;
        result[0]+=snums[i];
        result[1]+=wnums[i];
        } 
        else{
         snums[i]=0;   
         result[0]+=snums[i];
         result[1]+=wnums[i];
        } 
    }

    cout<<result[0]<<" "<<result[1];
    

    


}
