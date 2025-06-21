// Double LL 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node*prev;
    struct Node*next;
}DNode;

DNode* input(){
    int n ;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    DNode*head;
    DNode*tail; 
    for(int i = 0 ; i<n ;i++){
        DNode* newnode = (DNode*)malloc(sizeof(DNode));
        printf("Enter data : ");
        scanf("%d",&newnode->data);   
         
        if(i==0){
            newnode->prev = NULL;
            newnode->next = NULL;
            head = newnode;
            tail = head;         
        }
        else{
            newnode->prev = tail;
            newnode->next = NULL;
            tail->next = newnode;
            tail = newnode;
    }
}
return head;}
void printDLl(DNode*head){
    DNode*temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

DNode* inserti(int i ,int data, DNode*head){
    DNode* newnode = (DNode*)malloc(sizeof(DNode));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    int count = 0 ;
    DNode* temp = head;
    while(count<i){
        temp = temp->next;
        count++;
    }
    DNode* nextnode = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = nextnode;
    nextnode->prev = newnode;
    return head;
}

DNode* reverse(DNode*head){
    DNode* current = head;
    DNode* temp = NULL;
    while(current!= NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!= NULL){
        head = temp->prev;
    }
    return head;
}


int main(){
    DNode* head = input();
    printDLl(head);
    inserti(2,100,head);
    printDLl(head);
    head = reverse(head);
    printDLl(head);
    return 0;
}