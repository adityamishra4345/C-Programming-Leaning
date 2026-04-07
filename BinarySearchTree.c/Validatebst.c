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
node* build(node* root){
    printf("Enter the left node of %d : ",root->data);
    int n;
    scanf("%d",&n);
    if(n!=-1){
        root->left=create(n);
        build(root->left);
    }
    printf("Enter the right node of %d : ",root->data);
    scanf("%d",&n);
    if(n!=-1){
        root->right=create(n);
        build(root->right);
    }
        
    return root;

}

int bstchecker(node* root,int min,int max){
    if(root==NULL){
        return 1;
    }
    if(root->data<min || root->data>max){
        return 0;
    }
    return bstchecker(root->left,min,root->data-1) && bstchecker(root->right,root->data+1,max);
}

int main(){
    int n,val;
    printf("Enter the root node:");
    scanf("%d",&n);
    node* root=create(n);
    build(root);
    if(bstchecker(root,-10000,10000)){
        printf("The tree is a BST");
    }
    else{
        printf("The tree is not a BST");
    }
    return 0;
}
