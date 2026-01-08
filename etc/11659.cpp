#include <iostream>
using namespace std;
#include <vector>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::vector<int> s;
    s.push_back(0);
    int a,b; cin>>a>>b;
    int x;
    for(int i=1;i<=a;i++){
        cin>>x;
        s.push_back(x+s[i-1]);
    }
    int y,z;
    for(int i=1;i<=b;i++){
        cin>>y>>z;
        cout<<s[z]-s[y-1]<<'\n';
    }


}