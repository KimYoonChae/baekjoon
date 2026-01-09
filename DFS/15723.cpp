#include <iostream>
#include <vector>
using namespace std;

int n,m;
int A[27],R[27],visited[27]={0};
vector<int>v;
void dfs(int a){
	visited[a]=1;
	v.push_back(a);
	if(visited[A[a]]==0){
		dfs(A[a]);
	}
}
int main() {
	cin>>n;
	cin.ignore();

	int first;
	
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		A[s[0]-'a']=s[5]-'a';
		if(i==0) first=s[0]-'a';
	}
	dfs(first);

	cin>>m;
	cin.ignore();
	for(int i=0;i<m;i++){
		string s;
		getline(cin,s);
		R[s[0]-'a']=s[5]-'a';
		if()
	}

	for(int i=0;i<m;i++){
		if(R)
	}
	

	return 0;
}