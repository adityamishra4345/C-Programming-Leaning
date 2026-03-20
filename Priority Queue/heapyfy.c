#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
void swap(int* a,int* b){
 int temp=*a;
    *a=*b;
    *b=temp;
}

void heapi(int arr[],int n,int i){
    int l=i;
    int lft=(2*i)+1;
    int right=(2*i)+2;
    if(lft<n&&arr[lft]>arr[l]){
        l=lft;
    }
    if(right<n&&arr[right]>arr[l]){
        l=right;
    }
    if(l!=i){
        swap(&arr[i],&arr[l]);
    }
    if(l!=i){
        heapi(arr,n,l);
    }
}
void heapify(int arr[],int min,int n){
    for(int i=min;i>=0;i--){
        heapi(arr,n,i);
    }
}

int main(){
    int arr[]={1, 43, 21, 32, 27, 89, 54, 34, 33};
    int n=sizeof(arr)/4;
    int min=(n-2)/2;
    heapify(arr,min,n);
    printf("DONE!!!!\n");
    for(int k=0;k<n;k++){
        printf("%d  ",arr[k]);
    }
    

    return 0;
}