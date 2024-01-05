
#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList.h"

struct node *head;

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n********Main Menu********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in the beginning\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n");
        printf("5.Delete from last\n6.Delete node after specified location\n7.Search for a route\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            begInsert();
            break;
        case 2:
            lastInsert();
            break;
        case 3:
            randomInsert();
            break;
        case 4:
            beginDelete();
            break;
        case 5:
            lastDelete();
            break;
        case 6:
            randomDelete();
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
            printf("Please enter a valid choice..");
        }
    }

    return 0;
}


void begInsert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter route number\n");
        scanf("%d", &(ptr->routeNumber));
        printf("\nEnter transport type\n");
        scanf("%s", ptr->transportType);
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted");
    }
}

void lastInsert()
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter route number\n");
        scanf("%d", &(ptr->routeNumber));
        printf("\nEnter transport type\n");
        scanf("%s", ptr->transportType);
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}

void randomInsert()
{
    int loc;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter route number\n");
        scanf("%d", &(ptr->routeNumber));
        printf("\nEnter transport type\n");
        scanf("%s", ptr->transportType);
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d", &loc);
        temp = head;
        for (int i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nCan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted");
    }
}

void beginDelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning ...\n");
    }
}

void lastDelete()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}

void randomDelete()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d ", loc);
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
        printf("\nEnter route number which you want to search?\n");
        scanf("%d", &routeNumber);
        while (ptr != NULL)
        {
            if (ptr->routeNumber == routeNumber)
            {
                printf("Route found - Type of Transport: %s\n", ptr->transportType);
                flag = 0;
                break;
            }
            
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Route not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nPrinting values . . . . .\n");
        while (ptr != NULL)
        {
            printf("\nRoute Number: %d, Transport Type: %s", ptr->routeNumber, ptr->transportType);
            ptr = ptr->next;
        }
    }
}

