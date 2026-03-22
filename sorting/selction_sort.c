#include<stdio.h>
void selection_sort(int arr[],int n){
      for(int i=0;i<n;i++){
        int min_idx=i;
        for(int j=i;j<n-1;j++){
            if (arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
}
}
int main(){
    int arr[]={23,3,34,56,777,86,4,33,222};
    int n=sizeof(arr)/4;
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d   ",arr[i]);
    }
}