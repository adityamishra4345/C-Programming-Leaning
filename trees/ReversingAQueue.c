//code to reverse the order of a queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
} queue;
queue* createqueue() {
    queue* newqueue = (queue*)malloc(sizeof(queue));
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}
void enqueue(queue* q, const char* data) {
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->data, data);
    newnode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}
char* dequeue(queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    
    node* temp = q->front;
    
    char* result = (char*)malloc(strlen(temp->data) + 1);
    strcpy(result, temp->data);
    
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return result; 
}
void reversequeue(queue* q) {
    if (q->front == NULL) {
        return;
    }
    
    char* data = dequeue(q);
    reversequeue(q);
    enqueue(q, data);
    free(data);
}
void printqueue(queue* q) {
    node* current = q->front;
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    queue* q = createqueue();
    
    enqueue(q, "1");
    enqueue(q, "2");
    enqueue(q, "3");
    enqueue(q, "4");
    enqueue(q, "5");
    
    printf("Original queue: ");
    printqueue(q);
    
    reversequeue(q);
    
    printf("Reversed queue: ");
    printqueue(q);
    
    return 0;
}
