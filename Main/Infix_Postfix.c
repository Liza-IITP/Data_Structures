#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Implementing Stack using Linked List 
typedef struct Node {
    char data;
    struct Node* next;
} st;

st* create(st** top) {
    *top = NULL;
    return *top;
}

void push(st** top, char value) {
    st* newNode = (st*)malloc(sizeof(st));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

char pop(st** top) {
    char t;
    st* temp;
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        t = (*top)->data;
        temp = *top;
        *top = (*top)->next;
        free(temp);
        return t;
    }
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
    return -1;
}

void display(st* top) {
    st* temp;
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    temp = top;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to convert infix to postfix
char* infix_postfix(char* infix) {
    st* stack = NULL;
    create(&stack);
    int length = strlen(infix);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < length; i++) {
        if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack != NULL && stack->data == '(')
                pop(&stack);
        } else {
            while (stack != NULL && stack->data != '(' && precedence(stack->data) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    return postfix;
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char* postfix = infix_postfix(infix);
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
    return 0;
}