#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createnode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* deleted(node* root,int val){
    int c=0;
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{
            node* x=root->right;
            while(x->left!=NULL){
                x=x->left;
            }
            root->data=x->data;
            root->right=deleted(root->right,root->data);
            return root;
        }
    }
    if(val>=root->data){
        root->right=deleted(root->right,val);
    }
    else{
       root->left= deleted(root->left,val);
    }
    return root;
}

node* check(node* root,int val){
    if(root==NULL){
        return createnode(val);
    }
    if(val>=root->data){
        root->right=check(root->right,val);
    }
    else{
        root->left=check(root->left,val);
    }
    return root;
}

void build(node* root){
    int a;
    printf("Enter the node value (enter -1 to exit): ");
    scanf("%d",&a);
    if(a==-1){
        return;
    }
    check(root,a);
    build(root);
}

void traversal(node* root){
    if(root==NULL){
        return;
    }
    traversal(root->left);
    printf("%d   ",root->data);
    traversal(root->right);
}

int checkbst(node* root, int min_val, int max_val) {
    int d = 1;
    if (root == NULL) {
        return d; 
    }
    if (root->data <= min_val || root->data >= max_val) {
        d = 0;     
        return d;  
    }
    int left_d = checkbst(root->left, min_val, root->data);
    int right_d = checkbst(root->right, root->data, max_val);
    if (left_d == 0 || right_d == 0) {
        d = 0; 
    }
    return d;
}

int main(){
    int c;
    printf("Enter the root node value: ");
    scanf("%d",&c);
    node* root=createnode(c);
    build(root);
    
    printf("\nInorder Traversal: ");
    traversal(root);
    printf("\n");
    
    int v= checkbst(root, -10000, 10000);
    printf("Is the tree a valid BST? (1 for Yes, 0 for No): %d\n", v);
    
    int d;
    printf("\nEnter the node u wanna to delete: ");
    scanf("%d",&d);
    root=deleted(root,d);
    
    printf("\nInorder Traversal after deletion: ");
    traversal(root);
    printf("\n");
    
    return 0;
}