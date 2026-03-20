#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(struct Stack* stack) {
    if (stack->top == NULL) return;

    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

void display(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    display(myStack);

    pop(myStack);

    display(myStack);

    return 0;
}