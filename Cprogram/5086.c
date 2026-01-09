#include <stdio.h>
int main(){
    int num,sum=0;
    int arr[100000];
    int arr2[100000]={0};
    int c=0;
    
while(1){
    scanf("%d",&num);
    if(num==-1) break;
    for(int i=1;i<num;i++){
        if(num%i==0) sum+=i;
    }

    if(sum==num) {
        arr2[c]=1;
    }
    arr[c]=num;
    c++;
     sum=0;
}

for(int i=0;i<c;i++)
 {
    if(arr2[i]==1) {
        printf("%d = 1 ",arr[i]);
        for(int j=1;j<arr[i];j++){
            if(arr[i]%j==0&&j!=1) printf("+ %d ",j);
        }
        printf("\n");
    } else if(arr2[i]==0) {
        printf("%d is NOT perfect.\n",arr[i]);
    }

 }
}