#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// Function to create a List structure 
typedef struct{
    int *array;
    int max_size;
    int curr_size;
}List;

// Function to create a list 
List* createlist(int size){
    List* list = (List*)malloc(sizeof(list));
    list-> array = (int*)malloc(size*sizeof(int));
    list->curr_size = 0;
    list->max_size = size;
    return list;
}

// Function to add an element 
void AddElement(List *list, int element){
    if (list->curr_size == list->max_size){
        list->max_size*=2;
        list->array =( int*)realloc(list->array,list->max_size*sizeof(int));
    }
    list->array[list->curr_size] = element;
    list->curr_size++;
    
}

// Function to delete an element
void DeleteElement(List *list, int element){
    int index = -1;
    for (int i = 0; i < list->curr_size; i++) {
        if (list->array[i] == element) {
            index = i;
            break;
        }
    }
    if (index!= -1) {
        for (int i = index; i < list->curr_size - 1; i++) {
            list->array[i] = list->array[i + 1];
        }
        list->curr_size--;
    } else {
        printf("Element not found in the list.\n");
    }
}
int remove_element(List*list ,int index){
    for (int i = index; i < list->curr_size-1; i++) {
        list->array[i] = list->array[i + 1];
}
list->curr_size--;}

// Get an Element by index
int getElement(List*list, int index){
    if (index <0 || index>=list->curr_size)
    {printf("Index out of range\n ");
    return -1;}
    return list->array[index];
}

// Current size 
int getSize(List *list) {
    return list->curr_size;
}

// Is Empty 
bool isEmpty(List *list) {
    return list->curr_size == 0;
}

// Searching an element

int searchElement(List *list, int element) {
    for (int i = 0; i < list->curr_size; i++) {
        if (list->array[i] == element) {
            return i;
        }
    }
    return -1;
}

// Insert element
void insertElement(List*list,int element,int index){
    if(index < 0 || index > list->curr_size){
        printf("Invalid index\n");
        return;
    }
    if(index == list->curr_size){
        AddElement(list, element);
    }
    for(int i = list->curr_size-1 ;i>=index;i--){
        int temp = list->array[index];
        list->array[i+1] = list->array[i];
    }
    list->array[index] = element;
    list->curr_size++;

}
// Displaying Element
void display(List *list) {
    printf("List elements are : ");
    for (int i= 0 ; i< list->curr_size; i++){
        printf("%d ", list->array[i]);
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the size of the list : ");
    scanf("%d", &size);
    List *list = createlist(size);
    for (int i = 0; i < size; i++) {
        int input ;
        printf("Enter element %d : ", i + 1);  // User input for elements of the list.
        scanf("%d", &input);
        AddElement(list, input);
    }

    int elementtobeinserted ;
    printf("Enter element to be inserted : ");
    scanf("%d", &elementtobeinserted);
    int indextobeinserted ;
    printf("Enter index to insert : ");
    scanf("%d", &indextobeinserted);
    insertElement(list, elementtobeinserted, indextobeinserted);
    printf("List after insertion: ");
    display(list);

    int elementtodelete ;
    printf("Enter element to be deleted : ");
    scanf("%d", &elementtodelete);
    DeleteElement(list, elementtodelete);
    printf("List after deletion: ");
    display(list);
    
    int elementtosearch ;
    printf("Enter element to be searched : ");
    scanf("%d", &elementtosearch);
    int index = searchElement(list, elementtosearch);
    if(index!= -1){
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found in the list.\n");
    }
    
    printf("Size of the list: %d\n", getSize(list));
    bool isEmptyStatus = isEmpty(list);
    printf("Is the list empty? %s\n", (isEmptyStatus)? "Yes" : "No");


    return 0;
}