#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int n) {
    int i, j, count = 0;
    
    // Initialize indegree
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    // Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Enqueue nodes with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (j = 0; j < n; j++) {
            if (adj[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n);

    return 0;
}