#include <stdio.h>
#include <stdlib.h>

typedef struct terms {
    int coefficient;
    int exponent;
    struct terms* next;
} poly;

poly* inputPolynomials() {
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    poly* head = NULL;
    poly* temp = NULL;

    for (int i = 0; i < n; i++) {
        poly* newnode = (poly*) malloc(sizeof(poly));
        printf("Enter the coefficient and exponent of the term %d: ", i + 1);
        scanf("%d %d", &newnode->coefficient, &newnode->exponent);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

poly* addPolynomials(poly* poly1, poly* poly2) {
    poly* result = NULL;
    poly* temp = NULL;
    poly* ptr1 = poly1;
    poly* ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL) {
        poly* newnode = (poly*) malloc(sizeof(poly));
        newnode->next = NULL;

        if (ptr1->exponent == ptr2->exponent) {
            newnode->coefficient = ptr1->coefficient + ptr2->coefficient;
            newnode->exponent = ptr1->exponent;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->exponent > ptr2->exponent) {
            newnode->coefficient = ptr1->coefficient;
            newnode->exponent = ptr1->exponent;
            ptr1 = ptr1->next;
        } else {
            newnode->coefficient = ptr2->coefficient;
            newnode->exponent = ptr2->exponent;
            ptr2 = ptr2->next;
        }

        if (result == NULL) {
            result = newnode;
            temp = result;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    while (ptr1 != NULL) {
        poly* newnode = (poly*) malloc(sizeof(poly));
        newnode->coefficient = ptr1->coefficient;
        newnode->exponent = ptr1->exponent;
        newnode->next = NULL;
        
        if (result == NULL) {
            result = newnode;
            temp = result;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        poly* newnode = (poly*) malloc(sizeof(poly));
        newnode->coefficient = ptr2->coefficient;
        newnode->exponent = ptr2->exponent;
        newnode->next = NULL;
        
        if (result == NULL) {
            result = newnode;
            temp = result;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        ptr2 = ptr2->next;
    }

    return result;
}

void displayPolynomials(poly* head) {
    if (head == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    poly* polynomial1 = inputPolynomials();
    printf("Your Polynomial:\n");
    displayPolynomials(polynomial1);
    
    poly* polynomial2 = inputPolynomials();
    printf("Your Polynomial:\n");
    displayPolynomials(polynomial2);
    
    poly* result = addPolynomials(polynomial1, polynomial2);
    printf("Resultant Polynomial:\n");
    displayPolynomials(result);

    return 0;
}
