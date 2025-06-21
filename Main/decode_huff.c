#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
struct Node{
    char data;
    unsigned freq;
    struct Node *left, *right;
};
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct Node **array;
};
struct Node *newNode(char data, unsigned freq){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
struct MinHeap *createMinHeap(unsigned capacity){
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node **)malloc(minHeap->capacity * sizeof(struct Node *));
    return minHeap;
}
void swapNode(struct Node **a,struct Node **b){
    struct Node *t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap *minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx){
        swapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(struct MinHeap *minHeap){
    return (minHeap->size == 1);
}
struct Node *extractMin(struct MinHeap *minHeap){
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(struct MinHeap *minHeap,struct Node *Node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && Node->freq < minHeap->array[(i - 1) / 2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = Node;
}
void buildMinHeap(struct MinHeap *minHeap){
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}
int isLeaf(struct Node *root){
    return !(root->left) && !(root->right);
}
void countFreq(const char *sentence, char *arr, int *freq, int *uniqueCount){
    for(int i=0;sentence[i]!='\0';i++){
        char ch=sentence[i];
        int found=0;
        for(int j=0;j<*uniqueCount;j++){
            if(arr[j]==ch){
                freq[j]++;
                found=1;
                break;
            }
        }
        if(!found){
            arr[*uniqueCount]=ch;
            freq[*uniqueCount]=1;
            (*uniqueCount)++;
        }
    }
}
void printCodes(struct Node* root, int arr[],int top){
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}
void decode(const char* encoded, struct Node* root) {
    char array[100];
    int j = 0;
    struct Node* temp = root;

    for (int i = 0; encoded[i] != '\0'; i++) {
        if (encoded[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }

        // If a leaf node is reached
        if (temp->left == NULL && temp->right == NULL) {
            array[j] = temp->data; // Store the decoded character
            j++;
            temp = root; // Reset to the root for the next character
        }
    }

    array[j] = '\0'; // Null-terminate the decoded string
    printf("Decoded string: %s\n", array);
}
struct Node* buildHuffmanTree(char data[], int freq[], int uniqueCount){
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(uniqueCount);
    for (int i = 0; i < uniqueCount; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = uniqueCount;
    buildMinHeap(minHeap);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void HuffmanCodes(char data[], int freq[], int uniqueCount){
    struct Node* root = buildHuffmanTree(data, freq, uniqueCount);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}
int main() {
    char sentence[] = "iit patna is situated in bihta";
    char arr[256];
    int freq[256];
    char encoded[] = "00001111101000010111101111011100001011000111100011011111001101100110000111110100100001101111101";
    int uniqueCount = 0;

    // Count frequencies of characters in the sentence
    countFreq(sentence, arr, freq, &uniqueCount);

    // Build Huffman codes
    HuffmanCodes(arr, freq, uniqueCount);

    // Build the Huffman tree
    struct Node* root = buildHuffmanTree(arr, freq, uniqueCount);

    // Decode the encoded string
    decode(encoded, root);
    for(int i =0;i<uniqueCount;i++){
        printf("%c %d\n",arr[i],freq[i]);
    }

    return 0;
}