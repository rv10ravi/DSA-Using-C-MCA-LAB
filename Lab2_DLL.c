
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

struct node *head;

void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n********Main Menu********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1.Insert at the beginning\n2.Insert at last\n3.Insert at any random location\n");
        printf("4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n");
        printf("7.Search\n8.Show\n9.Exit\n");
        printf("Enter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice..\n");
        }
    }
}


void insertion_beginning()
{
    struct node *ptr;
    int routeNumber;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Route Number: ");
        scanf("%d", &routeNumber);
        ptr->routeNumber = routeNumber;
        printf("Enter Origin: ");
        scanf("%s", ptr->origin);
        printf("Enter Destination: ");
        scanf("%s", ptr->destination);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

void insertion_last()
{
    struct node *ptr, *temp;
    int routeNumber;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Route Number: ");
        scanf("%d", &routeNumber);
        ptr->routeNumber = routeNumber;
        printf("Enter Origin: ");
        scanf("%s", ptr->origin);
        printf("Enter Destination: ");
        scanf("%s", ptr->destination);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nNode inserted\n");
    }
}

void insertion_specified()
{
    struct node *ptr, *temp;
    int routeNumber, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW\n");
    }
    else
    {
        temp = head;
        printf("Enter the location: ");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nThere are less than %d elements\n", loc);
                return;
            }
        }

        printf("Enter Route Number: ");
        scanf("%d", &routeNumber);
        ptr->routeNumber = routeNumber;
        printf("Enter Origin: ");
        scanf("%s", ptr->origin);
        printf("Enter Destination: ");
        scanf("%s", ptr->destination);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        ptr->prev = temp;
        ptr->next = temp->next;
        temp->next = ptr;
        temp->next->prev = ptr;

        printf("\nNode inserted\n");
    }
}

void deletion_beginning()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_specified()
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter the data after which the node is to be deleted: ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->routeNumber != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nNode deleted\n");
    }
}

void display()
{
    struct node *ptr;
    printf("\nPrinting values...\n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("Route Number: %d\n", ptr->routeNumber);
        printf("Origin: %s\n", ptr->origin);
        printf("Destination: %s\n", ptr->destination);
        printf("Transport Type: %s\n", ptr->transportType);
        printf("Departure Time: %s\n", ptr->departureTime);
        printf("\n------------------------");
        ptr = ptr->next;
    }
}

void search()
{
    struct node *ptr;
    int routeNumber, flag = 0;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Route Number to search: ");
        scanf("%d", &routeNumber);
        while (ptr != NULL)
        {
            if (ptr->routeNumber == routeNumber)
            {
                printf("\nRoute found at location %d\n", flag + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nRoute not found\n");
        }
    }
}

