#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node (handle -1 as NULL)
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Mirror the tree by swapping children recursively
void mirror(struct Node* node) {
    if (node == NULL) return;

    // Swap left and right child pointers
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recurse for children
    mirror(node->left);
    mirror(node->right);
}

// Print inorder traversal (Left, Root, Right)
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Build the tree using a queue for level-order input
    struct Node* root = newNode(arr[0]);
    struct Node* queue[n];
    int head = 0, tail = 0;
    if (root) queue[tail++] = root;

    int i = 1;
    while (head < tail && i < n) {
        struct Node* curr = queue[head++];
        
        // Build left child
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        // Build right child
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    // Transform tree into its mirror
    mirror(root);

    // Print resulting inorder traversal
    printInorder(root);
    printf("\n");

    return 0;
}
