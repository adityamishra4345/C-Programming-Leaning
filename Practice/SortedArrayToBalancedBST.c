#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;

}node;
node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* make(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node* root=create(arr[mid]);
    root->left=make(arr,start,mid-1);
    root->right=make(arr,mid+1,end);
    return root;
}
void printb(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    printb(temp->left);
    printf("%d  ",temp->data);
    printb(temp->right);
    return;
}
int main(){
    int arr[15]={1,2,3,4,5,6,7,8,9};
    node* root;

    root=make(arr,0,8);
    printb(root);
    return 0;
}