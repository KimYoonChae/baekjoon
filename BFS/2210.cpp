#include <iostream>
#include <set>
using namespace std;
static int A[6][6];
static int visited[6][6];
static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
void DFS(int i, int j, int cur, int depth);
set<int>s;
void DFS(int i, int j, int cur, int depth){
    if(depth==6){
        s.insert(cur);
        return;
    }
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||y<0||x>=5||y>=5)continue;
            DFS(x,y,cur*10+A[x][y],depth+1);
        
    }
}

int main(){
  
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            
            DFS(i,j,A[i][j],1);
    
        }
    }
   
   cout<<s.size();


}