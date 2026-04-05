#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct graph{
    int vertx;
    struct node** arr;
}graph;

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
    printg(graphh);


    printf("successfull!!");
}