#include <iostream>
#include <string>
using namespace std;
string p[10001];
int main(){
    int test; //테스트 케이스
    int number; //전화번호 개수

   cin>>test;
    int flag=1;
    int count=0;

    for(int i=0;i<test;i++){ //테스트 케이스 만큼 반복
        //전화번호 몇개 입력받을건지 입력받기
        cin>>number;
        for(int j=0;j<number;j++){
            cin>>p[j];
        } // 전화번호 입력받기
        int min,c=0; string minstr;
        for(int t=0;t<number;t++){ // 전화번호 개수동안 반복
            if(t==0) { //초기에는 0번을 min으로 설정
            min=p[0].length();
            minstr=p[0];
            }
            if(p[t].length()>min){
                for(int k=0;k<min;k++){
                    if(minstr[k]==p[t][k]){
                        count++;
                    }
                }if(count==min){
                    flag=0;
                    break;
                }
            }
            min=p[t+1].length();
            minstr=p[t+1];
        }
    }

    if(flag==0) printf("No\n");
    else printf("Yes\n");
    
}