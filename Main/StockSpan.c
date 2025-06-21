#include <stdio.h>
#include <stdlib.h>

// Structure for the stack
typedef struct {
    int index;
    int price;
} StackItem;

typedef struct {
    StackItem *array;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (StackItem*)malloc(stack->capacity * sizeof(StackItem));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int index, int price) {
    stack->array[++stack->top].index = index;
    stack->array[stack->top].price = price;
}

// Function to pop an element from the stack
StackItem pop(Stack* stack) {
    return stack->array[stack->top--];
}

// Function to get the top element without popping
StackItem top(Stack* stack) {
    return stack->array[stack->top];
}

// Function to calculate stock span
void stockSpan(int prices[], int n, int spans[]) {
    Stack* stack = createStack(n);  // Create a stack

    for (int i = 0; i < n; i++) {
        while (!isEmpty(stack) && top(stack).price <= prices[i]) {
            pop(stack);
        }
        spans[i] = isEmpty(stack) ? (i + 1) : (i - top(stack).index);
        push(stack, i, prices[i]);
    }

    free(stack->array);
    free(stack);
}

int main() {
    int prices[] = {20,39,25,33,23,35};
    int n = sizeof(prices) / sizeof(prices[0]);
    int spans[n];

    stockSpan(prices, n, spans);

    printf("Stock Span: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", spans[i]);
    }

    return 0;
}
