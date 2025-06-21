#include <stdio.h>
typedef struct polynomials{
    int power;
    int coefficient;
    struct polynomials* next;
}terms;
struct polynomials* create(int coeff,int pow){
    terms*head = (terms*)malloc(sizeof(terms));
    head->coefficient = coeff;
    head->power = pow;
    head->next = NULL;
    return head;
}
void insertSorted(struct polynomials** head, int coeff, int power) {
    struct polynomials* newterms = create(coeff, power);
    if (*head == NULL || power < (*head)->power) {
        newterms->next = *head;
        *head = newterms;
        return;
    }
    struct polynomials* current = *head;
    while (current->next != NULL && current->next->power < power) {
        current = current->next;
    }
    if (current->power == power) {
        current->coefficient += coeff;
    } else if (current->next != NULL && current->next->power == power) {
        current->next->coefficient += coeff;
    } else {
        newterms->next = current->next;
        current->next = newterms;
    }
}
 
struct polynomials* input(){
    struct terms* head = NULL;
    int coeff, power;
    printf("Enter polynomial terms (coeff power). Enter '0 0' to stop:\n");
    while (1) {
        printf("Enter coefficient and power: ");
        scanf("%d %d", &coeff, &power);
        if (coeff == 0 && power == 0) {
            break;
        }
        insertSorted(&head, coeff, power);
    }
    return head;
}
void derivative(struct polynomials* head) {
    struct polynomials* current = head;
    while (current != NULL) {
        if (current->power > 0) {
            current->coefficient = current->coefficient * current->power;
            current->power = current->power - 1; 
        } else {
            current->coefficient = 0;
            current->power = -1;
        }
        current = current->next;
    }
}


void printPolynomial(struct polynomials* head) {
    struct polynomials* temp = head;
    while (temp != NULL) {
        printf("%d x^%d", temp->coefficient, temp->power);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
struct polynomials* reverseList(struct polynomials* head) {
    struct polynomials* prev = NULL;
    struct polynomials* current = head;
    struct polynomials* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev; 
        prev = current;       
        current = next;       
    }

    return prev;
}

int main() {
    struct polynomials* polynomial = input();

    printf("Polynomial in sorted order: ");
    printPolynomial(polynomial);
    printf("Reversed polynomial: ");
    polynomial = reverseList(polynomial);
    printPolynomial(polynomial);
    derivative(polynomial);
    printf("Derivative of the polynomial: ");
    printPolynomial(polynomial);
    polynomial = reverseList(polynomial);
    printf("Reversed polynomial: ");
    printPolynomial(polynomial);
    return 0;
}