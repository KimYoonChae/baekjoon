#include <iostream>
#include <vector>
using namespace std;
/*
입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

컴퓨터 수: 노드 개수
직접 연결되어 있는 컴퓨터 쌍의 수: 애지 개수

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/
static vector<vector<int>> L;
static vector<bool> visited;
void DFS(int node);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,e;
    cin>>n;
    cin>>e;

    L.resize(n+1);
    visited.resize(n+1,false);

    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        L[a].push_back(b);
        L[b].push_back(a);
    }

    DFS(1); int count=0;
    for(int i=2;i<n+1;i++){
        count+=visited[i];
    }
    cout<<count;
}

//DFS 1번 = connected componenet 1개
void DFS(int node){
    visited[node]=true;
    for(int i:L[node]){
        if(!visited[i]){
            visited[i]=true;
            DFS(i);
        }
    }
}