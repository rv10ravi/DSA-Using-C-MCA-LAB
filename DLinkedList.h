
struct node
{
    struct node *prev;
    struct node *next;
    int routeNumber;
    char origin[50];
    char destination[50];
    char transportType[20];
    char departureTime[10];
};

extern struct node *head;

void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

