
struct node
{
    int routeNumber;
    char transportType[20];
    char departureTime[10];
    struct node *next;
};

extern struct node *head;

void beginsert();
void lastinsert();
void insertion_inbetween();
void begin_delete();
void last_delete();
void delete_inbetween();
void search();
void display();


