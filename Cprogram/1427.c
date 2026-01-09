#include <stdio.h>
int main(){
    int num,n=1;
    scanf("%d",&num);
    if(num/10==0) printf("%d",num);
    else{
        while(1){
           if((num/(10*n))==0) break;
           n*=10;
        }//자릿수 알아내기 n=자릿수

int arr[100], index=0,r ,num2=num;
    while(1){
        if(index==0){
            r=num/n;
            arr[index]=r;
            num2=num-(n*r);
        }
        n=n/10; index++;
        r=num2/n;
        arr[index]=r;
        num2=num2-(n*r);   
        
        if(n==1) break;
    }
    /*for(int i=0;i<index+1;i++){
        printf("%d ",arr[i]);
    }*/

   for(int i=0;i<index;i++){
        for(int j=0;j<index-i;j++){
            if(arr[j]<arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
   // printf("\n");
       for(int i=0;i<index+1;i++){
        printf("%d",arr[i]);
    }

    } 

    

}