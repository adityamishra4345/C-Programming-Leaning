// int arr[100]={0,[3]=-2,[32]=-133} this makes index 3 ->-2 and 32th index ->-133 and rest are 0
#include<stdio.h>
void main(){
    int arr[100]={0,[3]=-2,[32]=-133};

     for(int i=0;i<100;i++){
        printf("%d ",arr[i]);
    }
}