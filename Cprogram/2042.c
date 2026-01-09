#include <stdio.h>
int main(){
      int n, m, k, a, b;
    long long c, tmp;
    int arr[10001];
    long long s[10001], result[10001];
    int r = 0;
    s[0]=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        s[i]=arr[i]+s[i-1];
    }
    for(int i=0;i<(m+k);i++){
        scanf("%d %d %lld",&a,&b,&c);
        if(a==1){
     
            if(c>arr[b]) {
                tmp=c-arr[b];
                for(int j=b;j<=n;j++){
                s[j]+=tmp;
            }
            }
            else{
                 tmp=arr[b]-c;
                 for(int j=b;j<=n;j++){
                s[j]-=tmp;
            }
            }
            arr[b]=c;
        }
        if(a==2){

            result[r]=s[c]-s[b-1];
            r++;
        }
    }
    for(int i=0;i<k;i++){
        printf("%lld\n",result[i]);
    }
}