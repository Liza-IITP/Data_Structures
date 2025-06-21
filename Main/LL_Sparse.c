#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Linked List
typedef struct LinkedList{
    int row;
    int col;
    int val;
    struct LinkedList*next ;
}LL;

// Input the sparse matrix as linked list 
LL* Sparseinput(){
    int row,col,value;
    printf("Enter the number of rows, columns and non-zero elements: ");
    scanf("%d %d %d",&row,&col,&value);
    LL* sparsemat = (LL*) malloc(sizeof(LL));
    LL* head = sparsemat;
    sparsemat->row = row;
    sparsemat->col = col;
    sparsemat->val = value;
    sparsemat->next = NULL;
    for(int i =0;i<value;i++){
        LL* newnode = (LL*) malloc(sizeof(LL));
        printf("Enter the value of %d row : ",i+1);
        scanf("%d %d %d",&newnode->row,&newnode->col,&newnode->val);
        newnode->next = NULL;
        sparsemat->next = newnode;
        sparsemat = newnode;
    }
    return head;}
void displaySparseMatrix(LL* head) {
    printf("Row\tColumn\tValue\n");
    
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->val);
        head = head->next;
    }
}
LL* additionSparse(LL* sparse1, LL*sparse2){
    if (sparse1->row!= sparse2->row || sparse1->col!= sparse2->col){
        printf("The two matrices are not of the same size.\n");
        return NULL;
    }
    LL* result = (LL*) malloc(sizeof(LL));
    result->row = sparse1->row;
    result->col = sparse1->col;
    result->next = NULL;
    result->val = 0 ;
    LL* p = sparse1->next ;
    LL* q = sparse2->next;
    LL* r = result;
    while (p!= NULL && q!= NULL){
        if (p->row == q->row && p->col == q->col){
            LL* newnode = (LL*) malloc(sizeof(LL));
            newnode->row = p->row;
            newnode->col = p->col;
            newnode->val = p->val + q->val;
            r->val++;
            result->next = newnode;
            result = result->next;
            p = p->next;
            q = q->next;
        } else if (p->row < q->row || (p->row == q->row && p->col < q->col)){
            LL* newnode = (LL*) malloc(sizeof(LL));
            newnode->row = p->row;
            newnode->col = p->col;
            newnode->val = p->val ;
            r->val++;
            result->next = newnode;
            result = result->next;
            p = p->next;
        } else {
            LL* newnode = (LL*) malloc(sizeof(LL));
            newnode->row = p->row;
            newnode->col = p->col;
            newnode->val = p->val ;
            r->val++;
            result->next = newnode;
            result = result->next;
            q = q->next;
            }}
    
    while (p!= NULL){
        LL* newnode = (LL*) malloc(sizeof(LL));
            newnode->row = p->row;
            newnode->col = p->col;
            newnode->val = p->val ;
            r->val++;
            result->next = newnode;
            result = result->next;
            p = p->next;
        
    }
    while (q!= NULL){
            LL* newnode = (LL*) malloc(sizeof(LL));
            newnode->row = q->row;
            newnode->col = q->col;
            newnode->val = q->val ;
            r->val++;
            result->next = newnode;
            result = result->next;
            q = q->next;
    }
    result->next = NULL;
    return r;

}
int main() {
    // Your code goes here
    LL* sparsemat = Sparseinput();
    printf("Your Sparse Matrix:\n");
    displaySparseMatrix(sparsemat);
    LL* sparsemat2 = Sparseinput();
    printf("Your Second Sparse Matrix:\n");
    displaySparseMatrix(sparsemat2);
    LL* result = additionSparse(sparsemat, sparsemat2);
    printf("Resultant Sparse Matrix:\n");
    displaySparseMatrix(result);
    return 0;
}