#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];     // Adjacency matrix
int visited[MAX];      // Visited array
int n, m;

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int u, v;

    // Input
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    // Start DFS from node 1
    dfs(1);

    // Check if all nodes are visited
    int connected = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}