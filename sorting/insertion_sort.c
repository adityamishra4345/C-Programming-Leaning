#include<stdio.h>
void swap(int* a,int* b){
    int c=*a;
    *a=*b;
    *b=c;
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int arr[]={1,3,6,3,99,66,34,77777,2,7,6,9};
    int n=12;
    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}
