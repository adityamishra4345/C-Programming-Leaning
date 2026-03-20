#include<stdio.h>
#include<stdlib.h>
//write a code to mirror a binary tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void mirror(struct node* root){
    if(root == NULL){
        return;
    }
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main(){
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Inorder traversal of the original tree: ");
    inorder(root);
    printf("\n");
    mirror(root);
    printf("Inorder traversal of the mirrored tree: ");
    inorder(root);
    printf("\n");
    return 0;
}
