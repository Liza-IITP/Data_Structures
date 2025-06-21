#include <stdio.h>
// Function to input a Sparse Matrix
int** inputSparseMatrix() {
    int rows, cols, terms;
    printf("Enter the rows, columns and non-zero terms: ");
    scanf("%d %d %d", &rows, &cols, &terms);
    
    int **array = (int **)malloc((terms + 1) * sizeof(int *));
    for (int i = 0; i <= terms; i++) {
        array[i] = (int *)malloc(3 * sizeof(int));
    }    
    // Assign values to the first row
    array[0][0] = rows;
    array[0][1] = cols;
    array[0][2] = terms;  
    // Input the non-zero elements
    for (int i = 1; i <= terms; i++) {
        printf("Enter row, column, and value for element %d: ", i);
        scanf("%d %d %d", &array[i][0], &array[i][1], &array[i][2]);
    }
    // Print the sparse matrix
    printf("\nSparse Matrix:\n");
    printf("%d %d %d\n", rows, cols, terms);
    for (int i = 1; i <= terms; i++) {
        printf("%d %d %d\n", array[i][0], array[i][1], array[i][2]);
    }
    return array;
}
// Function to Print a Sparse Matrix
void printSparseMatrix(int**matrix){
    printf("\nSparse Matrix:\n");
    printf("%d %d %d\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    for (int i = 1; i <= matrix[0][2]; i++) {
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}
// Function to add two sparse matrices
int** addSparseMatrices(int **matrix1, int **matrix2) {
    // Validate dimensions
    if (matrix1[0][0] != matrix2[0][0] || matrix1[0][1] != matrix2[0][1]) {
        printf("Error: Matrices have different dimensions, cannot add.\n");
        return NULL;
    }
    int rows = matrix1[0][0], cols = matrix1[0][1];
    int terms1 = matrix1[0][2], terms2 = matrix2[0][2];
    int **result = (int **)malloc((terms1 + terms2 + 1) * sizeof(int *));
    for (int i = 0; i <= terms1 + terms2; i++) {
        result[i] = (int *)malloc(3 * sizeof(int));
    }
    result[0][0] = rows;
    result[0][1] = cols;
    int i = 1, j = 1, k = 1; // Iterators for matrix1, matrix2, and result
    while (i <= terms1 && j <= terms2) {
        if (matrix1[i][0] < matrix2[j][0] || 
           (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            // Add matrix1[i] to result
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2];
            i++;
        } else if (matrix2[j][0] < matrix1[i][0] || 
                  (matrix2[j][0] == matrix1[i][0] && matrix2[j][1] < matrix1[i][1])) {
            // Add matrix2[j] to result
            result[k][0] = matrix2[j][0];
            result[k][1] = matrix2[j][1];
            result[k][2] = matrix2[j][2];
            j++;
        } else {
            // Same position, add the values
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2] + matrix2[j][2];
            i++;
            j++;
        }
        k++;
    }
    // Add remaining elements from matrix1
    while (i <= terms1) {
        result[k][0] = matrix1[i][0];
        result[k][1] = matrix1[i][1];
        result[k][2] = matrix1[i][2];
        i++;
        k++;
    }
    // Add remaining elements from matrix2
    while (j <= terms2) {
        result[k][0] = matrix2[j][0];
        result[k][1] = matrix2[j][1];
        result[k][2] = matrix2[j][2];
        j++;
        k++;
    }
    // Set the number of terms in the result matrix
    result[0][2] = k - 1;

    return result;
}
int main() {
    // Your code goes here
    printf("Input Sparse Matrix 1:\n");
    int** array_1 = inputSparseMatrix();
    printf("\nInput Sparse Matrix 2:\n");
    int** array_2 = inputSparseMatrix();

    printf("\nSparse Matrix 1:\n");
    printSparseMatrix(array_1);

    printf("\nSparse Matrix 2:\n");
    printSparseMatrix(array_2);

    int** result = addSparseMatrices(array_1, array_2);
    printf("\nResultant Sparse Matrix:\n");
    printSparseMatrix(result);
    return 0;
}