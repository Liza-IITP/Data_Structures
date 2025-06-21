#include <stdio.h>
#include <stdlib.h>

typedef struct DLL{int data; struct DLL*next;struct DLL*prev;}dll;
typedef struct CLL{int data ;struct CLL* next;}cll;
typedef struct SLL{int data ;struct SLL* next;}sll;



sll* create(int data){
    sll*temp=(sll*)malloc(sizeof(sll));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

dll* createDLL(int data){
    dll*temp=(dll*)malloc(sizeof(dll));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

cll* createCLL(int data){
    cll*temp=(cll*)malloc(sizeof(cll));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void printSLL(sll*head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void printDLL(dll*head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void printCLL(cll*head){
    cll*temp=head;
    if (!head) return;
    cll* temp = head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

cll* insert(cll*head,int data){
    cll*newnode = createCLL(data);
    if (!head){
        newnode->data = data;
        newnode->next=newnode;
        return newnode;
    }
    cll*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;
}

sll* insert(sll*head,int data){
    sll*newnode = create(data);
    if (!head){
        newnode->data = data;
        newnode->next=NULL;
        return newnode;
    }
    sll*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

dll* insertDLL(dll*head,int data){
    dll*newnode = createDLL(data);
    if (!head){
        newnode->data = data;
        newnode->next=newnode->prev=NULL;
        return newnode;
    }
    dll*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;
}

