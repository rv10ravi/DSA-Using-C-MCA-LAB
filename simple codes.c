// Program 1: Hashing
// Program 2: Naive Pattern Searching algorithm (first)
// Program 3: Naive Pattern Searching algorithm (last)
// Program 4: Binary Tree (normal traversal)
// Program 5: Binary Tree (depth order construction)
// Program 6: Binary Tree (level order construction)
// Program 7: BFS
// Program 8: DFS
// Program 9: Calculate the height of BT 
// Program 10: Binary Search Tree operations
// Program 11: Calculate the depth of BT
// Program 12: BST Traversal (in order, pre order, post order)

// Program 1: Hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3//size of hash table 
#define h(x) (x % m) //hash fn definition


typedef struct Node{
    int v;
    struct Node *next;
}Node;


Node *fill_table(Node *table, int table_range, int number);
Node *insert(Node *table, int hash_index, int v);
Node *del(Node *table,int table_range,int v);
void print_table(Node *table, int table_range);
void search_table(Node *table, int table_range, int v);

int main(){
    Node *table; 
    int n, i, j, choice, search;
    int hash_num, v;	 	

    
    table = (Node*) malloc(N*sizeof(Node));
//initializing all linked lists for keys as null    
    for(i = 0; i < N; i++){
    	table[i].next = NULL;
    }
	
    printf("--h(x) = xmod%d--\n",N);
    printf("\n\n");	 

    while(1){
    	printf("---------------------1.Insert some random numbers---------------------\n");
    	printf("---------------------2.Delete a number---------------------\n");
		printf("---------------------3.Search for a number---------------------\n");
		printf("---------------------4.Show the Hash Table---------------------\n");
		printf("---------------------0.Exit Program---------------------\n");		
		printf("\n--------\n");
		printf("Please enter your Choice: ");
		scanf("%d",&choice);
	
	switch(choice){
		case 0: return 0;
		case 1:
			
			printf("Lot to insert: ");
			scanf("%d", &n);
			table = fill_table(table, N, n);
			printf("Filled HashTable with %d random values\n", n);
			printf("\n--------\n");
			break;
		case 2:
			
			printf("Enter a number: ");
			scanf("%d",&search);
			table = del(table, N, search);
			printf("\n--------\n");	
			break;
		case 3:
			
			printf("Enter a number: ");
			scanf("%d",&search);			
			search_table(table, N, search);
			printf("\n--------\n");	
			break;
		case 4:
			
			printf("-HASHTABLE-\n\n");
			print_table(table, N);
			printf("\n--------\n");	
			break;	
	    }
	}	
	return 0;
}


Node *fill_table(Node *table, int table_range, int number){
    int i;
    int num;
    for(i=0; i<number; i++){
	num = rand()%10000; 
	table = insert(table, num % table_range, num);
    }
    return table;
}

void print_table(Node *table, int table_range){
    int i;
    Node* cur;
    for(i = 0; i < table_range; i++){ 
	if(table[i].next == NULL){ 
                printf("Table[%d] is empty!\n", i);
		continue;
	}
	cur = table[i].next;
	printf("Table[%d]", i);
	while(cur!=NULL){ 
		printf("->%d",cur->v);
		cur=cur->next; 
	}
	printf("\n");	
    }
}

Node *insert(Node *table, int hash_index, int v){
    Node *nn, *cur;

    nn = (Node*)malloc(sizeof(Node));
    nn->v=v;
    nn->next=NULL;
	
    if(table[hash_index].next == NULL){
	table[hash_index].next = nn;
	return table;
    }
	
    cur = table[hash_index].next;
    while(cur->next != NULL){
	cur=cur->next; //cur=cur+1;
    }
    cur->next = nn;
    return table;
}

void search_table(Node *table, int table_range, int v){
    int index = v % table_range;
    Node *cur;
	
    if(table[index].next == NULL){ // if empty
		printf("value %d not found cause Table[%d] is emtpy!\n", v,index);
                return;
    }

    cur = table[index].next;
    while(cur!=NULL){
	if(cur->v == v){
		printf("value %d was found!\n", v);
		return;
	}
	cur = cur->next;
    }
    printf("value %d not found in Hashtable!\n", v);
}

Node *del(Node *table, int table_range, int v){
    int index = v % table_range;
    Node *prev;
	
    if(table[index].next == NULL){ // if empty
	printf("value %d not found cause Table[%d] is emtpy!\n", v,index);
	return table;
    }
	
    if(table[index].next->v == v){ // if first item
	printf("value %d was found at table[%d] and Deleted!\n", v,index);
	table[index].next = table[index].next->next;
	return table;
    }

    prev = table[index].next;
    while(prev->next!=NULL){
	if(prev->next->v == v){
		prev->next = prev->next->next;
		printf("value %d was found at table[%d] and Deleted!\n", v,index);
		return table;
	}
	prev = prev->next;
    }
    printf("value %d was not found in Hashtable!\n", v);
    return table;
}


// Program 2: C program for Naive Pattern Searching algorithm (First)
#include <stdio.h> 
#include <string.h> 
  //first char pattern match with text
void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  int i,j;
    /* A loop to slide pat[] one by one */
    for (i = 0; i <= N - M; i++) { 
          
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            printf("Pattern found at index %d \n", i); 
               
    } 
    
         
} 
  
int main() 
{ 
    //CASE 1
	
	char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
        
    
    
/*
//CASE---2---
 char txt[]= "AABCCAADDEE"; 
char pat[] = "FAA";
*/

  /*


// CASE---3
   
char txt[] = "AAAAAAAAAAAAAAAAAA"; 
char pat[] = "AAAAA";
  
*/
/*
//CASE---4
char txt[] = "AAAAAAAAAAAAAAAAAB"; 
char pat[] = "AAAAB"; 
  
 */

    search(pat, txt); 
    return 0; 
} 

// Program 3: C program for Naive Pattern Searching algorithm (Last)
#include <stdio.h> 
#include <string.h> 
  
void nfind(char* string, char* pat) 
{ 
int i,j=-1,start=0;
int lasts=strlen(string)-1;
int lastp=strlen(pat)-1;
int endmatch=lastp;
for(i=0;endmatch<=lasts;endmatch++,start++)
{
	if (string[endmatch]==pat[lastp])
		for (j=0,i=start;j<lastp &&string[i]==pat[j];i++,j++)
			;
	if(j==lastp)
	{
	  printf ("PATTERN is found at position %d \n",start);
	  j=0;
}

}
if (j==-1)
printf("PATTERN not found\n" );
 }
    
int main() 
{ 

/* 
  // CASE---1----PATTERN FOUND
char txt[] = "ABCABA"; 
char pat[] = "CAB"; 
*/


 // CASE---2----PATTERN NOT FOUND---when first character of pattern is not matching in text 
char txt[] = "ABCABA"; 
char pat[] = "ABX"; 


/*
 // CASE---3----UNIQUE CHARACTERS IN TEXT AND PATTERN 
char txt[] = "ABCDEFGH"; 
char pat[] = "DEF"; 
*/

/*
 // CASE---4----PATTERN FOUND IN THE END OF THE TEXT
char txt[] = "ABCDABCABCDF"; 
char pat[] = "ABCDF"; 
*/

/*
// CASE 5----pattern found at multiple places in text
	char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
*/
  
/*
// CASE---6---All characters in TEXT & PATTERN ARE SAME   
char txt[] = "AAAAAAAAAAAAAAAAAA"; 
char pat[] = "AAAAA";
  */

/*
//CASE---7
char txt[] = "AAAAAB"; 
char pat[] = "AAAAB"; 
  */


    printf("GIVEN TEXT IS %s\n" ,txt);
    printf("GIVEN PATTERN IS %s\n" ,pat);
   
    nfind(txt,pat);
    return 0; 
} 

// Program 4: Binary Tree (normal traversal)
#include<stdio.h>
#include <stdlib.h>

struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
};

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
}

void display(struct node *root)
{
   if(root != NULL){
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
   }
}
int main() 
{ 
	struct node *root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	
	display(root);
	getch(); 
}

// Program 5: Binary Tree (depth order construction)
#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;
 
node *create()
{
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(node*)malloc(sizeof(node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=create();
 
	printf("Enter right child of %d:\n",x);
	p->right=create();
	
	return p;
}
 
void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		//visit the root
		preorder(t->left);		//preorder traversal on left subtree
		preorder(t->right);		//preorder traversal om right subtree
	}
}
 
int main()
{	
	node *root;
	root=create();
	printf("\nThe preorder traversal of tree is:\n");
	preorder(root);
	
	return 0;
}

//Program 6: Binary Tree (LEVEL ORDER CONSTRUCTION)
#include <stdio.h>
#include <stdlib.h>  
struct Node
{
    int data;
    struct Node* left, * right;
};
  
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
  
struct Node* insert(int arr[], struct Node* root, int i, int n)
{
    // Base case for recursion
    if (i < n)
    {
        struct Node* temp = newNode(arr[i]);
        root = temp;
  
        // insert left child
        root->left = insert(arr, root->left, 2 * i + 1, n);
  
        // insert right child
        root->right = insert(arr, root->right, 2 * i + 2, n);
    }
    return root;
}
  
// Function to print tree nodes in InOrder fashion
void inOrder(struct Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data );
        inOrder(root->right);
    }
}
  
int main()
{
    int arr[] = { 27, 14, 35, 10, 19, 31, 42 };
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Node* root = insert(arr, root, 0, n);
    inOrder(root);
}

//Program 7: BFS

// undirected Graph Representation Adjacency Matrix
#include <stdio.h>
// n vertices and m Edges
int adj[20][20], n,m, q[20],visited[20],f=-1,r=-1;
//edge representation
struct edge
{
	int s,d;
};
struct edge e[20];
// Function to create Adjacency Matrix

void createadjmatrix( struct edge e[])
{
    int i,j,x,y;
	// Initialise all value to this Adjacency matrix to zero
    for ( i = 0; i < n ; i++) {
  
        for (j = 0; j < n ; j++) {
            adj[i][j] = 0;
        }
    }
  
    // Traverse the array of Edges
    for (i = 0; i < m; i++) 
	{
        // Find X and Y of Edges as source and destination of the edges
         x = e[i].s;
        y = e[i].d;
       // Update value to 1
        adj[x][y] = 1;
        adj[y][x] = 1;//not required in case of directed graph
   }
    for (i = 0; i < n ; i++) 
   {
   		 for (j = 0; j < n ; j++) 
		    printf("%d ", adj[i][j]);
         printf("\n");
    }
        
    }
  
void bfs(int v) 
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(adj[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       r=r+1;
                       q[r]=i;                       // insert them into queue
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
              }
      }
      f=f+1;                             // remove the vertex at front of the queue
      if(f<=r)                           // as long as there are elements in the queue
            bfs(q[f]);                  // peform bfs again on the vertex at front of the queue
}
  

int main()
{
  int i, j,v;
  char ch='y';
  m=0;i=0;
  printf("Enter no of vertices: ");
  scanf("%d", &n);
  
 while(ch=='y')
 {
   	printf("Enter source of edge: ");
   	scanf("%d", &e[i].s);
   	printf("Enter destination of edge: ");
   	scanf("%d", &e[i].d);
    printf("do you want to add edges: ");
    fflush(stdin);
    scanf("%c", &ch);
    m=m+1;
    i++;
  }


    // Function call to create Adjacency Matrix
    createadjmatrix(e);
  
     
  
    for (i=0;i<n;i++)                   // mark all the vertices as not visited
    {
        visited[i]=0;
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    f=r=0;
    q[r]=v;
    printf("\n BFS traversal is:\n");
    visited[v]=1;                                     // mark the starting vertex as visited
    printf("%d   ",v);
   
    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
  
  
  
}


// Program 8: DFS
#include <stdio.h>
// n vertices and m Edges
int adj[20][20], n,m, q[20],visited[20];
//edge representation
struct edge
{
	int s,d;
};
struct edge e[20];
// Function to create Adjacency Matrix

void createadjmatrix( struct edge e[])
{
    int i,j,x,y;
	// Initialise all value to this Adjacency matrix to zero
    for ( i = 0; i < n ; i++) {
  
        for (j = 0; j < n ; j++) {
            adj[i][j] = 0;
        }
    }
  
    // Traverse the array of Edges
    for (i = 0; i < m; i++) 
	{
        // Find X and Y of Edges as source and destination of the edges
         x = e[i].s;
        y = e[i].d;
       // Update value to 1
        adj[x][y] = 1;
        adj[y][x] = 1;//not required in case of directed graph
   }
    for (i = 0; i < n ; i++) 
   {
   		 for (j = 0; j < n ; j++) 
		    printf("%d ", adj[i][j]);
         printf("\n");
    }
        
    }
  void dfs(int v)
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(adj[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
                       dfs(i);
              }
      }
}
 
int main()
{
  int i, j,v;
  char ch='y';
  m=0;i=0;
  printf("Enter no of vertices: ");
  scanf("%d", &n);
  
 while(ch=='y')
 {
   	printf("Enter source of edge: ");
   	scanf("%d", &e[i].s);
   	printf("Enter destination of edge: ");
   	scanf("%d", &e[i].d);
    printf("do you want to add edges: ");
    fflush(stdin);
    scanf("%c", &ch);
    m=m+1;
    i++;
  }
  // Function call to create Adjacency Matrix
    createadjmatrix(e);
    for (i=0;i<n;i++)                   // mark all the vertices as not visited
    {
        visited[i]=0;
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
   printf("\n DFS traversal is:\n");
    visited[v]=1; // mark the starting vertex as visited
    printf("%d   ",v);
    dfs(v);
   }
   
//Program 9: Calculate the heigth of BT
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

int height (struct node *node)
{
  if (node == NULL)
    return 0;
  else
    {

      int leftHeight = height (node->left);
      int rightHeight = height (node->right);

      if (leftHeight > rightHeight)
	return (leftHeight + 1);
      else
	return (rightHeight + 1);
    }
}
struct node *newNode (int data)
{
  struct node *node = (struct node *) malloc (sizeof (struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

int main ()
{
  struct node *root = newNode (10);

  root->left = newNode (20);
  root->right = newNode (30);
  root->left->left = newNode (40);
  root->left->right = newNode (50);

  printf ("Height of tree is %d", height (root));


  return 0;
}

// Program 10: Binary Search Tree Operations
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; //node will store some data
  struct node *right_child; // right child
  struct node *left_child; // left child
};

//function to create a node
struct node* new_node(int x) {
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp -> data = x;
  temp -> left_child = NULL;
  temp -> right_child = NULL;

  return temp;
}

// searching operation
struct node* search(struct node * root, int x) {
  if (root == NULL || root -> data == x) //if root->data is x then the element is found
    return root;
  else if (x > root -> data) // x is greater, so we will search the right subtree
    return search(root -> right_child, x);
  else //x is smaller than the data, so we will search the left subtree
    return search(root -> left_child, x);
}

// insertion
struct node* insert(struct node * root, int x) {
  //searching for the place to insert
  if (root == NULL)
    return new_node(x);
  else if (x > root -> data) // x is greater. Should be inserted to the right
    root -> right_child = insert(root -> right_child, x);
  else // x is smaller and should be inserted to left
    root -> left_child = insert(root -> left_child, x);
  return root;
}

//function to find the minimum value in a node
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root -> left_child != NULL) // node with minimum value will have no left child
    return find_minimum(root -> left_child); // left most element will be minimum
  return root;
}

// deletion
struct node* delete(struct node * root, int x) {
  //searching for the item to be deleted
  if (root == NULL)
    return NULL;
  if (x > root -> data)
    root -> right_child = delete(root -> right_child, x);
  else if (x < root -> data)
    root -> left_child = delete(root -> left_child, x);
  else {
    //No Child node
    if (root -> left_child == NULL && root -> right_child == NULL) {
      free(root);
      return NULL;
    }

    //One Child node
    else if (root -> left_child == NULL || root -> right_child == NULL) {
      struct node *temp;
      if (root -> left_child == NULL)
        temp = root -> right_child;
      else
        temp = root -> left_child;
      free(root);
      return temp;
    }

    //Two Children
    else {
      struct node *temp = find_minimum(root -> right_child);
      root -> data = temp -> data;
      root -> right_child = delete(root -> right_child, temp -> data);
    }
  }
  return root;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) // checking if the root is not null
  {
    inorder(root -> left_child); // traversing left child
    printf(" %d ", root -> data); // printing data at root
    inorder(root -> right_child); // traversing right child
  }
}

int main() {
  struct node *root;
  root = new_node(20);
  insert(root, 5);
  insert(root, 1);
  insert(root, 15);
  insert(root, 9);
  insert(root, 7);
  insert(root, 12);
  insert(root, 30);
  insert(root, 25);
  insert(root, 40);
  insert(root, 45);
  insert(root, 42);

  inorder(root);
  printf("\n");

  root = delete(root, 1);

  root = delete(root, 40);

  root = delete(root, 45);

  root = delete(root, 9);

  inorder(root);
  printf("\n");

  return 0;
}


// Program 11: Calculate the depth of BT
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the depth of a binary tree
int findDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

int main() {
    // Creating a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Finding and printing the depth of the binary tree
    int treeDepth = findDepth(root);
    printf("Depth of the binary tree: %d\n", treeDepth);

    return 0;
}

// Program 12: BST (in order, pre order, post order)
#include<stdio.h>
#include<stdlib.h>

struct treenode
{
        int info;
        struct treenode *lchild;
        struct treenode *rchild;
}*root=NULL;

struct listnode
{
        struct listnode *prev;
        int info;
        struct listnode *next;
}*pre=NULL, *in=NULL;

void display(struct treenode *ptr,int level);
struct listnode *addtoempty(struct listnode *start,int data);
struct listnode *addatend(struct listnode *start,int data);
struct listnode *create_list(struct listnode *start, int n);
struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num);
void inorder(struct treenode *ptr);
void postorder(struct treenode *ptr);
void preorder(struct treenode *ptr);

int main( )
{
        int n;

        printf("Enter the number of nodes  :  ");
        scanf("%d",&n);

        printf("\nEnter inorder\n");
        in = create_list(in, n);

        printf("\nEnter preorder\n");
        pre=create_list(pre, n);

        root = construct(in,pre,n);

        printf("\nInorder : ");  inorder(root);
        printf("\n\nPostorder : ");  postorder(root);
        printf("\n\nPreorder : "); preorder(root);
        printf("\n\n\nTree is : \n");
        display(root,0);
        printf("\n");

        return 0;
}

struct treenode *construct(struct listnode *inptr,struct listnode *preptr, int num )
{
        struct treenode *temp;
        struct listnode *q;

        int i,j;
        if(num==0)
                return NULL;
//firstnode in preorer is the root node
        temp=(struct treenode *)malloc(sizeof(struct treenode));
        temp->info=preptr->info;
        temp->lchild = NULL;
        temp->rchild = NULL;

        if(num==1)/*if only one node in tree */
                return temp;
//finding the root node in inorder.....
        q = inptr;
        for(i=0; q->info != preptr->info; i++)
                q = q->next;

        /*Now q points to root node in inorder list and
         and number of nodes in its left subtree is i*/

        /*For left subtree*/
        temp->lchild = construct(inptr, preptr->next, i);

        /*For right subtree*/
        for(j=1;j<=i+1;j++)
                preptr=preptr->next;
        temp->rchild = construct(q->next, preptr, num-i-1);

        return temp;
}/*End of construct()*/

void display(struct treenode *ptr,int level)
{
        int i;
        if ( ptr!=NULL )
        {
                display(ptr->rchild, level+1);
                printf("\n");
                for (i = 0; i < level; i++)
                        printf("    ");
                printf("%d", ptr->info);
                display(ptr->lchild, level+1);
        }
}/*End of display()*/

struct listnode *create_list(struct listnode *start, int n)
{
        int i, data;
        start=NULL;
        for(i=1;i<=n;i++)
        {
                printf("Enter the element to be inserted : ");
                scanf("%d",&data);
                if(start==NULL)
                        start=addtoempty(start,data);
                else
                        start=addatend(start,data);
        }
        return start;
}/*End of create_list()*/

struct listnode *addtoempty(struct listnode *start,int data)
{
        struct listnode *tmp;
        tmp=(struct listnode*)malloc(sizeof(struct listnode));
        tmp->info=data;
        tmp->prev=NULL;
        tmp->next=NULL;
        start=tmp;
        return start;
}/*End of addtoempty( )*/
struct listnode *addatend(struct listnode *start,int data)
{
        struct listnode *tmp,*p;
        tmp=(struct listnode*)malloc(sizeof(struct listnode));
        tmp->info=data;
        p=start;
        while(p->next!=NULL)
                p=p->next;
        p->next=tmp;
        tmp->next=NULL;
        tmp->prev=p;
        return start;
}/*End of addatend( )*/

void inorder(struct treenode *ptr)
{
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        if(ptr!=NULL)
        {
                inorder(ptr->lchild);
                printf("%d  ",ptr->info);
                inorder(ptr->rchild);
        }
}/*End of inorder( )*/
void postorder(struct treenode *ptr)
{
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        if(ptr!=NULL)
        {
                postorder(ptr->lchild);
                postorder(ptr->rchild);
                printf("%d  ",ptr->info);
        }
}/*End of postorder( )*/

void preorder(struct treenode *ptr)
{
        if(root==NULL)
        {
                printf("Tree is empty");
                return;
        }
        if(ptr!=NULL)
        {
                printf("%d  ",ptr->info);
                preorder(ptr->lchild);
                preorder(ptr->rchild);
        }
}/*End of preorder( )*/
