#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n,sum=0,count=0;
    cin>>n;

    stack<int> s;

    while(1){
        if(sum<n){
            s.push(1);
            sum++;
        }
        else{
            if(sum==n){
                count++;
            }
            while(!s.empty()&&s.top()==2){
                sum-=2;
                s.pop();
            }
            if(s.empty()) break;

            s.pop();
            sum-=1;
            s.push(2);
            sum+=2;
        }
    }
    cout<<count;

}