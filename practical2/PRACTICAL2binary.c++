#include <stdio.h>

int BinarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int result = BinarySearch(arr, n, key);
    
    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");
    
    return 0;
}