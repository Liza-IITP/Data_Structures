#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef struct CircularQueue {
    int front, rear;
    int items[MAX];
} CircularQueue;

void enqueue(CircularQueue* q, int item) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = item;
        if (q->front == -1) {
            q->front = 0;

        }
        printf("Inserted %d\n", item);
    }
    return;
}

void dequeue(CircularQueue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted %d\n", q->items[q->front]);
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
    return;
}

void display(CircularQueue* q) {
    int i;
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    } while (i!= (q->rear + 1) % MAX);
    printf("\n");
    return;
}


int main() {
    return 0;
}