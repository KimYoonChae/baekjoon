#include <iostream>
#include <algorithm>
using namespace std;

static int dx[]={0,1,0,-1};
static int dy[]={1,0,-1,0};
static int A[26][26];
static int visited[26][26];
void DFS(int i, int j);
static int N;
static int housecnt=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;

    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<N;j++){
            A[i][j]=s[j]-'0';
        }
    }
      for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visited[i][j]=0;
        }

    }
    int count=0;
   int numbers[26 * 26]; // 최대 단지 수
    int idx = 0;
   for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        if (A[i][j] == 1 && visited[i][j] == 0){
            housecnt = 0;
                DFS(i, j);
                numbers[idx++] = housecnt;
                count++;
           
         }
        
    }
        }
   sort(numbers, numbers + idx);

    cout << count << "\n";
    for (int i = 0; i < idx; i++) {
        cout << numbers[i] << "\n";
    }
 

}

void DFS(int i, int j){
   visited[i][j] = 1;
housecnt++;

    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];

        if(x>=0&&y>=0&&x<N&&y<N){
            if(A[x][y]!=0 && visited[x][y]==0){
               
                DFS(x,y);
            }
        }
    }

    
}