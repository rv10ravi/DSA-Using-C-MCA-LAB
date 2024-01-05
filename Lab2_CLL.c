

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

struct node *head;

void main()
{
    int choice = 0;
    while (choice != 8)
    {
        printf("\n********Main Menu********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1.Insert at the beginning\n2.Insert at last\n3.Insert in between\n4.Delete from Beginning\n5.Delete from last\n6.Delete in between\n7.Search\n8.Show\n9.Exit\n");
        printf("Enter your choice?\n");
        scanf("\n%d", &choice);

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            insertion_inbetween();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            delete_inbetween();
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


void beginsert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Route Number: ");
        scanf("%d", &ptr->routeNumber);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        ptr->next = head;

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            head = ptr;
        }

        printf("\nNode inserted\n");
    }
}

void lastinsert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Route Number: ");
        scanf("%d", &ptr->routeNumber);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }

        printf("\nNode inserted\n");
    }
}

void insertion_inbetween()
{
    struct node *ptr, *temp;
    int item, loc, i;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = head;
        printf("Enter the location after which you want to insert: ");
        scanf("%d", &loc);

        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                printf("\nCan't insert\n");
                return;
            }
        }

        printf("Enter Route Number: ");
        scanf("%d", &ptr->routeNumber);
        printf("Enter Transport Type: ");
        scanf("%s", ptr->transportType);
        printf("Enter Departure Time: ");
        scanf("%s", ptr->departureTime);

        ptr->next = temp->next;
        temp->next = ptr;

        printf("\nNode inserted\n");
    }
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nNode deleted\n");
    }
}

void last_delete()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void delete_inbetween()
{
    struct node *ptr, *temp;
    int loc, i;

    if (head == NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }

    printf("Enter the location after which you want to delete: ");
    scanf("%d", &loc);

    ptr = head;

    for (i = 0; i < loc - 1; i++)
    {
        ptr = ptr->next;
        if (ptr == head)
        {
            printf("\nCan't delete\n");
            return;
        }
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    printf("\nNode deleted\n");
}

void search()
{
    struct node *ptr;
    int routeNumber, flag = 1;
    ptr = head;

    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Route Number to search: ");
        scanf("%d", &routeNumber);

        while (ptr->next != head)
        {
            if (ptr->routeNumber == routeNumber)
            {
                printf("\nRoute found at location\n");
                flag = 0;
                break;
            }
            ptr = ptr->next;
        }

        if (flag != 0)
        {
            printf("\nRoute not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    if (head == NULL)
    {
        printf("\nNothing to print\n");
    }
    else
    {
        printf("\nPrinting values...\n");

        while (ptr->next != head)
        {
            printf("Route Number: %d\n", ptr->routeNumber);
            printf("Transport Type: %s\n", ptr->transportType);
            printf("Departure Time: %s\n", ptr->departureTime);
            printf("-------------------------------\n");
            ptr = ptr->next;
        }
        printf("Route Number: %d\n", ptr->routeNumber);
        printf("Transport Type: %s\n", ptr->transportType);
        printf("Departure Time: %s\n", ptr->departureTime);
    }
}


