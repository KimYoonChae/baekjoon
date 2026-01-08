#include <iostream>
#include <vector>
using namespace std;
/*
문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
*/
static int N; //노드 개수
static int visited[100000]={0};
static vector<vector<int>> A;
void DFS(int s);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    if(N<2) return 0;
    int a,b; //연결된 노드들
    A.resize(N+1);
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    DFS(1);
   for(int i=2;i<=N;i++){
        cout<<visited[i]<<"\n";
    }

}
void DFS(int s){
    for(int i:A[s]){
        if(visited[i]==0){
            visited[i]=s;
            DFS(i);
        }
    }
}