#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct graph{
    int vertx;
    struct node** arr;
} graph;

node* createn(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

graph* grph(int vertices){
    graph* newgrp=(graph*)malloc(sizeof(graph));
    newgrp->vertx=vertices;
    newgrp->arr=malloc(vertices*sizeof(node*));
    for(int i=0;i<vertices;i++){
        newgrp->arr[i]=NULL;
    }
    return newgrp;
}

void edgeadd(graph* grp,int src,int dest){
    node* hook=createn(dest);
    hook->next=grp->arr[src];
    grp->arr[src]=hook;
}

void printg(graph* grp){
    for(int i=0;i<grp->vertx;i++){
        node* s=grp->arr[i];
        printf("%d->",i);
        while(s!=NULL){
            printf("%d->",s->data);
            s=s->next;
        }
        printf("NULL");
        printf("\n");
    }
}

void bfs(graph* grp, int start) {
    int* visited = (int*)malloc(grp->vertx * sizeof(int));
    for(int i = 0; i < grp->vertx; i++) {
        visited[i] = 0;
    }
    
    int* queue = (int*)malloc(grp->vertx * sizeof(int));
    int front = 0;
    int rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    while(front < rear) {
        int curnt = queue[front++];
        printf("%d ", curnt);
        
        node* temp = grp->arr[curnt];
        while(temp != NULL) {
            int adj = temp->data;
            if(visited[adj] == 0) {
                visited[adj] = 1;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
    
    
}

int main(){
    graph* graphh=grph(5);
    edgeadd(graphh,1,3);
    edgeadd(graphh,1,4);
    edgeadd(graphh,1,2);
    edgeadd(graphh,1,1);
    edgeadd(graphh,2,4);
    edgeadd(graphh,4,4);
    edgeadd(graphh,3,1);
    edgeadd(graphh,4,3);
    
    // printf("Adjacency List:\n");
    // printg(graphh);
    
    printf("\nBFS starting from vertex 1:\n");
    bfs(graphh, 1);
    printf("\n\n");
    
    printf("successfull!!\n");
    return 0;
}