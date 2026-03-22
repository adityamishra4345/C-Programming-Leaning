#include<stdio.h>
void buuble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
    int arr[]={1,4,32,6,8,5,55,12,111};
    buuble_sort(arr,9);
    for(int i=0;i<9;i++){
        printf("%d   ",arr[i]);
    }
    return 0;
}