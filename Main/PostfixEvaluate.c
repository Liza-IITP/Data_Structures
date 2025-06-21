#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of stack

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;  // Insert value and increment top
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;  // Error case
    }
    return s->arr[(s->top)--];  // Return top value and decrement top
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    Stack stack;
    stack.top = -1;  // Initialize empty stack

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If character is an operand (digit), push it to stack
        if (isdigit(ch)) {
            push(&stack, ch - '0'); 
        }
        // If character is an operator, perform calculation
        else {
            int A = pop(&stack);
            int B = pop(&stack);

            switch (ch) {
                case '+': push(&stack, B + A); break;
                case '-': push(&stack, B - A); break;
                case '*': push(&stack, B * A); break;
                case '/': push(&stack, B / A); break;
                case '^': push(&stack, pow(B,A)); break;
                default: printf("Invalid %c\n", ch);
            }
        }
        i++;
    }

    return pop(&stack);  // Final result at top of stack
}

// Main function to test the evaluation
int main() {
    char postfix[] = "9852^*+";  // Example postfix expression

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}