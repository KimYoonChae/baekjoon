#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<5||n>100) return 0;

    int x[100],y[100],a=0,b=0;

    for(int i=1;i<50;i++){
        for(int j=1;j<50;j++){
            if((2*i+3*j)==n){
                x[a++]=i;
                y[b++]=j;
            }
        }
    }

    for(int i=0;i<a;i++){
printf("x= %d y= %d\n",x[i],y[i]);

    }
    return 0;
}