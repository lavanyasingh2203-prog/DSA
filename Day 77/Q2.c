#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

// Adjacency list
int *adj[MAX];
int size[MAX];

// Arrays
int visited[MAX];
int disc[MAX];
int low[MAX];
int time = 0;

// Store result
int bridges[MAX][2];
int bridgeCount = 0;

// Add edge
void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (size[u] + 1) * sizeof(int));
    adj[u][size[u]++] = v;
}

// DFS function
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (v == parent) continue;

        if (!visited[v]) {
            dfs(v, u);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Check for bridge
            if (low[v] > disc[u]) {
                bridges[bridgeCount][0] = u;
                bridges[bridgeCount][1] = v;
                bridgeCount++;
            }
        }
        else {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        size[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    // Run DFS from node 0
    dfs(0, -1);

    // Output bridges
    for (int i = 0; i < bridgeCount; i++) {
        printf("[%d, %d]\n", bridges[i][0], bridges[i][1]);
    }

    return 0;
}