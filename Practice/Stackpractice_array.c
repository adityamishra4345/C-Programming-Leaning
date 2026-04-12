#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int arr[100];
    int top;
}stack;
void init(stack* stk){
    stk->top=-1;
}
void push(stack* stk,int val){
    if(stk->top>100){
        printf("stack already full\n");
    }
    stk->top++;
    stk->arr[stk->top]=val;
}
int pop(stack* stk){
    if(stk->top==-1){
        printf("Empty Stack\n");
        return -1;
    }
    stk->top--;
    return stk->arr[stk->top+1];
}
int peek(stack* stk) {
    if (stk->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stk->arr[stk->top];
}
void search(stack* stk,int val){
    int c=0;
    for(int i=0;i<=stk->top;i++){
        if(stk->arr[i]==val){
            printf("%d found at %d postn\n",val,i);
            c=1;
        }
    }
    if(c==0){
        printf("value doesnt lie in stack\n");
    }
}
int isempty(stack* stk){
    if(stk->top==-1) {
        printf("Empty\n");
    }
    else{
        printf("Not Empty ,%d elemnts left\n",stk->top+1);

    }
}
int main(){
    stack arr;
    init(&arr);
    push(&arr,10);
    push(&arr,11);
    push(&arr,12);
    push(&arr,13);
    push(&arr,14);
    push(&arr,15);
    push(&arr,16);
    search(&arr,13);
    printf("%d is the top element",peek(&arr));
}