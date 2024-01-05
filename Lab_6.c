#include <stdio.h>
#include <stdlib.h>

// Structure to represent transport data
struct Transport {
    int id;
    int routeNumber;
};

// Function prototypes
void quickSort(struct Transport arr[], int low, int high, int *compCount, int *swapCount);
int partition(struct Transport arr[], int low, int high, int *compCount, int *swapCount);
void selectionSort(struct Transport arr[], int n, int *compCount, int *swapCount);
void generateRandomData(struct Transport arr[], int size);
void printData(struct Transport arr[], int size);
void readFile(struct Transport arr[], int *size);
void writeFile(struct Transport arr[], int size, char *filename);

int main() {
    int size = 10; // Initial size for random data
    char filename[] = "transport_data.txt";

    // Generate random data
    printf("Generating Random Data...\n");
    struct Transport arr[size];
    generateRandomData(arr, size);

    // Display unsorted data
    printf("Unsorted Data:\n");
    printData(arr, size);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Quick Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int compCount = 0;
        int swapCount = 0;

        switch (choice) {
            case 1:
                quickSort(arr, 0, size - 1, &compCount, &swapCount);
                printf("Quick Sort Results:\n");
                break;
            case 2:
                selectionSort(arr, size, &compCount, &swapCount);
                printf("Selection Sort Results:\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Display sorted data
        printf("Sorted Data:\n");
        printData(arr, size);

        printf("Comparisons: %d\n", compCount);
        printf("Data Transfers: %d\n", swapCount);

        // Write sorted data back to the file
        writeFile(arr, size, filename);

    } while (choice != 3);

    return 0;
}

void quickSort(struct Transport arr[], int low, int high, int *compCount, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, compCount, swapCount);

        quickSort(arr, low, pi - 1, compCount, swapCount);
        quickSort(arr, pi + 1, high, compCount, swapCount);
    }
}

int partition(struct Transport arr[], int low, int high, int *compCount, int *swapCount) {
    struct Transport pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*compCount)++;
        if (arr[j].id <= pivot.id) {
            i++;
            // Swap arr[i] and arr[j]
            struct Transport temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swapCount)++;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    struct Transport temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swapCount)++;

    return i + 1;
}

void generateRandomData(struct Transport arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].id = rand() % 1000 + 1;  // Random ID between 1 and 1000
        arr[i].routeNumber = rand() % 100;  // Random route number between 0 and 99
    }
}

void printData(struct Transport arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Route Number: %d\n", arr[i].id, arr[i].routeNumber);
    }
}

void selectionSort(struct Transport arr[], int n, int *compCount, int *swapCount) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*compCount)++;
            if (arr[j].id < arr[min_idx].id) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        struct Transport temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        (*swapCount)++;
    }
}


void readFile(struct Transport arr[], int *size) {
     FILE *file = fopen("transport_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the size of the array
    fscanf(file, "%d", size);

    // Read data into the array
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d %d", &arr[i].id, &arr[i].routeNumber);
    }

    fclose(file);
}

void writeFile(struct Transport arr[], int size, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the size of the array
    fprintf(file, "%d\n", size);

    // Write data from the array to the file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %d\n", arr[i].id, arr[i].routeNumber);
    }

    fclose(file);
}
