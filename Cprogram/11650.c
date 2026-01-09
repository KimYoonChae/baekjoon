#include <stdio.h>

typedef struct{
    int x;
    int y;
}Point;

Point sorted[100000];

void merge(Point arr[], int left, int mid, int right){
    int l=left, s=left,j=mid+1;
    while(l<=mid&&j<=right){
        if(arr[l].x<arr[j].x||(arr[l].x==arr[j].x&&arr[l].y<arr[j].y)) sorted[s++]=arr[l++];
        else sorted[s++]=arr[j++];
    }

    while(l<=mid) sorted[s++]=arr[l++];
    while(j<=right) sorted[s++]=arr[j++];

    for(int i=left;i<=right;i++){
        arr[i]=sorted[i];
    }
}
void merge_sort(Point arr[],int left, int right)
{
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}


int main(){
    int num;
    scanf("%d",&num);

    Point arr[100000];

    for(int i=0;i<num;i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    merge_sort(arr,0,num-1);

    for(int i=0;i<num;i++){
        printf("%d %d\n",arr[i].x,arr[i].y);
    }
}