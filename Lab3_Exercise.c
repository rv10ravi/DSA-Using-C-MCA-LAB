#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function prototypes
struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
int peek(struct Stack* stack);
int pop(struct Stack* stack);
void push(struct Stack* stack, int op);
int isOperator(char ch);
int precedence(char op);
void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to get the top element of the stack
int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // Special value indicating an empty stack
}

// Function to push an element onto the stack
void push(struct Stack* stack, int op) {
    stack->array[++stack->top] = op;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (infix[i] == ' ' || infix[i] == '\t') {
            i++;
            continue;
        }

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Pop '('
            i++;
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

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

    result = pop(stack);
    return result;
}

// Main menu-driven function
int main() {
    int choice;
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    struct Stack* stack = createStack(MAX_SIZE);

    do {
        printf("\nMenu:\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter Postfix Expression: ");
                scanf("%s", postfix);
                printf("Result of Evaluation: %d\n", evaluatePostfix(postfix));
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

