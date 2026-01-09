#include <stdio.h>
int main(){
    int n,input;
    int flag=0,r;
    scanf("%d",&n);
    int arr[101];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&input);
        arr[i]=input;
        }
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=1;j<=n;j++){
            r=arr[i]%j;
            if(j!=1&&r==0) flag=1;
            if(j!=n&&r==0) flag=1;
        }
        if(flag==1) count++;

    }
    printf("%d",n-count);
 
    return 0;
}