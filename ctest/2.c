#include <stdio.h>
int main(){
    int x,sum=0;
    scanf("%d",&x);

    for(int i=1;i<=x;i++){
        if(i%3==0) sum+=i;
    }
    printf("%d",sum);
}