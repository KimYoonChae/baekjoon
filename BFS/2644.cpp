#include <iostream>
#include <vector>
using namespace std;
/*
입력
사람들은 1, 2, 3, …, n (1 ≤ n ≤ 100)의 연속된 번호로 각각 표시된다. 
입력 파일의 첫째 줄에는 전체 사람의 수 n이 주어지고, 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호가 주어진다. 
그리고 셋째 줄에는 부모 자식들 간의 관계의 개수 m이 주어진다. 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.

각 사람의 부모는 최대 한 명만 주어진다.

출력
입력에서 요구한 두 사람의 촌수를 나타내는 정수를 출력한다. 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1을 출력해야 한다.
*/
static int visited[101]={0};
static vector<vector<int>>A;
void DFS(int a, int b, int depth);
int a,b; //촌수를 구해야 하는 서로 다른 두 사람의 번호
int d=-1;
int cnt=0;
int main(){
    int n;
    cin>>n; //전체 사람의 수 == 노드 개수
    
    cin>>a>>b;
    int m; //부모 자식들 간의 관계의 개수 == 앳지 개수
    cin>>m;

 
    int x,y;
    A.resize(n+1);
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

 DFS(a,b,0);
 cout<<d;


  

   
}

void DFS(int a, int b, int depth){
  visited[a-1]=1;
  if(a==b) {
    d=depth;
    return;
  }

  for(int i:A[a]){
    if(visited[i-1]==0){
      DFS(i,b,depth+1);
    }
  }

}