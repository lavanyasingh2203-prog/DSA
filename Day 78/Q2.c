#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int *adj[MAX];
int size[MAX];

int visited[MAX], disc[MAX], low[MAX], parent[MAX];
int ap[MAX];   // articulation points marker
int time = 0;

// Add edge
void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (size[u] + 1) * sizeof(int));
    adj[u][size[u]++] = v;
}

// DFS function
void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    int children = 0;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);

            // Update low value
            if (low[v] < low[u])
                low[u] = low[v];

            // Case 1: Root node
            if (parent[u] == -1 && children > 1)
                ap[u] = 1;

            // Case 2: Non-root
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent[u]) {
            // Back edge
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        size[i] = 0;
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = 0;
    }

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    // Run DFS for all components
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    // Output articulation points
    int found = 0;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    return 0;
}