#include <stdio.h>

#define MAX 100
#define INF 1000000000

int findTheCity(int n, int edges[][3], int m, int distanceThreshold) {
    int dist[MAX][MAX];

    // Step 1: Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Step 2: Fill edges (bidirectional)
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Step 3: Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 4: Find city with minimum reachable cities
    int resultCity = -1;
    int minCount = INF;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // Choose city with smaller count OR larger index in tie
        if (count <= minCount) {
            minCount = count;
            resultCity = i;
        }
    }

    return resultCity;
}

int main() {
    int n, m, distanceThreshold;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int edges[m][3];

    printf("Enter edges (from to weight):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Enter distance threshold: ");
    scanf("%d", &distanceThreshold);

    int result = findTheCity(n, edges, m, distanceThreshold);

    printf("City with smallest reachable cities: %d\n", result);

    return 0;
}