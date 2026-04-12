#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int arr[100];
    int rear;
    int n;
}Queue;
void intit(Queue* q){
    q->rear=-1;
    q->n=-1;
} 
void push(Queue* q,int val){
    if(q->rear>=100){
        printf("Queue full");
        return ;

    }
    if(q->rear==-1){
        q->rear=0;
    }
    q->n++;
    q->arr[q->n]=val;
}
int pop(Queue* q){
    if(q->rear==-1){
        printf("Queue Empty");
        return -1;
    }
    int a= q->arr[q->rear];
    q->rear++;
    return a;
}
int peek(Queue* q ){
    if(q->rear==-1){
        printf("Queue Empty");
        return -1;
    }
    return q->arr[q->rear];
}

void printq(Queue* q){
    for(int i=q->rear;i<=q->n;i++){
        printf("%d  ",q->arr[i]);
    }
    printf("\n");
}
int main(){
    Queue que;
    intit(&que);
    push(&que,1);
    push(&que,2);
    push(&que,3);
    push(&que,4);
    push(&que,5);
    push(&que,6);
    printq(&que);
    pop(&que);
    pop(&que);
    printq(&que);
    pop(&que);
    printq(&que);
    pop(&que);
    printq(&que);

    return 0;
}