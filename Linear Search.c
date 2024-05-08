#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 9, 12, 15, 19, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        printf("%d found at index %d.\n", key, result);
    else
        printf("%d not found.\n", key);

    return 0;
}
