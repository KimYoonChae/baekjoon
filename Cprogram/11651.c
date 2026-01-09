#include <stdio.h>
typedef struct 
{
    int x;
    int y;
}Point;

Point sorted[100000];

void merge(Point arr[],int left, int mid, int right){
    int l=left, s=left, r=mid+1;
    while(l<=mid&&r<=right){
        if(arr[l].y<arr[r].y||
            (arr[l].y==arr[r].y&&arr[l].x<arr[r].x)) sorted[s++]=arr[l++];
        else{
            sorted[s++]=arr[r++];
        }
    }
    while(l<=mid) {
        sorted[s++]=arr[l++];
    }
    while(r<=right){
        sorted[s++]=arr[r++];
    }
    for(int i=left;i<=right;i++){
        arr[i]=sorted[i];
    }
}

void merge_sort(Point arr[],int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr, left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left, mid,right);
    }
}

int main(){
    int num;
    Point arr[100000];

    scanf("%d",&num);
    
    for(int i=0;i<num;i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    merge_sort(arr,0,num-1);
    for(int i=0;i<num;i++){
        printf("%d %d\n",arr[i].x,arr[i].y);
    }

    return 0;
}

