#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int stack[MAX], top = -1;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }

    push(node); // push after visiting all neighbors
}

int main() {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    // Print topological order
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}