#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack {
    int top;
    int capacity;
    char* array;
} st;

st* createStack(int capacity) {
    st* stack = (st*)malloc(sizeof(st));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(st* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(st* stack) {
    return stack->top == -1;
}

void push(st* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = value;
}

char pop(st* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

char peek(st* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->array[stack->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
}

char* reversepolish(char* infix) {
    int length = strlen(infix);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int j = 0;
    st* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Remove '(' from stack
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    char* infix = "a+b*(c^d-e)^(f+g*h)-i";
    char* postfix = reversepolish(infix);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
    return 0;
}