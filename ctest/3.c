#include <stdio.h>
int main(){
    int p;
    scanf("%d",&p);

    if(p>=100000){
       p*=0.8;
    }
    else if(p>=50000){
        p*=0.9;
    }
    

    printf("%d", p);
    return 0;
}