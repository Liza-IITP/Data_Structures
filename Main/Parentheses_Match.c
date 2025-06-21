#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100 // Stack Size

typedef struct Stack {
    int top;
    char data[MAX];
} stack;

// Function to initialize the stack 
void initstack(stack* stack) {
    stack->top = -1;
}

// Check if empty 
bool isEmpty(stack* stack) {
    return (stack->top == -1);
}

// Push 
void push(stack* stack, char c) {
    if (stack->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++(stack->top)] = c;
}

// Pop 
char pop(stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character if stack is empty
    }
    return stack->data[(stack->top)--];
}

// Function to check balance or not 
bool isBalanced(char expression[]) {
    stack st;
    initstack(&st);  // FIXED: Use local stack variable

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (ch == '{' || ch == '[' || ch == '(') {
            push(&st, ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            char top = pop(&st);
            if ((ch == '}' && top != '{') ||
                (ch == ']' && top != '[') ||
                (ch == ')' && top != '(')) {
                return false; // Mismatched brackets
            }
        }
    }

    return isEmpty(&st); // If stack is empty, expression is balanced
}

int main() {
    char expr[] = "{a,(b+f[4])*3,d+f[5]}";

    if (isBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }

    char exp2[] = "{[(])}";
    if (isBalanced(exp2)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }

    char input[MAX];
    printf("Enter an expression: ");
    scanf("%s", input);

    
    if (isBalanced(input)) {
        printf("Balanced\n");
    } else {
        printf("Unbalanced\n");
    }
    return 0;
}
