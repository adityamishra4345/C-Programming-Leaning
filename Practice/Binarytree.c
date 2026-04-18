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
node* build(){
    node* root;
    int n;
    scanf("%d",&n);
    if(n==-1){
        return NULL;
    }
    root=create(n);
    printf("Enter the value of left node of %d ",root->data);
    root->left=build();
    printf("Enter the value of right node of %d ",root->data);
    root->right=build();
    return root;
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
void bfs(node* root){
    if (root == NULL) {
        return; 
    }
    node* arr[100];
    int rear=0;
    int front=0;
    arr[front]=root;
    front++;
    while(rear<front){
        node* curr=arr[rear];
        printf("%d ",curr->data);
        rear++;
        if(curr->left!=NULL){
            arr[front]=curr->left;
            front++;
    }
        if(curr->right!=NULL){
        arr[front]=curr->right;
        front++;
       } 
       
}  
}
int main(){
    printf("Enter the root Node : ");
    node* root=build();
    printb(root);
     printf("\n");
    bfs(root);

}