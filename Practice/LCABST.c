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
node* make(node* root, node* x){
    if(root==NULL){
        return x;
        }
    
    if(x->data>=root->data){
        root->right=make(root->right,x);}
    
    else{
        root->left=make(root->left,x);
    }
    return root;
}

    

node* build(node* root){
    int n;
    printf("Enter the value of node : ");
    scanf("%d",&n);
    if(n==-1){
        return NULL;
    }
    node* x=create(n);
    make(root,x);
    build(root);
    return root;

}
void lca(node* root,int n,int m,int* c){
    if(root==NULL){
        return ;
    }
    else{
        if(n>root->data&&m>root->data){
            lca(root->right,n,m,c);
        }
        else if(n<root->data&&m<root->data){
            lca(root->left,m,n,c);
        }
        else {
            *c=root->data;
        }
        
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
    int n;
    scanf("%d",&n);
    node* root=create(n);
    build(root);
    printb(root);
    int c=root->data;
    printf("\nEnter the no whose lca u have to find");
    int m, o;
    scanf("%d %d",&m,&o);
    lca(root,m,o,&c);
    printf("\nLCA of %d , %d is %d",m,o,c);
}