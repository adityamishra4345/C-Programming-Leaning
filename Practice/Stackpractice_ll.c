#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct stack{
    struct node* top;
}stack;
void initstack(stack* arr){
    arr->top=NULL;
}
node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void insert(stack* arr){
    printf("Enterr the element: ");
    int a;
    scanf("%d",&a);
    node* temp=create(a);
    temp->next=arr->top;
    arr->top=temp;
}
int pop(stack* arr){
    if(arr->top==NULL){
        printf("Stack empty");
        return -1;
    }
    int a=arr->top->data;
    arr->top=arr->top->next;
    return a;
}
int peek(stack* arr){
    if(arr->top==NULL){
        printf("Stack empty");
        return -1;
    }
    return arr->top->data;
}
void prints(stack* arr){
    node* temp=arr->top;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    stack arr;
    initstack(&arr);
    int a;
    printf("Enter how many values you wanna to enter: ");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        insert(&arr);
    }
    printf("%d is top value and is deleted\n",pop(&arr));
    printf("%d is top value ",peek(&arr));
}