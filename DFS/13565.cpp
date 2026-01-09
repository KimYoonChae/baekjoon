#include <iostream>
#include <memory.h>
using namespace std;
static int R,C;
static int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
static int A[1001][1001];
static int visited[1001][1001];
int sx,sy;
bool flag=false;
void DFS(int a, int b){

	visited[a][b]=1;
	sx=a;
	if(a==R-1&&A[a][b]==0) {
		flag=true;
	}
	
	
	for(int i=0;i<4;i++){
		int x=a+dx[i];
		int y=b+dy[i];
		if(x<0||y<0||x>=R||y>=C) continue;
		if(visited[x][y]==1) continue;
		if(A[x][y]==1) continue; 
        
		DFS(x,y);
		
		
		

	}
}
int main() {
	memset(visited,0,sizeof(visited));
	cin>>R>>C;

	for(int i=0;i<R;i++){
		string s;
		cin>>s;
		for(int j=0;j<C;j++){
			A[i][j]=s[j]-'0';
		}
	}
		int x;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
			if(visited[i][j]==0&&A[i][j]==0){
				x=i;
				DFS(i,j); 
				if(x==0&&flag==1) {cout<<"YES"; return 0;}
			}
			
		}
		}
		cout<<"NO";

	return 0;
}