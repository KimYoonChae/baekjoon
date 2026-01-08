//트리의 지름
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> edge;
static vector<vector<edge>> A;
static int visited[]
int n;
int main(){
    cin>>n;
    A.resize(n+1);

    int n1,cn,g;
    for(int i=0;i<n;i++){
        cin>>n1;
        while(1){
            cin>>cn;
            cin>>g;
            A[n1].push_back(make_pair(cn,g));
            if(cn==-1)break;
        }
    }
}