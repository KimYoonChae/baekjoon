#include <iostream>
#include <memory.h>
using namespace std;
static int T,H,W,dx[]={0,1,0,-1},dy[]={1,0,-1,0},visited[101][101];
static char A[101][101];
static int cnt=0;

void dfs(int a, int b){
	visited[a][b]=1;
	if(A[a][b]=='#') cnt++; 

	for(int i=0;i<4;i++){
		int x=a+dx[i];
		int y=b+dy[i];
		if(x<0||y<0||x>=H||y>=W) continue;
		if(visited[x][y]!=0) continue;
		if(A[x][y]=='.') continue;
		if(A[x][y]=='#'){
			dfs(x,y);
		} 
	}
}
int main() {
	cin>>T;
	
	

	for(int i=0;i<T;i++){
		cin>>H>>W;
		int result=0;
		memset(visited,0,sizeof(visited));
		
		for(int j=0;j<H;j++){
			for(int t=0;t<W;t++){
				cin>>A[j][t];
				}
			}

		for(int j=0;j<H;j++){
			for(int t=0;t<W;t++){
				if(visited[j][t]==0&&A[j][t]=='#'){
					dfs(j,t);
					 result++;
			}
		}
	}

		cout<<result<<"\n";
		
		}
	return 0;
}