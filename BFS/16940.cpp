#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int main() {
	int n;
	cin>>n;
    queue<int>q;
	int a,b;
	vector<vector<int>> V;vector<vector<int>> V2;
	V.resize(n+1); V2.resize(n+1);


	vector<int>check;
	for(int i=0;i<n-1;i++){
      cin>>a>>b;
	  V[a].push_back(b);
	 // V2[a].push_back(b);
	}

	vector <int> compare;
	compare.resize(n+1);
	for(int i=0;i<n;i++){
		cin>>compare[i];
	}


	vector<int> visited;
	visited.resize(n+1,0);

	visited[compare[n-1]]=1;
	q.push(compare[n-1]);

	vector<int> result;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		result.push_back(cur);
		for(int i : V[cur]){
			if(visited[i]==0){
				q.push(i);
				visited[i]=1;

			}

		}
	}/*
	vector<int> visited2;
	visited2.resize(n+1,0);
	visited2[1]=1;
	q.push(1);

	vector<int> result2;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		result2.push_back(cur);


		for(int i=V2[cur].size()-1;i>=0;i--){
			int j=V2[cur][i];
			if(visited2[j]==0){
				q.push(j);
				visited2[j]=1;
			}
		}
	}

	bool flag=true;
	for(int i=0;i<result.size();i++){
		//if(result[i]!=compare[i]) flag=false;
		cout<<result[i];
	}
	bool flag2=true;
	for(int i=0;i<result2.size();i++){
		//if(result2[i]!=compare[i]) flag2=false;
		cout<<result2[i];
	}

	//if(flag==true||flag2==true) cout<<1;

	//else cout<<0;
*/
	return 0;
}