#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int>num;
    num.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    //정렬
    sort(num.begin(),num.end());

    int count=0;

    for(int i=0;i<n;i++){
        int s=0, e=n-1;
        int kijun=num[i];

        while(s<e){
            if(num[s]+num[e]==kijun){
                if(s!=i&&e!=i){
                    count++;
                    break;
                }
                else if(s==i){
                    s++;
                }
                else if(e==i){
                    e--;
                }
            }
            else if(num[s]+num[e]<kijun){
                s++;
            }
            else{
                e--;
            }
        }
    }
    cout<<count;
}