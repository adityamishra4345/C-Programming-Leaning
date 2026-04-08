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
void delete(ll* list,int val){
    
    if(list->head==NULL){
        printf("Empty list");
    }
    else if(list->head->data==val){
        node* del=list->head;
        list->head=list->head->next;
        free(del);
        }
    else{
        node* temp=list->head;
        while(temp->next!=NULL&&temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next==NULL){
            printf("This value doesn't exist in the list\n");
        }
        else if(temp->next->data==val){
            printf("The value is now deleted from the list\n");
            node* del=temp->next;
            temp->next=temp->next->next;
            if(temp->next==NULL){
                list->tail=temp;
            }
            free(del);
        }
        
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
         printf("Enter 2 to delete from Linked List\n");
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
            printf("Enter the value you wanna to delete : ");
            int d;
            scanf("%d",&d);
            delete(&adi,d);
        }
        else if(a!=-1){
            printf("enter a valid option\n");
        }
}
    while(a!=-1);
    freell(&adi);
    return 0;
}