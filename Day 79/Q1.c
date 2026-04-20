#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u, w);
    node->next = adj[v];
    adj[v] = node;
}

// Min Heap structure
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

// Swap heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while(i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if(right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Check empty
int isEmpty() {
    return size == 0;
}

// Dijkstra function
void dijkstra(int n, int source) {
    int dist[MAX];

    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while(!isEmpty()) {
        HeapNode current = pop();
        int u = current.vertex;

        Node* temp = adj[u];

        while(temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}