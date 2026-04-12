#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    
}node;
typedef struct queue{
    struct node* rear;
    struct node* front;
}que;
void init(que* queue){
    queue->front=NULL;
    queue->rear=NULL;
}
node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
void insert(que* queue,int val){

    node* temp=create(val);
    if(queue->front==NULL){
        queue->front=temp;
        queue->rear=temp;
    }
    else{
        queue->rear->next=temp;
        queue->rear=temp;
    }

}
int pop(que* queue){
    if(queue->front==NULL){
        printf("Queue Empty");
        return -1;
    }
    int a=queue->front->data;
    queue->front=queue->front->next;
    printf("popped %d according to FIFO\n",a);
    return a;
}
void printq(que* queue){
    node* temp=queue->front;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    que queue;
    init(&queue);
    insert(&queue,1);
    insert(&queue,2);
    insert(&queue,3);
    insert(&queue,4);
    insert(&queue,5);
    insert(&queue,6);
    printq(&queue);
    pop(&queue);
    pop(&queue);
    pop(&queue);
    pop(&queue);

    return 0;
}