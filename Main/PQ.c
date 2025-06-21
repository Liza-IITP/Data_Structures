#include <stdio.h>
#include <stdlib.h>

// Structure for a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to enqueue an element based on priority
void enqueue(struct Node** front, int value, int priority) {
    struct Node* temp = createNode(value, priority);
    
    if (*front == NULL || priority < (*front)->priority) {
        temp->next = *front;
        *front = temp;
    } else {
        struct Node* start = *front;
        while (start->next != NULL && start->next->priority <= priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to dequeue an element
int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    free(temp);
    return data;
}

// Function to display the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = front;
    while (temp) {
        printf("[%d, priority %d] -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* pq = NULL;
    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 0);
    display(pq);
    
    printf("Dequeued: %d\n", dequeue(&pq));
    display(pq);
    
    return 0;
}