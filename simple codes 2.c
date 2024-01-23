// Progarm1: 2d array
// Program2: Circular LL
// Program3: Double LL
// Program4: Single ll
// Program5: Stack infix to potsfix
// Program6: Queue
// Program7: Sorting and Searching



//1.
	#include <stdio.h>
	#include<conio.h>
	#include<stdlib.h>
	
	typedef struct TaxpayerRecord { 
		int taxpayer_id; 
		float income; 
		float deductions;
	} TaxpayerRecord;
	
	
	TaxpayerRecord taxpayer_records[100];
	
	
	void insert_taxpayer_record(TaxpayerRecord taxpayer_record) { 
	for (int i = 0; i < 100; i++) {
		if (taxpayer_records[i].taxpayer_id == 0) { 
			taxpayer_records[i] = taxpayer_record; 
			break;
		}
		}
	}
	
	
	void delete_taxpayer_record(int taxpayer_id) {
		printf("Deleting taxpayer record with ID %d...\n", taxpayer_id);
	
	
		int found_index = -1;
		for (int i = 0; i < 100; i++) {
			if (taxpayer_records[i].taxpayer_id == taxpayer_id) { 
			found_index = i;
			break;	 
			}
		}	
	
		if (found_index == -1) {
			printf("Taxpayer record with ID %d not found.\n", taxpayer_id);
		} else {
			for (int j = found_index; j < 99; j++) {
				taxpayer_records[j] = taxpayer_records[j + 1];
			}
			taxpayer_records[99].taxpayer_id = 0;
			printf("Taxpayer record with ID %d deleted.\n", taxpayer_id);
		}
	}
	
	
	TaxpayerRecord* find_taxpayer_record_by_id(int taxpayer_id) { 
		for (int i = 0; i < 100; i++) {
			if (taxpayer_records[i].taxpayer_id == taxpayer_id) {
				 return &taxpayer_records[i];
			}
		}
	return NULL;
	}
	
	
	void matrixTax() {
		int matrix1[3][4];	
		for (int i = 0; i < 3; i++) {
			 for (int j = 0; j < 4; j++) {
				printf("Enter Salary of Quarter %d of client %d: ", i + 1, j + 1); scanf("%d", &matrix1[i][j]);
			}
		}
	
		printf("\n Quarterly Salary Matrix:\n "); 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 4; j++) {
				printf("%d ", matrix1[i][j]);
			}
			printf("\n");
		}
		int tax;
		printf("\nEnter the Tax Rate: "); scanf("%d",&tax);
		int total_sal[3][4];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
			total_sal[i][j] = matrix1[i][j] / tax ;
			}
		}
		printf("\nTotal Salary matrix:\n"); 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%d ", total_sal[i][j]);
			}
			printf("\n");
		}
	}
	
	
	void matrixSubtraction() {	 
		int matrix1[3][4]; 
		int matrix2[3][4];
	
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 4; j++) {
				printf("Enter Salary of quarter %d of client %d: ", i + 1, j + 1);
				scanf("%d", &matrix1[i][j]);
			}
		}
		
		printf("\n Salary Matrix\n: "); 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%d ", matrix1[i][j]);
			}
			printf("\n");
		}	
		for (int i = 0; i < 3; i++) { 
			for (int j = 0; j < 4; j++) {
				printf("Enter Deductions of quarter %d of client %d: ", i + 1, j + 1); 
				scanf("%d", &matrix2[i][j]);
			}
		}
	
		printf("\n Deductions Matrix\n: ");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
			printf("%d ", matrix2[i][j]);
			}
			printf("\n");
	 	}	
		int total_sal[3][4];
		for (int i = 0; i < 3; i++) { 
			for (int j = 0; j < 4; j++) {
				total_sal[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}	
	
		printf("Salary - Deduction matrix:\n"); 
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%d ", total_sal[i][j]);
			}
			printf("\n");
		}
	}
	
	
int main() {
	int choice;
	printf("\nMenu:\n"); 
do{
	printf("\n1. Insert a new taxpayer record.\n"); printf("2. Delete a taxpayer record.\n");
	printf("3. Find a taxpayer record by ID.\n"); printf("4. To Calculate Tax.\n");
	printf("5. To Calculate remaining Salary.\n"); printf("4. Exit.\n\n");
	printf("Enter your choice: ");
	 
	scanf("%d",&choice);
	
	
	TaxpayerRecord taxpayer_record;
	
	
	switch (choice) { 
		case 1:
			printf("Enter the taxpayer ID: ");
			scanf("%d", &taxpayer_record.taxpayer_id);	
			printf("Enter the taxpayer's income: "); 
			scanf("%f", &taxpayer_record.income);
			printf("Enter the taxpayer's deductions: "); 
			scanf("%f", &taxpayer_record.deductions);	
			insert_taxpayer_record(taxpayer_record); 
			break;
	
		case 2:
			printf("Enter the taxpayer ID to delete: ");
			scanf("%d", &taxpayer_record.taxpayer_id);
			delete_taxpayer_record(taxpayer_record.taxpayer_id);
			break;
	
		case 3:	{
			printf("Enter the taxpayer ID to find: "); 
			scanf("%d", &taxpayer_record.taxpayer_id);
			TaxpayerRecord* found_taxpayer_record = find_taxpayer_record_by_id(taxpayer_record.taxpayer_id);
			if (found_taxpayer_record != NULL) {
				printf("Taxpayer record found:\n");
				printf("Taxpayer ID: %d\n", found_taxpayer_record->taxpayer_id); 
				printf("Income: %f\n", found_taxpayer_record->income);
				printf("Deductions: %f\n", found_taxpayer_record->deductions);
			} else {
				printf("Taxpayer record not found.\n");
			}
			break;	
		}
		case 4:
			matrixTax(); 
			break;
		case 5:
			matrixSubtraction(); 
			break;
		case 6:
			printf("\nGoodbye!\n");
			exit(0);
		default:
			printf("Invalid choice.\n");
	}
}while(choice != 6);
	 
	printf("\nGoodbye!\n");
	
	return 0;
	
}

//2. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a taxpayer
struct TaxPayer {
    char name[50];
    double income;
    double taxAmount;
    struct TaxPayer* next;  // Pointer to the next node in the linked list
};

// Function to create a new taxpayer node
struct TaxPayer* createNode(char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = (struct TaxPayer*)malloc(sizeof(struct TaxPayer));
    strcpy(newNode->name, name);
    newNode->income = income;
    newNode->taxAmount = taxAmount;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a taxpayer at the end of the circular linked list
struct TaxPayer* insertAtEnd(struct TaxPayer* head, char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = createNode(name, income, taxAmount);

    if (head == NULL) {
        // If the list is empty, make the new node the head and point to itself
        head = newNode;
        newNode->next = head;
    } else {
        // Find the last node in the list
        struct TaxPayer* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Insert the new node at the end and update pointers
        last->next = newNode;
        newNode->next = head;
    }

    return head;
}

// Function to display all taxpayers in the circular linked list
void displayList(struct TaxPayer* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct TaxPayer* current = head;

    do {
        printf("Name: %s, Income: %.2f, Tax Amount: %.2f\n", current->name, current->income, current->taxAmount);
        current = current->next;
    } while (current != head);
}

// Function to search for a taxpayer by name in the circular linked list
struct TaxPayer* searchTaxPayer(struct TaxPayer* head, char* name) {
    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return NULL;
    }

    struct TaxPayer* current = head;

    do {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;  // Taxpayer not found
}

// Function to delete a taxpayer by name in the circular linked list
struct TaxPayer* deleteTaxPayer(struct TaxPayer* head, char* name) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct TaxPayer* current = head;
    struct TaxPayer* prev = NULL;

    do {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                // Deleting the first node
                if (current->next == head) {
                    // Only one node in the list
                    free(current);
                    return NULL;
                }

                struct TaxPayer* last = head;
                while (last->next != head) {
                    last = last->next;
                }

                head = head->next;
                last->next = head;
            } else {
                prev->next = current->next;
            }

            free(current);  // Free the memory
            return head;
        }

        prev = current;
        current = current->next;
    } while (current != head);

    printf("Taxpayer not found.\n");
    return head;
}

// Function to free the memory allocated for the circular linked list
void deleteList(struct TaxPayer* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct TaxPayer* current = head;
    struct TaxPayer* next;

    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != head);
}

int main() {
    struct TaxPayer* head = NULL;  // Initialize an empty circular linked list

    int choice;
    char name[50];
    double income, taxAmount;

    do {
        printf("\n Circular Linked List Menu:\n");
        printf("1. Add Taxpayer\n");
        printf("2. Display Taxpayers\n");
        printf("3. Search Taxpayer\n");
        printf("4. Delete Taxpayer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter taxpayer details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Income: ");
                scanf("%lf", &income);
                printf("Tax Amount: ");
                scanf("%lf", &taxAmount);
                head = insertAtEnd(head, name, income, taxAmount);
                break;

            case 2:
                printf("Taxpayers in the list:\n");
                displayList(head);
                break;

            case 3:{
                printf("Enter the name to search: ");
                scanf("%s", name);
                struct TaxPayer* foundTaxPayer = searchTaxPayer(head, name);
                if (foundTaxPayer != NULL) {
                    printf("Taxpayer found - Name: %s, Income: %.2f, Tax Amount: %.2f\n", foundTaxPayer->name, foundTaxPayer->income, foundTaxPayer->taxAmount);
                } else {
                    printf("Taxpayer not found.\n");
                }
                break;
            }

            case 4:
                printf("Enter the name to delete: ");
                scanf("%s", name);
                head = deleteTaxPayer(head, name);
                break;

            case 5:
                // Free the memory allocated for the circular linked list
                deleteList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

//3.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a taxpayer
struct TaxPayer {
    char name[50];
    double income;
    double taxAmount;
    struct TaxPayer* next;  // Pointer to the next node in the linked list
    struct TaxPayer* prev;  // Pointer to the previous node in the linked list
};

// Function to create a new taxpayer node
struct TaxPayer* createNode(char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = (struct TaxPayer*)malloc(sizeof(struct TaxPayer));
    strcpy(newNode->name, name);
    newNode->income = income;
    newNode->taxAmount = taxAmount;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a taxpayer at the beginning of the doubly linked list
struct TaxPayer* insertAtBeginning(struct TaxPayer* head, char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = createNode(name, income, taxAmount);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

// Function to display all taxpayers in the doubly linked list
void displayList(struct TaxPayer* head) {
    struct TaxPayer* current = head;
    while (current != NULL) {
        printf("Name: %s, Income: %.2f, Tax Amount: %.2f\n", current->name, current->income, current->taxAmount);
        current = current->next;
    }
}

// Function to search for a taxpayer by name in the doubly linked list
struct TaxPayer* searchTaxPayer(struct TaxPayer* head, char* name) {
    struct TaxPayer* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // Taxpayer not found
}

// Function to delete a taxpayer by name in the doubly linked list
struct TaxPayer* deleteTaxPayer(struct TaxPayer* head, char* name) {
    struct TaxPayer* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // Deleting the first node
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);  // Free the memory
            return head;
        }

        current = current->next;
    }

    printf("Taxpayer not found.\n");
    return head;
}

// Function to free the memory allocated for the doubly linked list
void deleteList(struct TaxPayer* head) {
    struct TaxPayer* current = head;
    struct TaxPayer* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct TaxPayer* head = NULL;  // Initialize an empty doubly linked list

    int choice;
    char name[50];
    double income, taxAmount;

    do {
        printf("\nDouble Linked List Menu:\n");
        printf("1. Add Taxpayer\n");
        printf("2. Display Taxpayers\n");
        printf("3. Search Taxpayer\n");
        printf("4. Delete Taxpayer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter taxpayer details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Income: ");
                scanf("%lf", &income);
                printf("Tax Amount: ");
                scanf("%lf", &taxAmount);
                head = insertAtBeginning(head, name, income, taxAmount);
                break;

            case 2:
                printf("Taxpayers in the list:\n");
                displayList(head);
                break;

            case 3:{
                printf("Enter the name to search: ");
                scanf("%s", name);
                struct TaxPayer* foundTaxPayer = searchTaxPayer(head, name);
                if (foundTaxPayer != NULL) {
                    printf("Taxpayer found - Name: %s, Income: %.2f, Tax Amount: %.2f\n", foundTaxPayer->name, foundTaxPayer->income, foundTaxPayer->taxAmount);
                } else {
                    printf("Taxpayer not found.\n");
                }
                break;
            }

            case 4:
                printf("Enter the name to delete: ");
                scanf("%s", name);
                head = deleteTaxPayer(head, name);
                break;

            case 5:
                // Free the memory allocated for the doubly linked list
                deleteList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

//4.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a taxpayer
struct TaxPayer {
    char name[50];
    double income;
    double taxAmount;
    struct TaxPayer* next;  // Pointer to the next node in the linked list
};

// Function to create a new taxpayer node
struct TaxPayer* createNode(char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = (struct TaxPayer*)malloc(sizeof(struct TaxPayer));
    strcpy(newNode->name, name);
    newNode->income = income;
    newNode->taxAmount = taxAmount;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a taxpayer at the beginning of the linked list
struct TaxPayer* insertAtBeginning(struct TaxPayer* head, char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = createNode(name, income, taxAmount);
    newNode->next = head;
    return newNode;
}

struct TaxPayer* addNodeAtEnd(struct TaxPayer* head, char* name, double income, double taxAmount) {
    struct TaxPayer* newNode = createNode(name, income, taxAmount);

    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to add node.\n");
        return head;
    }

    if (head == NULL) {
        // If the list is empty, make the new node the head
        head = newNode;
    } else {
        // Traverse the list to find the last node
        struct TaxPayer* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Add the new node at the end
        current->next = newNode;
    }

    return head;
}

// Function to display all taxpayers in the linked list
void displayList(struct TaxPayer* head) {
    struct TaxPayer* current = head;
    while (current != NULL) {
        printf("Name: %s, Income: %.2f, Tax Amount: %.2f\n", current->name, current->income, current->taxAmount);
        current = current->next;
    }
}

// Function to search for a taxpayer by name
struct TaxPayer* searchTaxPayer(struct TaxPayer* head, char* name) {
    struct TaxPayer* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // Taxpayer not found
}

// Function to delete a taxpayer by name
struct TaxPayer* deleteTaxPayer(struct TaxPayer* head, char* name) {
    struct TaxPayer* current = head;
    struct TaxPayer* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                // Deleting the first node
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);  // Free the memory
            return head;
        }

        prev = current;
        current = current->next;
    }

    printf("Taxpayer not found.\n");
    return head;
}

// Function to free the memory allocated for the linked list
void deleteList(struct TaxPayer* head) {
    struct TaxPayer* current = head;
    struct TaxPayer* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct TaxPayer* head = NULL;  // Initialize an empty linked list

    int choice;
    char name[50];
    double income, taxAmount;

    do {
        printf("\nSingle Linked List Menu:\n");
        printf("1. Add Taxpayer\n");
        printf("2. Display Taxpayers\n");
        printf("3. Search Taxpayer\n");
        printf("4. Delete Taxpayer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter taxpayer details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Income: ");
                scanf("%lf", &income);
                printf("Tax Amount: ");
                scanf("%lf", &taxAmount);
                head = addNodeAtEnd(head, name, income, taxAmount);
                break;

            case 2:
                printf("Taxpayers in the list:\n");
                displayList(head);
                break;

            case 3:{
			
                printf("Enter the name to search: ");
                scanf("%s", name);
                struct TaxPayer* foundTaxPayer = searchTaxPayer(head, name);
                if (foundTaxPayer != NULL) {
                    printf("Taxpayer found - Name: %s, Income: %.2f, Tax Amount: %.2f\n", foundTaxPayer->name, foundTaxPayer->income, foundTaxPayer->taxAmount);
                } else {
                    printf("Taxpayer not found.\n");
                }
                break;
            }

            case 4:
                printf("Enter the name to delete: ");
                scanf("%s", name);
                head = deleteTaxPayer(head, name);
                break;

            case 5:
                // Free the memory allocated for the linked list
                deleteList(head);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}


// 5.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix) {
    Stack* stack = createStack(MAX_SIZE);
    int i, k;

    printf("Postfix expression: ");
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                printf("%c", pop(stack));
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                printf("%c", pop(stack));
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        printf("%c", pop(stack));
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    Stack* stack = createStack(MAX_SIZE);
    int i, operand1, operand2;

    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char infix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    printf("\nEnter the postfix expression: ");
    char postfix[MAX_SIZE];
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}

//6.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<cstring>

struct Taxpayer {
    char name[50];
    char ssn[15];
    float income;
    struct Taxpayer* next;
};

// Node for regular queue
struct Node {
    struct Taxpayer* data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Node for priority queue
struct PQNode {
    struct Taxpayer* data;
    int priority;
    struct PQNode* next;
};

struct PriorityQueue {
    struct PQNode *front;
};

// Circular Queue
#define MAX_SIZE 5
struct Taxpayer* circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function to create a new Taxpayer node
struct Taxpayer* createTaxpayer(char name[], char ssn[], float income) {
    struct Taxpayer* newTaxpayer = (struct Taxpayer*)malloc(sizeof(struct Taxpayer));
    if (newTaxpayer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newTaxpayer->name, name);
    strcpy(newTaxpayer->ssn, ssn);
    newTaxpayer->income = income;
    newTaxpayer->next = NULL;
    return newTaxpayer;
}

// Regular Queue Operations
struct Node* newNode(struct Taxpayer* taxpayer) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = taxpayer;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct Taxpayer* taxpayer) {
    struct Node* temp = newNode(taxpayer);
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
}

void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Taxpayers in the Queue:\n");
    while (temp != NULL) {
        printf("Name: %s | ID: %s | Income: %.2f\n", temp->data->name, temp->data->ssn, temp->data->income);
        temp = temp->next;
    }
}

// Priority Queue Operations
struct PQNode* newPQNode(struct Taxpayer* taxpayer, int p) {
    struct PQNode* temp = (struct PQNode*)malloc(sizeof(struct PQNode));
    temp->data = taxpayer;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

void enqueuePQ(struct PriorityQueue* pq, struct Taxpayer* taxpayer, int p) {
    struct PQNode* start = pq->front;
    struct PQNode* temp = newPQNode(taxpayer, p);

    if (pq->front == NULL || p < pq->front->priority) {
        temp->next = pq->front;
        pq->front = temp;
    } else {
        while (start->next != NULL && start->next->priority <= p) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

void dequeuePQ(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    struct PQNode* temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
}

void displayPQ(struct PriorityQueue* pq) {
    struct PQNode* temp = pq->front;
    if (temp == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Taxpayers in the Priority Queue:\n");
    while (temp != NULL) {
        printf("Name: %s | ID: %s | Income: %.2f | Priority: %d\n", temp->data->name, temp->data->ssn, temp->data->income, temp->priority);
        temp = temp->next;
    }
}

// Circular Queue Operations
bool isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

bool isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueueCircular(struct Taxpayer* taxpayer) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    circularQueue[rear] = taxpayer;
    printf("Enqueued taxpayer to Circular Queue\n");
}

void dequeueCircular() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    } else if (front == rear) {
        printf("Dequeued taxpayer from Circular Queue\n");
        front = rear = -1;
    } else {
        printf("Dequeued taxpayer from Circular Queue\n");
        front = (front + 1) % MAX_SIZE;
    }
}

void displayCircularQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Taxpayers in Circular Queue:\n");
    while (i != rear) {
        printf("Name: %s | ID: %s | Income: %.2f\n", circularQueue[i]->name, circularQueue[i]->ssn, circularQueue[i]->income);
        i = (i + 1) % MAX_SIZE;
    }
    printf("Name: %s | ID: %s | Income: %.2f\n", circularQueue[rear]->name, circularQueue[rear]->ssn, circularQueue[rear]->income);
}

int main() {
    struct Queue* queue = createQueue();
    struct PriorityQueue* pq = createPriorityQueue();
    int choice;
    char name[50], ssn[15];
    float income;
    int priority;
    int subChoice;
    int subChoicePQ;
	int subChoiceCircular;
	
    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Queue (FIFO)\n");
        printf("2. Priority Queue\n");
        printf("3. Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Linear Queue Operations\n");
                do{
                printf("1. Enqueue taxpayer\n");
                printf("2. Dequeue taxpayer\n");
                printf("3. Display taxpayers\n");
                printf("4. Exit\n");
				printf("Enter your choice (1-4): ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter taxpayer's name: ");
                        scanf("%s", name);
                        printf("Enter taxpayer's ID: ");
                        scanf("%s", ssn);
                        printf("Enter taxpayer's income: ");
                        scanf("%f", &income);
                        enqueue(queue, createTaxpayer(name, ssn, income));
                        printf("Taxpayer added to the queue.\n");
                        break;
                    case 2:
                        dequeue(queue);
                        printf("Processed taxpayer.\n");
                        break;
                    case 3:
                        displayQueue(queue);
                        break;
                    case 4:
                        printf("Exiting the program...\n");
                        exit(0);
                    default:
                        printf("Invalid choice\n");
                }
            }while(subChoice!=4);
                break;

            case 2:
                printf("Priority Queue Operations\n");
                do{
                printf("1. Enqueue taxpayer\n");
                printf("2. Dequeue taxpayer\n");
                printf("3. Display taxpayers\n");
                printf("4. Exit\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &subChoicePQ);
                switch (subChoicePQ) {
                    case 1:
                        printf("Enter taxpayer's name: ");
                        scanf("%s", name);
                        printf("Enter taxpayer's ID: ");
                        scanf("%s", ssn);
                        printf("Enter taxpayer's income: ");
                        scanf("%f", &income);
                        printf("Enter taxpayer's priority: ");
                        scanf("%d", &priority);
                        enqueuePQ(pq, createTaxpayer(name, ssn, income), priority);
                        printf("Taxpayer added to the priority queue.\n");
                        break;
                    case 2:
                        dequeuePQ(pq);
                        printf("Processed taxpayer from priority queue.\n");
                        break;
                    case 3:
                        displayPQ(pq);
                        break;
                    case 4:
                        printf("Exiting the program...\n");
                        exit(0);
                    default:
                        printf("Invalid choice\n");
                }
            }while(subChoicePQ != 4);
                break;

            case 3:
                printf("Circular Queue Operations\n");
                do{
                printf("1. Enqueue taxpayer\n");
                printf("2. Dequeue taxpayer\n");
                printf("3. Display taxpayers\n");
                printf("4. Exit\n");
				printf("Enter your choice (1-4): ");
                scanf("%d", &subChoiceCircular);
                switch (subChoiceCircular) {
                    case 1:
                        printf("Enter taxpayer's name: ");
                        scanf("%s", name);
                        printf("Enter taxpayer's ID: ");
                        scanf("%s", ssn);
                        printf("Enter taxpayer's income: ");
                        scanf("%f", &income);
                        enqueueCircular(createTaxpayer(name, ssn, income));
                        break;
                    case 2:
                        dequeueCircular();
                        break;
                    case 3:
                        displayCircularQueue();
                        break;
                    case 4:
                        printf("Exiting the program...\n");
                        exit(0);
                    default:
                        printf("Invalid choice\n");
                }
            }while(subChoiceCircular != 4);
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}


//7.
#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons);
int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons);
void bubbleSort(int arr[], int n, int *comparisons, int *transfers);
void insertionSort(int arr[], int n, int *comparisons, int *transfers);

int i, j;

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int intArray[n];
    char charArray[n];

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &intArray[i]);
    }

    printf("Enter %d characters:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &charArray[i]);
    }

    int keyLinear;
    printf("Enter the integer to search using Linear Search: ");
    scanf("%d", &keyLinear);

    int elementComparisonsLinear = 0, indexComparisonsLinear = 0;
    int linearResult = linearSearch(intArray, n, keyLinear, &elementComparisonsLinear, &indexComparisonsLinear);

    printf("Element Comparisons (Linear): %d\n", elementComparisonsLinear);
    printf("Index Comparisons (Linear): %d\n", indexComparisonsLinear);
    printf("\n");

    int keySentinel;
    printf("Enter the integer to search using Sentinel Search: ");
    scanf("%d", &keySentinel);

    int elementComparisonsSentinel = 0, indexComparisonsSentinel = 0;
    int sentinelResult = sentinelSearch(intArray, n, keySentinel, &elementComparisonsSentinel, &indexComparisonsSentinel);

    printf("Element Comparisons (Sentinel): %d\n", elementComparisonsSentinel);
    printf("Index Comparisons (Sentinel): %d\n", indexComparisonsSentinel);
    printf("\n");

    int bubbleComparisons = 0, bubbleTransfers = 0;
    bubbleSort(intArray, n, &bubbleComparisons, &bubbleTransfers);
    printf("Bubble Sort Comparisons: %d\n", bubbleComparisons);
    printf("Bubble Sort Transfers: %d\n", bubbleTransfers);
    printf("\n");

    int insertionComparisons = 0, insertionTransfers = 0;
    insertionSort(intArray, n, &insertionComparisons, &insertionTransfers);
    printf("Insertion Sort Comparisons: %d\n", insertionComparisons);
    printf("Insertion Sort Transfers: %d\n", insertionTransfers);
    printf("\n");

    int keyBinary;
    printf("Enter the integer to search using Binary Search: ");
    scanf("%d", &keyBinary);

    int elementComparisonsBinary = 0, indexComparisonsBinary = 0;
    int binaryResult = binarySearch(intArray, 0, n - 1, keyBinary, &elementComparisonsBinary, &indexComparisonsBinary);
    printf("Binary Search Result: %d\n", binaryResult);
    printf("Element Comparisons (Binary): %d\n", elementComparisonsBinary);
    printf("Index Comparisons (Binary): %d\n", indexComparisonsBinary);

    return 0;
}

int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons)
{
    for (i = 0; i < n; i++)
    {
        (*elementComparisons)++;
        if (arr[i] == key)
        {
            (*indexComparisons)++;
            return i;
        }
    }
    (*indexComparisons)++;
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons)
{
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key)
    {
        (*elementComparisons)++;
        i++;
    }
    arr[n - 1] = last;

    if (i < n - 1)
    {
        (*indexComparisons)++;
        return i;
    }
    else
    {
        (*indexComparisons)++;
        return -1;
    }
}

int binarySearch(int arr[], int low, int high, int key, int *elementComparisons, int *indexComparisons)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        (*elementComparisons)++;
        if (arr[mid] == key)
        {
            (*indexComparisons)++;
            return mid;
        }
        else if (arr[mid] < key)
        {
            (*indexComparisons)++;
            return binarySearch(arr, mid + 1, high, key, elementComparisons, indexComparisons);
        }
        else
        {
            (*indexComparisons)++;
            return binarySearch(arr, low, mid - 1, key, elementComparisons, indexComparisons);
        }
    }
    (*indexComparisons)++;
    return -1;
}

void bubbleSort(int arr[], int n, int *comparisons, int *transfers)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            (*comparisons)++;
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*transfers)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparisons, int *transfers)
{
    for (i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        (*comparisons)++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            (*transfers)++;
        }
        arr[j + 1] = key;
    }
}
