#include <stdio.h>

int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 9, 12, 15, 19, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("%d found at index %d.\n", key, result);
    else
        printf("%d not found.\n", key);

    return 0;
}
