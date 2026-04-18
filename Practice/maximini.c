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

int c=-1000000;
int maxi(node* root){
    if(root==NULL){
        return 0;
    }   
     node* temp=root;
     maxi(temp->left);
     if(temp->data>c){
        c=temp->data;
     }
     maxi(temp->right);
     return c;
}
int d=1000000;
int mini(node* root){
    if(root==NULL){
        return 0;
    }   
     node* temp=root;
     mini(temp->left);
     if(temp->data<d){
        d=temp->data;
     }
     mini(temp->right);
     return d;
}
int main(){
    node* root;
    printf("Enter the valur of root Node");
    root=build();
    printt(root);
    printf("\n");
    printf("Maximum of Node are %d",maxi(root));
     printf("\n");
    printf("Minimum of Node are %d",mini(root));
}