#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
} Node;

// Array to store cloned nodes
Node* visited[MAX];

// Function to create new node
Node* createNode(int val, int size) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->numNeighbors = size;
    node->neighbors = (Node**)malloc(size * sizeof(Node*));
    return node;
}

// DFS function to clone graph
Node* cloneGraph(Node* node) {
    if (node == NULL)
        return NULL;

    // If already cloned
    if (visited[node->val] != NULL)
        return visited[node->val];

    // Create clone node
    Node* clone = createNode(node->val, node->numNeighbors);
    visited[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}