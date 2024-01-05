#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bus
struct Bus {
    int busNumber;
    char destination[50];
    char departureTime[10];
    float fare;
};

// Define a structure for a node in the linked list
struct Node {
    struct Bus bus;
    struct Node* next;
};

// Define a structure for the bus priority queue
struct BusPriorityQueue {
    struct Node* front;
};

// Function prototypes
void initializeBusPriorityQueue(struct BusPriorityQueue* busQueue);
void enqueueBus(struct BusPriorityQueue* busQueue, struct Bus bus);
struct Bus dequeueBus(struct BusPriorityQueue* busQueue);
void displayBusPriorityQueue(struct BusPriorityQueue* busQueue);

int compareFares(float fare1, float fare2);

int main() {
    struct BusPriorityQueue busQueue;
    initializeBusPriorityQueue(&busQueue);

    int choice;
    struct Bus newBus;

    do {
        // Display menu
        printf("\nBus Transport Management System - Priority Queue based on Fare\n");
        printf("1. Enqueue Bus\n");
        printf("2. Dequeue Bus\n");
        printf("3. Display Bus Priority Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Bus Number: ");
                scanf("%d", &newBus.busNumber);
                printf("Enter Destination: ");
                scanf("%s", newBus.destination);
                printf("Enter Departure Time (HH:MM): ");
                scanf("%s", newBus.departureTime);
                printf("Enter Fare: ");
                scanf("%f", &newBus.fare);
                enqueueBus(&busQueue, newBus);
                break;

            case 2:
                newBus = dequeueBus(&busQueue);
                if (newBus.busNumber != -1) {
                    printf("Dequeued Bus Number: %d\n", newBus.busNumber);
                    printf("Destination: %s\n", newBus.destination);
                    printf("Departure Time: %s\n", newBus.departureTime);
                    printf("Fare: %.2f\n", newBus.fare);
                }
                break;

            case 3:
                displayBusPriorityQueue(&busQueue);
                break;

            case 4:
                printf("Exiting Bus Transport Management System. Have a great day!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the bus priority queue
void initializeBusPriorityQueue(struct BusPriorityQueue* busQueue) {
    busQueue->front = NULL;
}

// Function to enqueue a bus into the bus priority queue based on fare
void enqueueBus(struct BusPriorityQueue* busQueue, struct Bus bus) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Unable to enqueue bus.\n");
        return;
    }

    // Set the bus details and next pointer
    newNode->bus = bus;
    newNode->next = NULL;

    // Check if the bus priority queue is empty or the new bus has a lower fare
    if (busQueue->front == NULL || compareFares(newNode->bus.fare, busQueue->front->bus.fare) < 0) {
        newNode->next = busQueue->front;
        busQueue->front = newNode;
    } else {
        // Find the appropriate position to insert the new bus in the priority queue
        struct Node* current = busQueue->front;
        while (current->next != NULL &&
               compareFares(newNode->bus.fare, current->next->bus.fare) >= 0) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Bus %d enqueued successfully.\n", bus.busNumber);
}

// Function to dequeue a bus from the bus priority queue
struct Bus dequeueBus(struct BusPriorityQueue* busQueue) {
    struct Bus emptyBus = {-1, "", "", 0.0}; // Represents an empty/bus not found scenario

    // Check if the bus priority queue is empty
    if (busQueue->front == NULL) {
        printf("Bus priority queue is empty. Unable to dequeue.\n");
        return emptyBus;
    }

    // Get the bus details from the front node
    struct Bus dequeuedBus = busQueue->front->bus;

    // Move the front pointer to the next node
    struct Node* temp = busQueue->front;
    busQueue->front = busQueue->front->next;

    // Free the memory of the dequeued node
    free(temp);

    return dequeuedBus;
}

// Function to display the buses in the bus priority queue
void displayBusPriorityQueue(struct BusPriorityQueue* busQueue) {
    // Check if the bus priority queue is empty
    if (busQueue->front == NULL) {
        printf("Bus priority queue is empty.\n");
        return;
    }

    printf("Bus Priority Queue:\n");
    struct Node* current = busQueue->front;
    while (current != NULL) {
        printf("Bus Number: %d\n", current->bus.busNumber);
        printf("Destination: %s\n", current->bus.destination);
        printf("Departure Time: %s\n", current->bus.departureTime);
        printf("Fare: %.2f\n", current->bus.fare);
        printf("\n");
        current = current->next;
    }
}

// Function to compare two fare values
int compareFares(float fare1, float fare2) {
    if (fare1 < fare2) {
        return -1;
    } else if (fare1 > fare2) {
        return 1;
    } else {
        return 0;
    }
}

