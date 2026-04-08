#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
bool visited[MAX];

// DFS function to detect cycle
bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // If edge exists
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            }
            else if (i != parent) {
                return true; // Cycle found
            }
        }
    }
    return false;
}

int main() {
    int n, m, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    // Check for cycle
    bool hasCycle = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}