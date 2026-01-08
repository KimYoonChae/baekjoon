#include <iostream>
#include <stack>
using namespace std;
int check[2001][2001]={0};
int main(){
    //노드 개수, 엣지 개수 입력받기
    int n,m;
    cin>>n>>m;

    //연결되어 있는 노드 체크 하기
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        check[a][b]=1;
        check[b][a]=1;
    }
    int flag=1;

    //모든 노드들 돌면서 방문 여부 체크하고,
    int visited[2001]={0};
    stack<int> s;
    for(int i=0;i<n;i++){
        int count=0;
        if(visited[i]==1) continue;
        s.push(i);
        visited[i]=1;


        while(!s.empty()){
            int cur=s.top();
        
            s.pop();
            for(int j=0;j<n;j++){
                if(check[cur][j]==1&&visited[j]==0){
                    visited[j]=1;
                    s.push(j);
                }
            }
            
        }
    }
   
    for(int i=0;i<n;i++){ int sum=0;
        for(int j=0;j<n;j++){
        cout<<check[i][j]<<' ';
        }
       
      cout<<'\n';
    }
   // cout<<flag;
}