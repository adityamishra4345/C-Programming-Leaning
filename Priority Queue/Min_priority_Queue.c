#include<stdio.h>
#include<stdlib.h>
//#define max(a,b) (((a) > (b)) ? (a) : (b))
void swap(int* a,int* b){
 int temp=*a;
    *a=*b;
    *b=temp;
}

void heapi(int arr[],int n,int i){
    int l=i;
    int lft=(2*i)+1;
    int right=(2*i)+2;
    if(lft<n&&arr[lft]<arr[l]){
        l=lft;
    }
    if(right<n&&arr[right]<arr[l]){
        l=right;
    }
    if(l!=i){
        swap(&arr[i],&arr[l]);
        heapi(arr,n,l);
    }
   
}
void heapify(int arr[],int min,int n){
    for(int i=min;i>=0;i--){
        heapi(arr,n,i);
    }
}
//since we have to pop the most priority element i.e arr[0],or CEO
//this is wrong as since we made the tree correct but for it to be a  heap 
//it must be  complete binary tree i.e since we removed one ceo
//size decrease by 1 and since their will be one empty seat which is for 
//tree it will be at bottom but for arr it lies somewhere in middle i.e 
//for our case it will be [54, 43, 21, 34, 27, EMPTY, 1, 32, 33]
//and for heap size will be decresed by one and we end up losing last element \
//i.e 33. 

// void pop(int arr[],int n,int i){
//     if(2*i+1<n && arr[2*i+1]>=arr[2*1+2]){
//         arr[i]=arr[2*i+1];
//         i=2*i+1;
//         pop(arr,n,i);
//     }
//     else if(2*i+2<n && arr[2*i+1]<arr[2*1+2])
//     {
//         arr[i]=arr[2*i+2];
//         i=2*i+2;
//         pop(arr,n,i);
//     }


// }
int pop(int arr[],int n,int i){
    arr[i]=arr[n-1];
    heapi(arr,n-1,i);
}
void fixpostn(int arr[],int n,int i){
    if(i<=0) return;
    if(arr[i]<arr[(i-1)/2]){
        swap(&arr[i],&arr[(i-1)/2]);
        i=(i-1)/2;
        fixpostn(arr,n,i);
    }
    
}
void insert(int arr[],int val,int n){
    int i=n-1;
    arr[i]=val;
    fixpostn(arr,n,i);
}
void printheap(int arr[],int n){
        for(int k=0;k<n;k++){
        printf("%d  ",arr[k]);
    }
}

int main(){
    int arr[100]={1, 43, 21, 32, 27, 89, 54, 34, 33};
    int n=9;
    int min=(n-2)/2;
    
    heapify(arr,min,n);
    printf("DONE!!!!\n");
    printheap(arr,n);
    printf("\nPopping done \n");
    pop(arr,n,0);
    n--;
    printheap(arr,n);
    n++;
    insert(arr,50,n);
    printf("\ninsertion done \n");
    printheap(arr,n);

    

    return 0;
}