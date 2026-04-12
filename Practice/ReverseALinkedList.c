//not done yet
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct ll{
    node* head;
    node* tail;
}ll;
 void init(ll* adi){
    adi->head=NULL;
    adi->tail=NULL;
 }

node* create(int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}

void insert(ll* ll,int val){
    node* newnode=create(val);
    if(ll->head==NULL){
        ll->head=newnode;
        ll->tail=newnode;
    }
    else{
    ll->tail->next=newnode;
    ll->tail=newnode;}
}
void rev(ll* adi){
    node* p1=NULL;
    node* p2=adi->head;
    node* p3=adi->head->next;
    while(p2!=NULL&&p3!=NULL){
        p2->next=p1;
        p2->next=p3;
        p1=p3;
        p2=p1->next;
        p2=p3->next;
        if(p2!=NULL){
            p3=p2->next;
        }
    }
    adi->tail=adi->head;
    if(p3==NULL){
        p2->next=p1;
        adi->head=p2;
    }
    else{
        adi->head=p1;
    }
    
    
    
}
void printll(ll* ll){
    node* temp=ll->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void freell(ll* list){
    node* temp=list->head;
    while(temp!=NULL){
        node* f=temp;
        temp=temp->next;
        free(f);
    }
    list->head=NULL;
    list->tail=NULL;
}
int main(){
    ll adi;
    init(&adi);
    int a;
    int n;
    do{
         printf("Enter 1 to insert in Linked List\n");
         printf("Enter 2 to reverse Linked List\n");
         printf("Enter 3 to print the Linked List\n");
         printf("Enter -1 to exit from Linked List\n");
         printf("Enter your option : ");
         scanf("%d",&a);
         if(a==1){
            printf("Enter the value of the node(-1 to exit) : ");
            scanf("%d",&n);
            while(n!=-1){
            insert(&adi,n);
            printf("Enter the value of the node(-1 to exit) : ");
            scanf("%d",&n);
             }
            }
        else if(a==3){
            printll(&adi);
        }
        else if(a==2){
            rev(&adi);
        }
        else if(a!=-1){
            printf("enter a valid option\n");
        }
}
    while(a!=-1);
    freell(&adi);
    return 0;
}