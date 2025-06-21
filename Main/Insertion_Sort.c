#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct DLL{
    int data;
    struct DLL *next;
    struct DLL *prev;
}dll;
void insertsort1(dll*head){
    dll*temp=head;
    dll*temp1=head->next;
    while(temp1!=NULL){
        dll*temp2=temp;
        while(temp2!=temp1){
            if(temp2->data>temp1->data){
                int t=temp1->data;
                temp1->data=temp2->data;
                temp2->data=t;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
// using previous pointer

void insertsort2(dll*head){
    dll*temp1 = head;
    while(temp1!=NULL){
        dll*temp2 = temp1;
        while(temp2->prev!=NULL && temp2->data < temp2->prev->data){
            int t = temp2->data;
            temp2->data = temp2->prev->data;
            temp2->prev->data = t;
            temp2 = temp2->prev;
        }
        temp1 = temp1->next;
    }

}
// using dll swapping not data swapping
void insertionSort(dll** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    dll* current = (*head)->next;
    while (current != NULL) {
        dll* nextdll = current->next;
        dll* keydll = current;
        dll* scan = keydll->prev;
        while (scan != NULL && scan->data > keydll->data) {
            scan = scan->prev;
        }
        if (keydll->prev != scan) {
            if (keydll->prev != NULL)
                keydll->prev->next = keydll->next;
            if (keydll->next != NULL)
                keydll->next->prev = keydll->prev;
            if (scan == NULL) {
                keydll->next = *head;
                keydll->prev = NULL;
                (*head)->prev = keydll;
                *head = keydll;
            } else {
                keydll->next = scan->next;
                keydll->prev = scan;
                if (scan->next != NULL)
                    scan->next->prev = keydll;
                scan->next = keydll;
            }
        }

        current = nextdll; // Move to the next dll
    }
}



int main() {
    dll*head=NULL;
    dll*temp=NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        dll*newdll=(dll*)malloc(sizeof(dll));
        newdll->data=x;
        newdll->next=NULL;
        newdll->prev=NULL;
        if(head==NULL){
            head=newdll;
            temp=head;
        }
        else{
            temp->next=newdll;
            newdll->prev=temp;
            temp=temp->next;
        }
    }
    insertsort1(head);
    dll*temp1=head;
    printf("Sorted Linked List: ");
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
    insertsort2(head);
    temp1=head;
    printf("Sorted Linked List using previous pointer: ");
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
    insertionSort(&head);
    temp1=head;
    printf("Sorted Linked List using previous pointer: ");
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    } 

    printf("\n");
    return 0;
}