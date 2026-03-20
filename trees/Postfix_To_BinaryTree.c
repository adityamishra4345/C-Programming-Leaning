//code to convert postfix expression to binary tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
} root;
typedef struct stack{
    root* data;
    struct stack* next;
} stack;
stack* createstack(){
    stack* newstack=(stack*)malloc(sizeof(stack));
    newstack->data=NULL;
    newstack->next=NULL;
    return newstack;
}
void push(stack** top, root* data){
    stack* newstack=createstack();
    newstack->data=data;
    newstack->next=*top;
    *top=newstack;
}
root* pop(stack** top){
    if(*top==NULL){
        return NULL;
    }
    stack* temp=*top;
    root* data=temp->data;
    *top=(*top)->next;
    free(temp);
    return data;
}
int isoperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return 1;
    }
    return 0;
}
root* createnode(char data){
    root* newnode=(root*)malloc(sizeof(root));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

root* postfixtotree(char* postfix){
    stack* top=NULL;
    for(int i=0; postfix[i]!='\0'; i++){
        if(isoperator(postfix[i])){
            root* newnode=createnode(postfix[i]);
            newnode->right=pop(&top);
            newnode->left=pop(&top);
            push(&top, newnode);
        }
        else{
            root* newnode=createnode(postfix[i]);
            push(&top, newnode);
        }
    }
    return pop(&top);
}
void inorder(root* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%c  ",root->data);
    inorder(root->right);

}
int main(){
    char postfix[]="ab+cde+**";
    root* tree=postfixtotree(postfix);
    printf("Inorder traversal of the binary tree: ");
    inorder(tree);
    printf("\n");
    return 0;
}
