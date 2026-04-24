#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data ;
    struct node* left;
    struct node* right;
    int height;
}node;
int maxi(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return 1+maxi(left,right);
}
node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->height=1;
    return newnode;
}
int bala(node* root){
    if(root==NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}
node* leftr(node* root){
    node* x=root->right;
    node* y=x->left;
    x->left=root;
    root->right=y;
    root->height=1+maxi(height(root->left),height(root->right));
    x->height=1+maxi(height(x->left),height(x->right));
    return x;
}
node* rightr(node* root){
    node* x=root->left;
    node* y=x->right;
    x->right=root;
    root->left=y;
    root->height=1+maxi(height(root->left),height(root->right));
    x->height=1+maxi(height(x->left),height(x->right));
    return x;
}
node* insert(node* root,int val){
    if(root==NULL){
        return create(val);
    }
    if(val>root->data){
        root->right=insert(root->right,val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{ 
        return root;
    }
    root->height=1+maxi(height(root->left),height(root->right));
    int bal=bala(root);
    if(bal>1&&val<root->left->data){
        return rightr(root);
    }
    else if(bal<-1&&val>root->right->data){
        return leftr(root);
    }
    else if(bal>1&&val>root->left->data){
        root->left=leftr(root->left);
        return rightr(root);
    }
    else if(bal<-1&&val<root->right->data){
        root->right=rightr(root->right);
        return leftr(root);
    }
    return root;
}
node* del()
