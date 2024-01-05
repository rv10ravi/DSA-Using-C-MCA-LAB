#include <stdio.h>
#include <stdlib.h>

// Define a structure for a bus
struct Bus {
    int busNumber;
    char destination[50];
    char departureTime[10];
};

// Define a structure for a node in the linked list
struct Node {
    struct Bus bus;
    struct Node* next;
};

// Define a structure for the bus queue
struct BusQueue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeBusQueue(struct BusQueue* busQueue);
void enqueueBus(struct BusQueue* busQueue, struct Bus bus);
struct Bus dequeueBus(struct BusQueue* busQueue);
void displayBusQueue(struct BusQueue* busQueue);

int main() {
    struct BusQueue busQueue;
    initializeBusQueue(&busQueue);

    int choice;
    struct Bus newBus;

    do {
        // Display menu
        printf("\nBus Transport Management System\n");
        printf("1. Enqueue Bus\n");
        printf("2. Dequeue Bus\n");
        printf("3. Display Bus Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Bus Number: ");
                scanf("%d", &newBus.busNumber);
                printf("Enter Destination: ");
                scanf("%s", newBus.destination);
                printf("Enter Departure Time: ");
                scanf("%s", newBus.departureTime);
                enqueueBus(&busQueue, newBus);
                break;

            case 2:
                newBus = dequeueBus(&busQueue);
                if (newBus.busNumber != -1) {
                    printf("Dequeued Bus Number: %d\n", newBus.busNumber);
                    printf("Destination: %s\n", newBus.destination);
                    printf("Departure Time: %s\n", newBus.departureTime);
                }
                break;

            case 3:
                displayBusQueue(&busQueue);
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

// Function to initialize the bus queue
void initializeBusQueue(struct BusQueue* busQueue) {
    busQueue->front = NULL;
    busQueue->rear = NULL;
}

// Function to enqueue a bus into the bus queue
void enqueueBus(struct BusQueue* busQueue, struct Bus bus) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Unable to enqueue bus.\n");
        return;
    }

    // Set the bus details and next pointer
    newNode->bus = bus;
    newNode->next = NULL;

    // Check if the bus queue is empty
    if (busQueue->rear == NULL) {
        busQueue->front = newNode;
        busQueue->rear = newNode;
    } else {
        // Update the next pointer of the current rear to the new node
        busQueue->rear->next = newNode;
        // Update the rear pointer to the new node
        busQueue->rear = newNode;
    }

    printf("Bus %d enqueued successfully.\n", bus.busNumber);
}

// Function to dequeue a bus from the bus queue
struct Bus dequeueBus(struct BusQueue* busQueue) {
    struct Bus emptyBus = {-1, "", ""}; // Represents an empty/bus not found scenario

    // Check if the bus queue is empty
    if (busQueue->front == NULL) {
        printf("Bus queue is empty. Unable to dequeue.\n");
        return emptyBus;
    }

    // Get the bus details from the front node
    struct Bus dequeuedBus = busQueue->front->bus;

    // Move the front pointer to the next node
    struct Node* temp = busQueue->front;
    busQueue->front = busQueue->front->next;

    // If the bus queue becomes empty, update the rear pointer to NULL
    if (busQueue->front == NULL) {
        busQueue->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);

    return dequeuedBus;
}

// Function to display the buses in the bus queue
void displayBusQueue(struct BusQueue* busQueue) {
    // Check if the bus queue is empty
    if (busQueue->front == NULL) {
        printf("Bus queue is empty.\n");
        return;
    }

    printf("Bus Queue:\n");
    struct Node* current = busQueue->front;
    while (current != NULL) {
        printf("Bus Number: %d\n", current->bus.busNumber);
        printf("Destination: %s\n", current->bus.destination);
        printf("Departure Time: %s\n", current->bus.departureTime);
        printf("\n");
        current = current->next;
    }
}

