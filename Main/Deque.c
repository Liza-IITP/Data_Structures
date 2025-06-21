#include <stdio.h>
#include <stdlib.h>

// Structure for a deque node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure for the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Function to insert an element at the front
void insertFront(struct Deque* dq, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = dq->front;
    
    if (dq->front == NULL) {
        dq->front = dq->rear = temp;
    } else {
        dq->front->prev = temp;
        dq->front = temp;
    }
}

// Function to insert an element at the rear
void insertRear(struct Deque* dq, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = dq->rear;
    
    if (dq->rear == NULL) {
        dq->front = dq->rear = temp;
    } else {
        dq->rear->next = temp;
        dq->rear = temp;
    }
}

// Function to delete an element from the front
int deleteFront(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    
    struct Node* temp = dq->front;
    int data = temp->data;
    dq->front = dq->front->next;
    
    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;
    
    free(temp);
    return data;
}

// Function to delete an element from the rear
int deleteRear(struct Deque* dq) {
    if (dq->rear == NULL) {
        printf("Deque is empty!\n");
        return -1;
    }
    
    struct Node* temp = dq->rear;
    int data = temp->data;
    dq->rear = dq->rear->prev;
    
    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;
    
    free(temp);
    return data;
}

// Function to display the deque
void display(struct Deque* dq) {
    if (dq->front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = dq->front;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Deque* dq = createDeque();
    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 30);
    insertRear(dq, 40);
    display(dq);
    
    printf("Deleted from front: %d\n", deleteFront(dq));
    display(dq);
    printf("Deleted from rear: %d\n", deleteRear(dq));
    display(dq);
    
    return 0;
}
