#include <iostream>
#include <vector>
using namespace std;
/*
입력
첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 
둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 
다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다.
 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

출력
총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.
*/
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>A(m+1,vector<int>(m+1,0));
    vector<vector<int>>S(m+1,vector<int>(m+1,0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin>>A[i][j];
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int result=S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1];
        cout<<result<<"\n";
    }

}
