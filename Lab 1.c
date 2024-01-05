#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROUTES 50
#define MAX_ROUTE_NAME 50

// Structure to store route information
struct Route {
    int routeID;
    char routeName[MAX_ROUTE_NAME];
    char startLocation[50];
    char endLocation[50];
    float distance;
    int totalStops;
    int frequency;
    int passengerCapacity;
};

// Function to insert a new route into the array
int insertRoute(struct Route routes[MAX_ROUTES], int count, struct Route newRoute) {
    if (count < MAX_ROUTES) {
        routes[count] = newRoute;
        return count + 1;
    } else {
        printf("Cannot insert, maximum route limit reached.\n");
        return count;
    }
}

// Function to delete a route by ID
int deleteRoute(struct Route routes[MAX_ROUTES], int count, int routeID) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (routes[i].routeID == routeID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            routes[i] = routes[i + 1];
        }
        return count - 1;
    } else {
        printf("Route ID not found. Deletion failed.\n");
        return count;
    }
}

// Function to perform linear search by route name
void searchRouteByName(struct Route routes[MAX_ROUTES], int count, char searchName[MAX_ROUTE_NAME]) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (strcmp(routes[i].routeName, searchName) == 0) {
            printf("Route ID: %d\n", routes[i].routeID);
            printf("Route Name: %s\n", routes[i].routeName);
            printf("Start Location: %s\n", routes[i].startLocation);
            printf("End Location: %s\n", routes[i].endLocation);
            printf("Distance: %.2f km\n", routes[i].distance);
            printf("Total Stops: %d\n", routes[i].totalStops);
            printf("Frequency: %d minutes\n", routes[i].frequency);
            printf("Passenger Capacity: %d\n", routes[i].passengerCapacity);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Route not found with the given name.\n");
    }
}

// Function to add two matrices
void matrixAddition(int matrix1[MAX_ROUTES][MAX_ROUTES], int matrix2[MAX_ROUTES][MAX_ROUTES], int result[MAX_ROUTES][MAX_ROUTES], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void matrixMultiplication(int matrix1[MAX_ROUTES][MAX_ROUTES], int rows1, int cols1, int matrix2[MAX_ROUTES][MAX_ROUTES], int rows2, int cols2, int result[MAX_ROUTES][MAX_ROUTES]) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Invalid dimensions.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    struct Route routes[MAX_ROUTES];
    int routeCount = 0;

    // Inserting sample routes
    struct Route route1 = {1, "Route A", "Start A", "End A", 10.5, 15, 30, 60};
    struct Route route2 = {2, "Route B", "Start B", "End C", 8.2, 10, 20, 40};
    struct Route route3 = {3, "Route C", "Start C", "End A", 7.2, 11, 21, 42};
   
    routeCount = insertRoute(routes, routeCount, route1);
    routeCount = insertRoute(routes, routeCount, route2);
    routeCount = insertRoute(routes, routeCount, route3);
	 printf("\nInserting.");
	 Sleep(1000);
	 printf(".");
	 Sleep(1000);
	 printf(".");
    // Displaying inserted routes
    printf("\nInserted Routes:\n");
    for (int i = 0; i < routeCount; i++) {
        printf("Route ID: %d, Name: %s\n", routes[i].routeID, routes[i].routeName);
    }


	printf("\nDeleting.");
	 Sleep(1000);
	 printf(".");
	 Sleep(1000);
	 printf(".");
    // Deleting a route
    int routeToDelete = 1; // Change route ID as needed
    routeCount = deleteRoute(routes, routeCount, routeToDelete);

    // Displaying remaining routes
    printf("\nRemaining Routes:\n");
    for (int i = 0; i < routeCount; i++) {
        printf("Route ID: %d, Name: %s\n", routes[i].routeID, routes[i].routeName);
    }
	
	
	printf("\nPerforming Linear Search.");
	 Sleep(1000);
	 printf(".");
	 Sleep(1000);
	 printf(".");
    // Performing a linear search
    char searchName[MAX_ROUTE_NAME] = "Route B"; // Change search name as needed
    printf("\nSearching for Route by Name: %s\n", searchName);
    searchRouteByName(routes, routeCount, searchName);

    //  matrices for matrix operations
    int matrix1[MAX_ROUTES][MAX_ROUTES] = {{1, 2}, {3, 4}};
    int matrix2[MAX_ROUTES][MAX_ROUTES] = {{5, 6}, {7, 8}};
    int result[MAX_ROUTES][MAX_ROUTES];

	printf("\nPerforming Matrix Addition.");
	 Sleep(1000);
	 printf(".");
	 Sleep(1000);
	 printf(".\n");
	 
    // Matrix Addition
    printf("\nMatrix Addition Result:\n");
    matrixAddition(matrix1, matrix2, result, 2, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

printf("\nPerforming Matrix Multiplication.");
	 Sleep(1000);
	 printf(".");
	 Sleep(1000);
	 printf(".");
	 
     // Matrix Multiplication
    printf("\nMatrix Multiplication Result:\n");
    int matrix3[MAX_ROUTES][MAX_ROUTES] = {{1, 2, 3}, {4, 5, 6}};
    int matrix4[MAX_ROUTES][MAX_ROUTES] = {{7, 8}, {9, 10}, {11, 12}};
    result[MAX_ROUTES][MAX_ROUTES];

    matrixMultiplication(matrix3, 2, 3, matrix4, 3, 2, result);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
