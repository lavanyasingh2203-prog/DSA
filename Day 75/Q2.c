#include <stdio.h>
#include <stdbool.h>

#define MAX 100

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

bool isEmpty() {
    return front == -1 || front > rear;
}

bool isBipartite(int graph[MAX][MAX], int n, int colSize[]) {
    int color[MAX];

    // Initialize all nodes as uncolored (-1)
    for (int i = 0; i < n; i++)
        color[i] = -1;

    for (int start = 0; start < n; start++) {

        if (color[start] != -1)
            continue;

        // Start BFS
        front = rear = -1;
        enqueue(start);
        color[start] = 0;

        while (!isEmpty()) {
            int node = dequeue();

            for (int i = 0; i < colSize[node]; i++) {
                int neighbor = graph[node][i];

                // If not colored
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    enqueue(neighbor);
                }
                // If same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int n = 4;

    int graph[MAX][MAX] = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    int colSize[] = {3, 2, 3, 2};

    if (isBipartite(graph, n, colSize))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    return 0;
}