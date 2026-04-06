#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue
int queue[MAX], front = -1, rear = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* temp = createNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = createNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

// Enqueue
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return val;
}

// BFS
void BFS(int s) {
    enqueue(s);
    visited[s] = 1;

    while (front != -1) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                enqueue(temp->data);
            }
            temp = temp->next;
        }
    }
}

// Main
int main() {
    int n, m, u, v, s;

    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Source vertex
    scanf("%d", &s);

    BFS(s);

    return 0;
}