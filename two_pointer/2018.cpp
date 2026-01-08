#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int sum=1;
    int start=1;
    int end=1;
    int count=1;
    while(end!=n){
        if(sum==n){
            count++;
            end++;
            sum=sum+end;
        }
        else if(sum>n){
            sum=sum-start;
            start++;
        }
        else{
            end++;
            sum=sum+end;
        }
    }
    cout<<count;
}