#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} root;
root* createnode(int val){
    root* newnode=(root*)malloc(sizeof(root));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void printtree(root* root){
    if(root==NULL){
        return ;
    }
    printtree(root->left);
    printf("%d  ",root->data);
    printtree(root->right);

}
int d=0,k=0;
int depth(root* root){
     if(root==NULL){
        return 0;
    }
    d++;

     if(d>k){
        k=d;
    }
    depth(root->left);
   
    depth(root->right);
     
    d--;
    return k-1;
}
void mirror(root* tree){
     if(tree==NULL){
        return ;
    }
    root* newnode=tree->left;
    tree->left=tree->right;
    tree->right=newnode;
    mirror(tree->left);
    mirror(tree->right);
}
int c=0;
int single(root* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right!=NULL){
        c++;
    }
    else if(root->right==NULL&&root->left!=NULL){
        c++;
    }
    single(root->left);
    single(root->right);
    return c;

}
int main(){
    root* root=createnode(5);
    root->left=createnode(2);
    root->right=createnode(3);
    
    root->left->right=createnode(3);
    root->right->left=createnode(2);
    
    printtree(root);
    printf("\n");
    printf("%d",single(root));
    printf("\n");
    printf("%d",depth(root));
    mirror(root);
    printf("\n");
    printtree(root);


    
    

}