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
void init(ll* list){
    list->head=NULL;
    list->tail=NULL;
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
void printll(ll* ll){
    node* temp=ll->head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void detectloop(ll* adi){
    node* first=adi->head;
    node* second=adi->head;
    while(second!=NULL&&second->next!=NULL){
        first=first->next;
        second=second->next->next;
        if(first==second){
            printf("loop detected\n");
            return;
        }
    }
    printf("NO LOOP\n");
}
void loopmaker(ll* adi){
    adi->tail->next=adi->head;
}
void loopend(ll* adi){
    adi->tail->next=NULL;
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
         printf("Enter 2 to detect loop in Linked List\n");
         printf("Enter 3 to print the Linked List\n");
         printf("Enter 4 to make loop in the Linked List\n");
         printf("Enter 5 to destroy loop in the Linked List\n");
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
            detectloop(&adi);
        }
        else if(a==4){
            loopmaker(&adi);
        }
        else if(a==5){
            loopend(&adi);
        }
        else if(a!=-1){
            printf("enter a valid option\n");
        }
}
    while(a!=-1);
    freell(&adi);
    return 0;
}
