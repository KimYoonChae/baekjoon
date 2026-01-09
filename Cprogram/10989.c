#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int arr[10000000];
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }

    /* 버블 소트
    for(int i=0;i<num;i++){
        for(int j=0;j<num-1-i;j++){
            if(arr[j]>arr[j+1]){
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    */

    int counting[10000000]={0};int idx;
    for(int i=0;i<num;i++){
        counting[(arr[i])]+=1;
    }
    for(int i=0;i<num;i++){
        if(counting[i]==0){
            idx=i;
            break;
        }
    }

    int c=0;

    for(int i=0;i<idx;i++){
        counting[i+1]=counting[i]+counting[i+1];
    } // 누적합 만들기
    int arr1[10000000];
  for(int i=num-1;i>=0;i--){
       // counting[arr[i]]=counting[arr[i]]-1;
       // arr1[counting[arr[i]]-1]=counting[arr[i]];
        int value = arr[i];
        counting[value]--;
        arr1[counting[value]] = value;
    }








/*

  for(int i=0;i<idx;i++){
        printf("%d ",counting[i]);
    }

 */

 
    for(int i=0;i<num;i++){
        printf("%d\n",arr1[i]);
    }
}