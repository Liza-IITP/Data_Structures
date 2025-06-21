#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.c"

// Function to check if a node is a leaf
int isLeaf(TreeNode* node) {
    return !(node->left) && !(node->right);
}

// Function to build the Huffman Tree
TreeNode* buildHuffmanTree(char data[], int freq[], int size) {
    Node* head = NULL;
    
    for (int i = 0; i < size; i++) {
        head = push(head, createTreeNode(data[i], freq[i]), freq[i]);
    }
    
    while (!isEmpty(head) && head->next != NULL) {
        TreeNode* left = peek(head);
        head = pop(head);
        TreeNode* right = peek(head);
        head = pop(head);
        
        TreeNode* newNode = createTreeNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        
        head = push(head, newNode, newNode->freq);
    }
    return peek(head);
}

// Function to decode the encoded string using Huffman Tree
void decodeHuffman(TreeNode* root, const char *encodedStr) {
    TreeNode* current = root;
    while (*encodedStr) {
        if (*encodedStr == '0')
            current = current->left;
        else
            current = current->right;
        
        if (isLeaf(current)) {
            printf("%c", current->ch);
            current = root;
        }
        encodedStr++;
    }
    printf("\n");
}

int main() {
    char arr[] = {'i', 's', 'd', 'h', 'n', 'p', 'u', 'b', 'e', 'a', ' ', 't'};
    int freq[] = {6, 2, 1, 1, 2, 1, 1, 1, 1, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    char encodedStr[] = "01011101111001010111000111011110100011100001110100011011100010100100111010011111100000110011110101";
    
    TreeNode* root = buildHuffmanTree(arr, freq, size);
    
    printf("Encoded: %s\n", encodedStr);
    printf("Decoded: ");
    decodeHuffman(root, encodedStr);
    
    return 0;
}
