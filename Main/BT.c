#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createBT(int val){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = val;
    root->left = root->right = NULL;
    return root;
}

Node* insert(Node* root, int val){
    if(root == NULL){
        return createBT(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left) inorder(root->left);
    printf("%d ", root->data);
    if(root->right) inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return 1 + (l > r ? l : r);
}
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}



Node* delete(Node* root, int x){
    if(root == NULL){
        return root;
    }
    if(x < root->data){
        root->left = delete(root->left, x);
    }
    else if(x > root->data){
        root->right = delete(root->right, x);
    }
    else {
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
int lowest_common_ancestor(Node* root, int n1 , int n2){
    while(root!=NULL){
        if(root->data > n1 && root->data > n2)
            root = root->left;
        else if(root->data < n1 && root->data < n2)
            root = root->right;
        else
            return root->data;
    }
    return -1;
}
int max(Node* root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;
}
int min(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}
void print_hrange_util(Node* root, int current_level, int k, int l) {
    if (root == NULL)  // Base case
        return;

    // Check if the current level is within the range [k, l]
    if (current_level >= k && current_level <= l) {
        print_hrange_util(root->left, current_level + 1, k, l);
        printf("%d ", root->data);  // Print the current node
        print_hrange_util(root->right, current_level + 1, k, l);
    } else if (current_level < k) {
        // If the current level is less than k, continue traversing
        print_hrange_util(root->left, current_level + 1, k, l);
        print_hrange_util(root->right, current_level + 1, k, l);
    }
}

void print_hrange(int k, int l, Node* root) {
    print_hrange_util(root, 0, k, l);  // Start from level 0
}


int main() {
    Node* root = createBT(25);
    insert(root, 15);
    insert(root, 50);
    insert(root, 10);
    insert(root, 22);
    insert(root, 35);
    insert(root, 70);
    insert(root, 4);
    insert(root, 12);
    insert(root, 18);
    insert(root, 31);
    insert(root, 44);
    insert(root, 66);
    insert(root, 90);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    printf("Height: %d\n", height(root));
    root = delete(root, 4);
    printf("Inorder after deletion 4: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 44);
    printf("Inorder after deletion 44: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 22);
    printf("Inorder after deletion 22: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 25);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 35);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 15);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));
    root = delete(root, 10);
    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");
    printf("Height after deletion: %d\n", height(root));

    print_hrange(0, 2, root);
    printf("\n");

    return 0;
}