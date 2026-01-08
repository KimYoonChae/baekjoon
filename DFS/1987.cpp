#include <iostream>
#include <memory.h>
using namespace std;

static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static char grid[21][21]; 
static int used[26]={0};
void DFS(int i, int j,int depth);
int R,C,cnt;

int main(){
    
    cin>>R>>C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
          
        }
    }
    cnt=0;
      DFS(0,0,1);
     cout<<cnt;
}


void DFS(int i, int j,int depth){
   used[grid[i][j]-'A']=1;
   cnt = max(cnt, depth);

   for(int k=0;k<4;k++){
    int x=i+dx[k];
    int y=j+dy[k];
   if(x>=0 && y>=0 && x<R && y<C)
{
      if(used[grid[x][y]-'A']==0){
        DFS(x,y,depth+1);
         used[grid[x][y]-'A']=0;
    }  
    }
    
   }

}