#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};

//  represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// find the parent of a vertex using union-find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

//  perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    int i = 0; // index variable for result[]
    int e = 0; // index variable for sorted edges array

    // sorting  edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding edges to the MST until V-1 edges are added
    while (i < V - 1 && e < E) {
        struct Edge nextEdge = edges[e++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, add it to the MST
        if (x != y) {
            result[i++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the edges of the MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < V - 1; i++) {
        printf("%d -- %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

    return 0;
}
