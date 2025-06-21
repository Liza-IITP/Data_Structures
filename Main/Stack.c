#include<stdio.h>
#include<stdlib.h>

struct Node{
    int row;
    int col;
    int val;
    struct Node*next;
};

struct Node* createmat(int r,int c,int v){
    struct Node*head = (struct Node*)malloc(sizeof(struct Node));
    head->row = r;
    head->col = c;
    head->val = v;
    head->next = NULL;
    struct Node*temp = head;  
    for(int i = 0 ; i<v ;i++){
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value of row %d and column %d: ",i+1,i+1);
        scanf("%d %d %d",&newnode->row,&newnode->col,&newnode->val);
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
    return head;
}

void display(struct Node*head){
    struct Node*temp = head;
    while(temp!=NULL){
        printf("(%d,%d,%d) -> ",temp->row,temp->col,temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* addmat(struct Node* mat1, struct Node* mat2){
    struct Node*temp1 = mat1;
    struct Node*temp2 = mat2;
    struct Node* result = (struct Node*)malloc(sizeof(struct Node));
    result->next = NULL;
    struct Node*temp3 = result;
    if(temp1->row != temp2->row || temp1->col != temp2->col){
        printf("Matrix addition not possible\n");
        return NULL;
    }
    else{   
        temp1 =temp1->next;
        temp2 = temp2->next; 
        while(temp1!=NULL && temp2!= NULL){
            if(temp1->row == temp2->row || temp1->col == temp2->col){
                struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->row = temp1->row;
                newnode->col = temp1->col;
                newnode->val = temp1->val + temp2->val;
                newnode->next = NULL;
                temp3->next = newnode;
                temp3 = newnode;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if(temp1->row < temp2->row || (temp1->row == temp2->row && temp1->col < temp2->col)){
                struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->row = temp1->row;
                newnode->col = temp1->col;
                newnode->val = temp1->val;
                newnode->next = NULL;
                temp3->next = newnode;
                temp3 = newnode;
                temp1 = temp1->next;
            }
            else{
                struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
                newnode->row = temp2->row;
                newnode->col = temp2->col;
                newnode->val = temp2->val;
                newnode->next = NULL;
                temp3->next = newnode;
                temp3 = newnode;
                temp2 = temp2->next;
            }


        }
    }
}
