#include <stdio.h>
int main(){
    int x;
    int h,m,s;
    scanf("%d",&x);
    if(x>=3600){
        h=x/3600;
        m=(x%3600)/60;
        s=(x%3600)%60;
    }
    else if(x>=60){
        h=0;
        m=x/60;
        s=x%60;
    }
    else{
        h=0;
        m=0;
        s=x;
    }
    printf("%dh %dm %ds",h,m,s);
    return 0;
}