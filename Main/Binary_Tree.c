#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to find the minimum node
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to check if a tree is a BST
int isBST(Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

// Function to find the depth of a tree
int depth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

// Function to find the diameter of the tree
int diameter(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = depth(root->left);
    int rightHeight = depth(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return (leftHeight + rightHeight + 1) > (leftDiameter > rightDiameter ? leftDiameter : rightDiameter) ? (leftHeight + rightHeight + 1) : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
}

// Main function to demonstrate functionalities
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Is BST: %s\n", isBST(root, -1000000, 1000000) ? "Yes" : "No");

    printf("Depth of Tree: %d\n", depth(root));
    printf("Diameter of Tree: %d\n", diameter(root));

    root = deleteNode(root, 50);
    printf("Inorder after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
