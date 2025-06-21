// priority_queue.c
#include <stdio.h>
#include <stdlib.h>

// Huffman Tree Node
typedef struct TreeNode {
    char ch;
    int freq;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Priority Queue Node
typedef struct Node {
    TreeNode* treeNode;
    int priority;
    struct Node* next;
} Node;

// Create a new Huffman tree node
TreeNode* createTreeNode(char ch, int freq) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create a new priority queue node
Node* newNode(TreeNode* treeNode, int priority) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->treeNode = treeNode;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Return the tree node with highest priority
TreeNode* peek(Node* head) {
    return head->treeNode;
}

// Remove the node with the highest priority
Node* pop(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Push using YOUR VERSION
Node* push(Node* head, TreeNode* treeNode, int priority) {
    Node* start = head;
    Node* temp = newNode(treeNode, priority);

    // Insert at head if priority is higher (smaller number)
    if (head == NULL || head->priority > priority) {
        temp->next = head;
        head = temp;
    } else {
        while (start->next != NULL && start->next->priority < priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }

    return head;
}

// Check if queue is empty
int isEmpty(Node* head) {
    return (head == NULL);
}