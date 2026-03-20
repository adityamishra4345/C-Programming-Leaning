#include<stdio.h>
void swap(int* a,int* b){
    int c=*a;
    *a=*b;
    *b=c;
}
int main(){
    int arr[]={1,3,6,3,99,66,34,77777,2,7,6,9};
    for(int i=0;i<12 ;i++){
        int k=i+1;
        int j=i;
        while(j>=0){
            if(arr[k]<arr[j]){
                swap(&arr[k],&arr[j]);
            k--;
        }
            j--;
            }
        }
    for(int z=0;z<12;z++){
        printf("%d  ",arr[z]);
    }
    }
