#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Structure for priority queue using array
struct PriorityQueue {
    int data[MAX];
    int priority[MAX];
    int size;
};

// Function to initialize the priority queue
void initQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

// Function to enqueue an element based on priority
void enqueue(struct PriorityQueue* pq, int value, int priority) {
    if (pq->size == MAX) {
        printf("Queue is full!\n");
        return;
    }
    
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] > priority) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    
    pq->data[i + 1] = value;
    pq->priority[i + 1] = priority;
    pq->size++;
}

// Function to dequeue an element
int dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }
    
    int value = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return value;
}

// Function to display the queue
void display(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    
    for (int i = 0; i < pq->size; i++) {
        printf("[%d, priority %d] -> ", pq->data[i], pq->priority[i]);
    }
    printf("NULL\n");
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 0);
    display(&pq);
    
    printf("Dequeued: %d\n", dequeue(&pq));
    display(&pq);
    
    return 0;
}