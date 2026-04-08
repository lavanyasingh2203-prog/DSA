#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];

// DFS function
bool dfs(int node, int n) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, n))
                    return true;
            }
            else if (recStack[i]) {
                return true; // Cycle detected
            }
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

int main() {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed edge
    }

    // Check cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}