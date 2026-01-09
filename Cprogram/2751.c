#include <stdio.h>
int sorted[1000000];
void merge(int arr[], int left, int mid, int right){
    int l=left, s=left, j=mid+1;
    while(l<=mid&&j<=right){
        if(arr[l]<arr[j]) sorted[s++]=arr[l++];
        else sorted[s++]=arr[j++];
    }
    if(l>mid){
        for(int i=j;i<=right;i++) sorted[s++]=arr[i];
    }else{
        for(int i=l;i<=mid;i++) sorted[s++]=arr[i];
    }
    for(int i=left;i<=right;i++){
        arr[i]=sorted[i];
    }
}
void merge_sort(int arr[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}


int main(){
    int num,arr[1000000];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,num-1);
    for(int i=0;i<num;i++){
        printf("%d\n",arr[i]);
    }
}