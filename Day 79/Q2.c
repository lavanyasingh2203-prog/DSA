#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

// Adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
Node* rev[MAX];

int visited[MAX];
int stack[MAX];
int top = -1;

// Create node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v) {
    Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    // Reverse graph
    node = createNode(u);
    node->next = rev[v];
    rev[v] = node;
}

// DFS for ordering
void dfs1(int v) {
    visited[v] = 1;

    Node* temp = adj[v];
    while(temp) {
        if(!visited[temp->vertex])
            dfs1(temp->vertex);
        temp = temp->next;
    }

    stack[++top] = v;
}

// DFS on reversed graph
void dfs2(int v) {
    visited[v] = 1;

    Node* temp = rev[v];
    while(temp) {
        if(!visited[temp->vertex])
            dfs2(temp->vertex);
        temp = temp->next;
    }
}

// Kosaraju function
int kosaraju(int V) {
    // Step 1: fill stack
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            dfs1(i);
    }

    // Step 2: reset visited
    for(int i = 0; i < V; i++)
        visited[i] = 0;

    // Step 3: process stack
    int scc_count = 0;

    while(top >= 0) {
        int v = stack[top--];

        if(!visited[v]) {
            dfs2(v);
            scc_count++;
        }
    }

    return scc_count;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for(int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("%d\n", kosaraju(V));

    return 0;
}