#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createCircularList(int n) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = head;
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = head;
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}
int josephus(Node* head, int steps,int startPos) {
    Node* temp = head;
    for (int i = 1; i < startPos; i++) {
        temp = temp->next;
    }
    while (temp->next != temp) { 
        for (int i = 0; i < steps - 2; i++) { 
            temp = temp->next;
        }
        printf("Eliminated: %d\n", temp->next->data);
        temp->next = temp->next->next;
        temp = temp->next;
    }
    int survivor = temp->data;
    return survivor;
}

int main() {
    int members = 7, steps = 3;
    int start = 1;
    Node* head = createCircularList(members);
    int survivor = josephus(head, steps,start);
    printf("Survivor: %d\n", survivor);
    return 0;
}
