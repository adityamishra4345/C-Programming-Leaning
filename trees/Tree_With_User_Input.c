//Code to make a tree using user input

#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* createnode(int val){
    node* root= (node*)malloc(sizeof(node));
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    return root;
}
node* build(){
    int data;
    scanf("%d",&data);
    if(data==-1){
        return NULL;
    }
    node* root=createnode(data);
    printf("Enter the value for left child of %d(-1 for NULL):",data);
    root->left=build();
    printf("Enter the value for right child of %d(-1 for NULL):",data);
    root->right=build();
    return root;
}
void traversal(node* root){
    if(root==NULL){
        return;
    }
    traversal(root->left);
    printf("%d   ",root->data);
    traversal(root->right);

}
int main(){

    printf("Enter the value for root ");
    node* root=build();
    printf("your tree is:\n");
    traversal(root);


    return 0;
}