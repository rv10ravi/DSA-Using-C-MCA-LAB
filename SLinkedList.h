
struct node
{
    int routeNumber;
    char transportType[20];
    struct node *next;
};

extern struct node *head;

void begInsert();
void lastInsert();
void randomInsert();
void beginDelete();
void lastDelete();
void randomDelete();
void display();
void search();


