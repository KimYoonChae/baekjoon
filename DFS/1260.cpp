#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> L; //인접 리스트
static vector<bool> visited; //방문 배열
void DFS(int node);
void BFS(int node);

int main(){
    int n,e,s; //노드 개수, 에지개수, 시작점
    cin>>n>>e>>s;

    L.resize(n+1);
    visited.resize(n+1,false);
    //시작노드, 끝 노드 입력받기
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        L[a].push_back(b);
        L[b].push_back(a);
    }

    //한 노드당 방문할 수 있는 노드가 여러개일때, 정렬을 해주기
    for(int i=1;i<=n;i++){
        sort(L[i].begin(),L[i].end());
    }

    DFS(s);
    cout<<"\n";
    fill(visited.begin(),visited.end(),false);
    BFS(s);
}

void DFS(int node){
    cout<<node<<" ";
    visited[node]=true;

    for(int i:L[node]){
        if(!visited[i]){
            DFS(i);
        }
    }
}

void BFS(int node){
    queue<int> q; //BFS에 사용할 큐
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        for(int i:L[cur]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
}