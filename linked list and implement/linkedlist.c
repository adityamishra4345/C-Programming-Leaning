#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct LL {
    node* head;
    node* tail;
} LL;

node* createNode(int val) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void initList(LL* list) {
    list->head = list->tail = NULL;
}
void pushfront(LL* list, int val) {
    node* newnode = createNode(val);
    if (list->head == NULL) {
        list->head = list->tail = newnode;
    } else {
        newnode->next = list->head;
        list->head = newnode;
    }
}

void printll(LL* list) {
    node* temp = list->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void pushback(LL* list, int val) {
    node* newnode = createNode(val);
    if (list->tail == NULL) {
        list->tail = list->head = newnode;
    } else {
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

int popback(LL* list) {
    if (list->head == NULL) {
        printf("empty list\n");
        return -1;
    } 
    
    if (list->head == list->tail) {
        int val = list->head->data;
        free(list->head);
        list->head = list->tail = NULL;
        return val;
    }

    
    node* prev = list->head;
    while (prev->next != list->tail) {
        prev = prev->next;
    }

    int val = list->tail->data;
    free(list->tail);
    list->tail = prev;
    list->tail->next = NULL;
    return val;
}
void freeList(LL* list) {
    node* current = list->head;
    node* next_node;

    while (current != NULL) {
        next_node = current->next; 
        free(current);             
        current = next_node;       
    }
    list->head = list->tail = NULL;
}

int main() {
    LL adi;
    initList(&adi);

    pushfront(&adi, 5);
    printll(&adi);
    printf("Popped: %d\n", popback(&adi));
    printll(&adi);

    pushfront(&adi, 7);
    pushfront(&adi, 6);
    pushback(&adi, 2);
    pushback(&adi, 90);
    pushback(&adi, 20);
    printll(&adi);

    int a = popback(&adi);
    printf("Popped: %d\n", a);
    printll(&adi);
    freeList(&adi);
    return 0;
}