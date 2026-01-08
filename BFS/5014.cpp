#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
1. 노드: 계단의 각 층
2. 이동: 업, 다운
3. 시작점: s
4. 끝내야 하는 조건: s가 g에 도달했을떼
5. 방문처리:업, 다운 해보면서 갔던 층은 체크하기
*/


static vector<int>visited;
int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;

    queue<int>q;
    visited.resize(f+1,-1);
    //시작점 처리
    q.push(s);
    visited[s]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        if(cur==g){
            cout<<visited[cur];
            return 0;
        }
       
        if(cur+u<=f&&visited[cur+u]==-1){
            visited[cur+u]=visited[cur]+1;
            q.push(cur+u);
        }

        if(cur-d>=1&&visited[cur-d]==-1){
            visited[cur-d]=visited[cur]+1;
            q.push(cur-d);
        }
    }



    cout<<"use the stairs";

}