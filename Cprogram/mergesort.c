#include <stdio.h>
int sorted[100];
void merge(int arr[], int left, int mid, int right){
    int i=left;
    int j=left;
    int k=mid+1;

    while(i<=mid&&k<=right){
        if(arr[i] <= arr[k]){
            sorted[j++]=arr[i++];
        }
        else{
            sorted[j++]=arr[k++];
        }
    }
    if(i>mid){
        for(int l=i;l<=mid;l++) sorted[j++]=arr[l];
    }else {
        for(int l=k;l<right;l++) sorted[j++]=arr[l];
    }

    for(int l=left;l<=right;l++){
        arr[l]=sorted[l];
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
    int arr[8]={21, 10, 12, 20, 25, 13, 15, 22};
    merge_sort(arr,0,8);
      for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }


}