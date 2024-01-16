#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }

    return root;
}

void printBFT(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Use a queue for BFT
    struct Node* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        struct Node* current = queue[++front];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[++rear] = current->left;
        }

        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }

    printf("\n");
}

void printDFT(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Use recursion for DFT
    printf("%d ", root->data);
    printDFT(root->left);
    printDFT(root->right);
}

int searchBFT(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    // Use a queue for BFT
    struct Node* queue[100];
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        struct Node* current = queue[++front];

        if (current->data == key) {
            return 1; // Key found
        }

        if (current->left != NULL) {
            queue[++rear] = current->left;
        }

        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }

    return 0; // Key not found
}

int searchDFT(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    // Use recursion for DFT
    if (root->data == key) {
        return 1; // Key found
    }

    int leftSearch = searchDFT(root->left, key);
    int rightSearch = searchDFT(root->right, key);

    return leftSearch || rightSearch;
}

int main() {
    struct Node* root = NULL;
    int choice, data, key, n;

    do {
        printf("\nMenu:\n");
        printf("1. Insert into BST\n");
        printf("2. Print Breadth-First Traversal (BFT)\n");
        printf("3. Print Depth-First Traversal (DFT)\n");
        printf("4. Search using BFT\n");
        printf("5. Search using DFT\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of data elements: ");
                scanf("%d", &n);
                printf("Enter %d data elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = insertBST(root, data);
                }
                break;
            case 2:
                printf("Breadth-First Traversal (BFT): ");
                printBFT(root);
                break;
            case 3:
                printf("Depth-First Traversal (DFT): ");
                printDFT(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the key to search using BFT: ");
                scanf("%d", &key);
                if (searchBFT(root, key)) {
                    printf("%d found using BFT.\n", key);
                } else {
                    printf("%d not found using BFT.\n", key);
                }
                break;
            case 5:
                printf("Enter the key to search using DFT: ");
                scanf("%d", &key);
                if (searchDFT(root, key)) {
                    printf("%d found using DFT.\n", key);
                } else {
                    printf("%d not found using DFT.\n", key);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
