#include <iostream>
using namespace std;
int n,A[4][4];
bool flag=false;
void DFS(int a, int b){
	if(a<0||b<0||a>=n||b>=n) return;
	if(flag) return;
	if(a==n-1&&b==n-1) {
		flag=true;
		return;
	}

	
	int jump=A[a][b];
	if(jump==0)return;
	DFS(a+jump,b);
	DFS(a,b+jump);
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	DFS(0,0);
	if(flag) cout<<"HaruHaru";
	else cout<<"Hing";
	return 0;
}