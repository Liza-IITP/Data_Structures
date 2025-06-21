#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 256

typedef struct Node {
    char character;
    unsigned frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node** array;
} MinHeap;

Node* newNode(char character, unsigned frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node**)malloc(capacity * sizeof(Node*));
    return heap;
}

void swapNodes(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&heap->array[idx], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

Node* extractMin(MinHeap* heap) {
    Node* node = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return node;
}

void insertMinHeap(MinHeap* heap, Node* node) {
    heap->size++;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(MinHeap* heap) {
    for (int i = (heap->size - 1) / 2; i >= 0; i--)
        minHeapify(heap, i);
}

MinHeap* createAndBuildHeap(char data[], int freq[], int size) {
    MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; i++)
        heap->array[i] = newNode(data[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeap* heap = createAndBuildHeap(data, freq, size);
    while (heap->size > 1) {
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* internal = newNode('$', left->frequency + right->frequency);
        internal->left = left;
        internal->right = right;
        insertMinHeap(heap, internal);
    }
    return extractMin(heap);
}

void generateCodes(Node* root, char* code, int depth, char** codes) {
    if (!root) return;
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        codes[(unsigned char)root->character] = strdup(code);
        return;
    }
    code[depth] = '0';
    generateCodes(root->left, code, depth + 1, codes);
    code[depth] = '1';
    generateCodes(root->right, code, depth + 1, codes);
}

char** getHuffmanCodes(Node* root) {
    char** codes = (char**)calloc(ASCII_SIZE, sizeof(char*));
    char code[ASCII_SIZE];
    generateCodes(root, code, 0, codes);
    return codes;
}

char* encode(char* text, char** codes) {
    int len = strlen(text);
    int totalBits = 0;
    for (int i = 0; i < len; i++)
        totalBits += strlen(codes[(unsigned char)text[i]]);
    char* encoded = (char*)malloc(totalBits + 1);
    encoded[0] = '\0';
    for (int i = 0; i < len; i++)
        strcat(encoded, codes[(unsigned char)text[i]]);
    return encoded;
}

char* decode(char* encoded, Node* root) {
    char* decoded = (char*)malloc(strlen(encoded) + 1);
    int idx = 0;
    Node* current = root;
    for (int i = 0; encoded[i]; i++) {
        current = (encoded[i] == '0') ? current->left : current->right;
        if (current->left == NULL && current->right == NULL) {
            decoded[idx++] = current->character;
            current = root;
        }
    }
    decoded[idx] = '\0';
    return decoded;
}

void countFrequencies(char* text, int* freq) {
    for (int i = 0; text[i]; i++)
        freq[(unsigned char)text[i]]++;
}

int main() {
    char text[] = "iit patna is situated in bihta";
    int freq[ASCII_SIZE] = {0};
    countFrequencies(text, freq);

    char data[ASCII_SIZE];
    int freqData[ASCII_SIZE];
    int size = 0;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freq[i]) {
            data[size] = (char)i;
            freqData[size] = freq[i];
            size++;
        }
    }

    Node* root = buildHuffmanTree(data, freqData, size);
    char** codes = getHuffmanCodes(root);

    char* encoded = encode(text, codes);
    char* decoded = decode(encoded, root);

    printf("Original: %s\n", text);
    printf("Encoded: %s\n", encoded);
    printf("Decoded: %s\n", decoded);

    // Free memory (simplified for example)
    free(encoded);
    free(decoded);
    for (int i = 0; i < ASCII_SIZE; i++)
        if (codes[i]) free(codes[i]);
    free(codes);
    return 0;
}