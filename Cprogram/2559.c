#include <stdio.h>
int main(){
    int n, k, arr[100001],sum[100001]={0};
    scanf("%d %d",&n,&k);

    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int a=1;
    for(int i=1;i<=n-k+1;i++){

        for(int j=1;j<=k;j++){
            sum[i]+=arr[a++];
        }a=a-(k-1);

    
    }
int max;
       for(int i=1;i<=n-k+1;i++){
        if(i==1)max=sum[i];
        if(sum[i]>max) max=sum[i];
    }
    printf("%d",max);



}