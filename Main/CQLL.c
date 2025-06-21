#include <stdio.h>
#include <stdlib.h>

// Structure for a circular queue node
struct Node {
    int data;
    struct Node* next;
};

// Structure for the circular queue
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new circular queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->rear->next = q->front; // Circular link
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
    q->rear->next = q->front; // Maintain circular link
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    struct Node* temp = q->front;
    int data = temp->data;
    
    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular link
    }
    
    free(temp);
    return data;
}

// Function to display the queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = q->front;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("(back to front)\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    
    return 0;
}
