#include <iostream>
#include <stack>
using namespace std;
int check[10][10]={0};    

int main(){
    int n; //자리수 입력받기
    cin>>n;

    for(int i=1;i<=9;i++){
        //인접 행렬에 어떤 노드들끼리 연결이 되었는지 기록하기
       for(int j=1;j<=9;j++){
        if(i==2||i==3||i==5||i==7){
            if(j%2!=0){
                check[i][j]=1;
            }
        }
       }
    }

    int visited[10]={0}; //방문 여부 체크 배열 0으로 초기화

    //각 노드들 돌면서 체크하고, connected component 개수 세기
    stack<int> s;
    int count=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==1) continue;
        s.push(i);
        visited[i]=1;
        count++;

        

        while(!s.empty()){
            int cur=s.top();
            s.pop();
            for(int j=1;j<=n;j++){
               if(check[cur][j]==1&&visited[j]==0) {
                s.push(j);
                visited[j]=1;
               }
            }
            
        }
    }
    cout<<count;

}