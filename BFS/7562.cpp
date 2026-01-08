#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

static int dx[]={-2,-1,1,2,2,1,-1,-2};
static int dy[]={1,2,2,1,-1,-2,-2,-1};
static int A[301][301];
typedef pair<int,int>p;
int Size;
void BFS(int q,int w, int e, int r);

void BFS(int q,int w, int e, int r){
    queue<p> myqueue;
    memset(A,-1,sizeof(A));
    myqueue.push(make_pair(q,w));
    A[q][w]=0;
    while(!myqueue.empty()){
        p cur=make_pair(myqueue.front().first,myqueue.front().second);
        myqueue.pop();
        if(cur.first==e&&cur.second==r) return;
        for(int i=0;i<8;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=0&&y>=0&&x<Size&&y<Size){
                if(A[x][y]==-1){
                    A[x][y]=A[cur.first][cur.second]+1;
                    myqueue.push(make_pair(x,y));
                }
            }
        }

    }

}
int main(){
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        
        cin>>Size;
        int q,w; //현재칸
        cin>>q>>w;
        int e,r;//도착칸
        cin>>e>>r;
        BFS(q,w,e,r);
        cout<<A[e][r]<<"\n";
    }

}