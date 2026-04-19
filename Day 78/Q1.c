#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, m;
    int adj[MAX][MAX];
    int visited[MAX] = {0};

    // Input
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;  // Undirected graph
    }

    int totalWeight = 0;
    visited[1] = 1;  // Start from node 1

    // MST will have (n-1) edges
    for (int count = 1; count < n; count++) {
        int min = INF, u = -1, v = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && adj[i][j] < min) {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            visited[v] = 1;
            totalWeight += min;
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}