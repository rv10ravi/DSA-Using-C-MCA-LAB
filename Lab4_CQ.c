#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bus departure
struct BusDeparture {
    int departureNumber;
    char destination[50];
    char departureTime[10];
    float ticketPrice;
};

// Define a structure for a node in the circular queue
struct QueueNode {
    struct BusDeparture departure;
    struct QueueNode* next;
};

// Define a structure for the bus departure circular queue
struct BusDepartureCircularQueue {
    struct QueueNode* rear;
};

// Function prototypes
void initializeBusDepartureCircularQueue(struct BusDepartureCircularQueue* queue);
void scheduleBusDeparture(struct BusDepartureCircularQueue* queue, struct BusDeparture departure);
struct BusDeparture departBus(struct BusDepartureCircularQueue* queue);
void displayBusDepartureCircularQueue(struct BusDepartureCircularQueue* queue);

int main() {
    struct BusDepartureCircularQueue departureQueue;
    initializeBusDepartureCircularQueue(&departureQueue);

    int choice;
    struct BusDeparture newDeparture;

    do {
        // Display menu
        printf("\nBus Departure Management System - Circular Queue\n");
        printf("1. Schedule Bus Departure\n");
        printf("2. Depart Bus\n");
        printf("3. Display Departures\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Departure Number: ");
                scanf("%d", &newDeparture.departureNumber);
                printf("Enter Destination: ");
                scanf("%s", newDeparture.destination);
                printf("Enter Departure Time (HH:MM): ");
                scanf("%s", newDeparture.departureTime);
                printf("Enter Ticket Price: ");
                scanf("%f", &newDeparture.ticketPrice);
                scheduleBusDeparture(&departureQueue, newDeparture);
                break;

            case 2:
                newDeparture = departBus(&departureQueue);
                if (newDeparture.departureNumber != -1) {
                    printf("Bus %d has departed to %s at %s.\n", newDeparture.departureNumber, newDeparture.destination, newDeparture.departureTime);
                    printf("Ticket Price: %.2f\n", newDeparture.ticketPrice);
                }
                break;

            case 3:
                displayBusDepartureCircularQueue(&departureQueue);
                break;

            case 4:
                printf("Exiting Bus Departure Management System. Have a great day!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the bus departure circular queue
void initializeBusDepartureCircularQueue(struct BusDepartureCircularQueue* queue) {
    queue->rear = NULL;
}

// Function to schedule a bus departure into the circular queue
void scheduleBusDeparture(struct BusDepartureCircularQueue* queue, struct BusDeparture departure) {
    // Create a new node
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation failed. Unable to schedule bus departure.\n");
        return;
    }

    // Set the bus departure details and next pointer
    newNode->departure = departure;
    newNode->next = NULL;

    // Check if the circular queue is empty
    if (queue->rear == NULL) {
        queue->rear = newNode;
        newNode->next = newNode; // Point to itself to make it circular
    } else {
        // Update the next pointer of the current rear to the new node
        newNode->next = queue->rear->next;
        queue->rear->next = newNode;
        // Update the rear pointer to the new node
        queue->rear = newNode;
    }

    printf("Departure %d scheduled successfully.\n", departure.departureNumber);
}

// Function to depart a bus from the circular queue
struct BusDeparture departBus(struct BusDepartureCircularQueue* queue) {
    struct BusDeparture emptyDeparture = {-1, "", "", 0.0}; // Represents an empty/departure not found scenario

    // Check if the circular queue is empty
    if (queue->rear == NULL) {
        printf("Bus departure circular queue is empty. Unable to depart bus.\n");
        return emptyDeparture;
    }

    // Get the bus departure details from the front node
    struct BusDeparture departedBus = queue->rear->next->departure;

    // If there's only one departure, set rear to NULL
    if (queue->rear->next == queue->rear) {
        free(queue->rear);
        queue->rear = NULL;
    } else {
        // Move the front pointer to the next node
        struct QueueNode* temp = queue->rear->next;
        queue->rear->next = temp->next;
        // Free the memory of the dequeued node
        free(temp);
    }

    return departedBus;
}

// Function to display the bus departures in the circular queue
void displayBusDepartureCircularQueue(struct BusDepartureCircularQueue* queue) {
    // Check if the circular queue is empty
    if (queue->rear == NULL) {
        printf("Bus departure circular queue is empty.\n");
        return;
    }

    printf("Bus Departures:\n");
    struct QueueNode* current = queue->rear->next;
    do {
        printf("Departure Number: %d\n", current->departure.departureNumber);
        printf("Destination: %s\n", current->departure.destination);
        printf("Departure Time: %s\n", current->departure.departureTime);
        printf("Ticket Price: %.2f\n", current->departure.ticketPrice);
        printf("\n");
        current = current->next;
    } while (current != queue->rear->next);
}

