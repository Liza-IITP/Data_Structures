#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack {
    int top;
    int arr[MAX];
} stack;

// Function to initialize stack
stack* init() {
    stack *s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    return s;
}

// Function to check if stack is empty
bool isEmpty(stack *s) {
    return s->top == -1;
}

// Function to push an element onto stack
void push(stack *s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Function to pop an element from stack
int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Convert Infix to Postfix 
char* postfix(char *infix) {
    stack *s = init();
    static char post[MAX];  // Fix: Store postfix result
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            push(s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (!isEmpty(s) && s->arr[s->top] != '(') {
                post[k++] = pop(s);
            }
            pop(s); // Remove '('
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!isEmpty(s) && (s->arr[s->top] == '*' || s->arr[s->top] == '/')) {
                post[k++] = pop(s);
            }
            push(s, infix[i]);
        }
        else {
            post[k++] = infix[i];  // Operand directly added to postfix
        }
    }
    
    while (!isEmpty(s)) {
        post[k++] = pop(s);
    }

    post[k] = '\0';  // Fix: Null terminate the string
    return post;
}

// Evaluate Reverse Polish Notation (Postfix Evaluation)
int reversepolish(char *exp) {
    stack *s = init();
    
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(s, exp[i] - '0'); // Convert char to int
        } else {
            int a = pop(s);
            int b = pop(s);
            switch (exp[i]) {
                case '+': push(s, b + a); break;
                case '-': push(s, b - a); break;
                case '*': push(s, b * a); break;
                case '/': push(s, b / a); break;
            }
        }
    }
    return pop(s);
}

int main() {
    char infix[MAX];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    char *post = postfix(infix);
    printf("The postfix expression is: %s\n", post);
    printf("The result of the expression is: %d\n", reversepolish(post));

    return 0;
}
