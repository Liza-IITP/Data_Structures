#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of each subarray of size k using a deque
void slidingWindowMax(int arr[], int n, int k) {
    int deque[n];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        if (front <= rear && deque[front] <= i - k)
            front++;
        while (front <= rear && arr[deque[rear]] <= arr[i])
            rear--;
        deque[++rear] = i;
        if (i >= k - 1)
            printf("%d ", arr[deque[front]]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    slidingWindowMax(arr, n, k);
    return 0;
}
