#include <stdio.h>
#include <stdlib.h>

// Define Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Right View Logic using BFS
void printRightView(struct Node* root, int n) {
    if (!root) return;

    struct Node* queue[n]; 
    int head = 0, tail = 0;

    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head; 

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];

            // If it's the last node of the current level
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || arr[0] == -1) return 0;

    // Build Tree from level-order array
    struct Node* root = newNode(arr[0]);
    struct Node* treeQueue[n];
    int head = 0, tail = 0;
    treeQueue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = treeQueue[head++];

        // Left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) treeQueue[tail++] = curr->left;
        }
        // Right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) treeQueue[tail++] = curr->right;
        }
    }

    printRightView(root, n);
    return 0;
}
