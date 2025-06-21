#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} stack;

void push(stack **head, int data) {
    stack *newNode = (stack*)malloc(sizeof(stack));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(stack *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int pop(stack **head) {
    if (!*head) return -1;
    int popped = (*head)->data;
    stack *temp = *head;
    *head = (*head)->next;
    free(temp);
    return popped;
}

int evaluatePostfix(char *postfix) {
    stack* stack = NULL;  // Initialize empty stack

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
                case '^': push(&stack, pow(B, A)); break;
                default: printf("Invalid %c\n", ch);
            }
        }
        i++;
    }

    return pop(&stack);  // Final result at top of stack
}

int main() {
    char postfix[] = "9852^*+";  // Example postfix expression

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}