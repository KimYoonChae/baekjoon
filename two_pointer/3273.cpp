#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int r;
    cin>>r;
    sort(num.begin(),num.end());
   

    int s=0,e=n-1;
    int count=0;
    while (s<e)
    {
        if(num[s]+num[e]==r) {
            count++;  s++; e--;
        }
        else if(num[s]+num[e]>r){
            e--;
        }
        else{
            s++;
        }

    }
    cout<<count;



}