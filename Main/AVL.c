#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    int height ;
    struct Node*left ;
    struct Node* right ;
};

int get_height(struct Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node*createNode(int key){
    struct Node*node = malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
};

int getbalancefactor(struct Node* node){
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->right;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));
    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));
    return x;

}   

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->left;
    struct Node* T2 = y->right;
    y->right = x;
    x->left = T2;
    y->height = 1 + (get_height(y->left) > get_height(y->right) ? get_height(y->left) : get_height(y->right));
    x->height = 1 + (get_height(x->left) > get_height(x->right) ? get_height(x->left) : get_height(x->right));
    return y;
}

struct Node* insert(struct Node* node, int key){
    if (node == NULL)
        return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + (get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right));
    int balance = getbalancefactor(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
        root->height = 1 + (get_height(root->left) > get_height(root->right)? get_height(root->left) : get_height(root->right));
    int balance = getbalancefactor(root);
    if (balance > 1 && getbalancefactor(root->left) >= 0)
        return rightRotate(root);
        if(balance>1 && getbalancefactor(root->left)<0){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && getbalancefactor(root->right)<=0)
            return leftRotate(root);    
        if(balance<-1 && getbalancefactor(root->right)>0){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        
            }
    return root;

}






int main() {
    return 0;
}
