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
node* build(){
    node* root;
    int n;
    scanf("%d",&n);
    if(n==-1){
        return NULL;
    }
    root=create(n);
    printf("Enter the left node of %d ",root->data);
    root->left=build();
    printf("Enter the right node of %d: ",root->data);
    root->right=build();
    return root;
}
void printt(node* root){
    if(root==NULL){
        return;
    }   
     node* temp=root;
     printt(temp->left);
     printf("%d  ",temp->data);
     printt(temp->right);
}
int c=0;
int count(node* root){
    if(root==NULL){
        return 0;
    }   
     node* temp=root;
     count(temp->left);
     c++;
     count(temp->right);
     return c;
}
int main(){
    node* root;
    printf("Enter the valur of root Node");
    root=build();
    printt(root);
    printf("\n");
    printf("No of Node are %d",count(root));
}