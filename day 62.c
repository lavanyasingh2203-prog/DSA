#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node** adjList;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v) {
    // Add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // For undirected graph, add u to v's list
    struct Node* newNode2 = createNode(u);
    newNode2->next = graph->adjList[v];
    graph->adjList[v] = newNode2;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d: ", i);

        struct Node* temp = graph->adjList[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}