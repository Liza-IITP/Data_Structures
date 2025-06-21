#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
// Array Based Implementation
typedef struct{
    int *data; // Array to hold integer elements
    int curr_size; // Current size of the array
    int max_size; // Maximum size of the array
} List;
// Creating a list 
List *createList(int capacity){
    List *list = (List*)malloc(sizeof(List));
    list-> data = (int*)malloc(capacity*sizeof(int));
    list-> curr_size = 0;
    list-> max_size = capacity ; 
    return list;}
// Addition of element
void adddElement(List *list,int element){
    if (list->curr_size == list->max_size){
        list->max_size+=1;
        list->data = (int*)realloc(list->data,list->max_size*sizeof(int)); 
    }
    list->data[list->curr_size] = element ;
    list->curr_size+=1;
} 
// Deletion of element
void delete(List*list , int index ){
    if (index <0 || index>=list->curr_size)
    {printf("Index out of range\n ");
    return;}
    for(int i = index ; i<list->curr_size-1;i++){
        list->data[i]= list->data[i+1];
    }
    list->curr_size--;
}
// Get an Element by index 
int getElement(List*list , int index){
    if (index <0 || index>=list->curr_size)
    {printf("Index out of range\n ");
    return -1;}
    return list->data[index];
}
// Display the list
void displayList(List *list){
    printf("List : ");
    for (int i = 0 ; i < list->curr_size ; i++){
        printf("%d ",list->data[i]);
    }
    printf("\n");
}
bool isEmpty(List *list){
    return list->curr_size == 0;
}
int size(List *list){
    return list->curr_size;
}
int ElementIndex(List *list, int element) {
    for (int i = 0; i < list->curr_size; i++) {
        if (list->data[i] == element) {
            return i;
        }
    }
    return -1;
}
int main() {
    int user_input;
    printf("Enter the size of the list : ");
    scanf("%d", &user_input);
    List *list = createList(user_input);
    for (int i = 0; i < user_input; i++) {
        int input ;
        printf("Enter element %d : ", i + 1);  // User input for elements of the list.
        scanf("%d", &input);
        adddElement(list, input);
    }
    displayList(list);
    int index;
    printf("Enter index to delete : ");  // User input for index to delete element from the list.
    scanf("%d", &index);
    delete(list, index);
    displayList(list);
    int element;
    printf("Enter index to get element : ");  // User input for index to get element from the list.
    scanf("%d", &element);
    printf("%d\n", getElement(list, element));
    printf("%d\n", size(list));
    printf("%d\n", isEmpty(list));
    int search;
    printf("Enter element to search : ");  // User input for element to search in the list.
    scanf("%d", &search);
    printf("%d\n", ElementIndex(list, search));
    free(list->data);
    free(list);

    return 0;
}