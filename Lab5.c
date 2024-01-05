#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int n, int key, int *comparisons, int *dataTransfers);
int sentinelSearch(int arr[], int n, int key, int *comparisons, int *dataTransfers);
int binarySearch(int arr[], int n, int key, int *comparisons, int *dataTransfers);
void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers);
void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers);

void printArray(int arr[], int n);

int main() {
    int n, key;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Sentinel Search\n");
        printf("3. Binary Search\n");
        printf("4. Bubble Sort\n");
        printf("5. Insertion Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Linear Search
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int linearIndex, linearComparisons, linearDataTransfers;
                linearIndex = linearSearch(arr, n, key, &linearComparisons, &linearDataTransfers);
                printf("Linear Search: Index = %d, Comparisons = %d, Data Transfers = %d\n", linearIndex, linearComparisons, linearDataTransfers);
                break;

            case 2: // Sentinel Search
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int sentinelIndex, sentinelComparisons, sentinelDataTransfers;
                sentinelIndex = sentinelSearch(arr, n, key, &sentinelComparisons, &sentinelDataTransfers);
                printf("Sentinel Search: Index = %d, Comparisons = %d, Data Transfers = %d\n", sentinelIndex, sentinelComparisons, sentinelDataTransfers);
                break;

            case 3: // Binary Search
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int binaryIndex, binaryComparisons, binaryDataTransfers;
                binaryIndex = binarySearch(arr, n, key, &binaryComparisons, &binaryDataTransfers);
                printf("Binary Search: Index = %d, Comparisons = %d, Data Transfers = %d\n", binaryIndex, binaryComparisons, binaryDataTransfers);
                break;

            case 4: // Bubble Sort
                bubbleSort(arr, n, NULL, NULL);
                printf("Array after Bubble Sort: ");
                printArray(arr, n);
                break;

            case 5: // Insertion Sort
                insertionSort(arr, n, NULL, NULL);
                printf("Array after Insertion Sort: ");
                printArray(arr, n);
                break;

            case 0: // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int key, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) {
            (*dataTransfers)++;
            return i; // Element found, return index
        }
    }
    return -1; // Element not found
}

int sentinelSearch(int arr[], int n, int key, int *comparisons, int *dataTransfers) {
    int last = arr[n - 1];
    arr[n - 1] = key; // Set the last element as the sentinel

    int i = 0;
    while (arr[i] != key) {
        (*comparisons)++;
        i++;
    }

    arr[n - 1] = last; // Restore the original last element

    if (i < n - 1) {
        (*dataTransfers)++;
        return i; // Element found, return index
    }

    return -1; // Element not found
}

int binarySearch(int arr[], int n, int key, int *comparisons, int *dataTransfers) {
    int low = 0, high = n - 1;

    while (low <= high) {
        (*comparisons)++;
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            (*dataTransfers)++;
            return mid; // Element found, return index
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comparisons != NULL) (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                if (dataTransfers != NULL) (*dataTransfers)++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            if (comparisons != NULL) (*comparisons)++;
            // Shift arr[j] to the right
            if (dataTransfers != NULL) (*dataTransfers)++;
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at its correct position
        if (dataTransfers != NULL) (*dataTransfers)++;
        arr[j + 1] = key;
    }
}

