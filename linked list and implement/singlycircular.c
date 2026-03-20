#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularList {
    struct Node* head;
    struct Node* tail;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct CircularList* createList() {
    struct CircularList* list = (struct CircularList*)malloc(sizeof(struct CircularList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addTail(struct CircularList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = list->head; // Point to itself
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head; // Point back to head to close circle
    }
}

void addHead(struct CircularList* list, int data) {
    struct Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = list->head; // Point to itself
    } else {
        newNode->next = list->head;
        list->head = newNode;
        list->tail->next = list->head; // Update tail to point to new head
    }
}

void deleteHead(struct CircularList* list) {
    if (list->head == NULL) return;

    struct Node* temp = list->head;

    if (list->head == list->tail) { // Only one node
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head; // Update tail to point to new head
    }
    
    free(temp);
}

void display(struct CircularList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = list->head;
    
    // We use a do-while loop because the condition (temp != head)
    // is false initially, but we need to run the loop at least once.
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    
    printf("(HEAD)\n");
}

int main() {
    struct CircularList* myList = createList();

    addTail(myList, 10);
    addTail(myList, 20);
    addTail(myList, 30);
    
    // Output: 10 -> 20 -> 30 -> (HEAD)
    display(myList);

    addHead(myList, 5);
    
    // Output: 5 -> 10 -> 20 -> 30 -> (HEAD)
    display(myList);

    deleteHead(myList);

    // Output: 10 -> 20 -> 30 -> (HEAD)
    display(myList);

    return 0;
}