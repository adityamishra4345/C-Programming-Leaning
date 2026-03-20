//implementation of max priority queue using queue 
#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int* b){
 int temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void insert(int arr[],int val,int n){
    int c=n-1;
    // for(int i=n-1;i>0;i--){
    //     if(val<arr[i]){
    //         c=i+1;
    //         break;
    //     }
    // }
    for(int i=n-2;i>=0&&val<arr[i];i--){
        arr[i+1]=arr[i];
           c=i;
    }
    arr[c]=val;
}
int pop(int arr[],int* n){
    int c=arr[(*n)-1];
    (*n)--;
    return c;
}
void printq(int arr[],int n){
     for(int k=0;k<n;k++){
        printf("%d  ",arr[k]);
    }
}
int main(){
    int arr[100]={3,4,2,77,5,56,44};
    int n=7;
    printq(arr,n);
    printf("\n");
    bubblesort(arr,n);
    printq(arr,n);
    n++;
    insert(arr,50,n);
    printf("\n");
    printq(arr,n); 
    pop(arr,&n);
    
    printf("\n");
    printq(arr,n); 
    

    return 0;
}