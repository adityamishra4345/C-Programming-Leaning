#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;
node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* make(node* root,int n){
    if(root==NULL){
        return create(n);
    }
    if(root->data>=n){
        root->left=make(root->left,n);
    }
    else{
        root->right=make(root->right,n);
    }
    return root;
}
node* build(node* root){
    int n;
    printf("Enter the node value");
    scanf("%d",&n);
    if(n==-1){
        return root;
    }
    root=make(root,n);
    build(root);

}
void bstsearch(node* root,int val,int* c){
    node* temp=(node*)malloc(sizeof(node));
    temp=root;
     if(temp==NULL){
        return ;
    }
    if(temp->data==val){
        *c=1;
        return ;
    }
    if(temp->data>=val){
        bstsearch(temp->left,val,c);
    }
    else{
        bstsearch(temp->right,val,c);
    }
}
void printb(node* root){
    node* temp=root;
    if(temp==NULL){
        return;
    }
    printb(temp->left);
    printf("%d ",temp->data);
    printb(temp->right);
   
    return;
}
int main(){
    printf("Enter the value of root node: ");
    int n,c=0;
    scanf("%d",&n);
    node* root=create(n);
    build(root);
    printb(root);
    printf("\nEnter the value to be searched: ");
    scanf("%d",&n);
    bstsearch(root,n,&c);
    if(c==1){
        printf("Found");
    }
    else{
        printf("Not Found");
    }
}