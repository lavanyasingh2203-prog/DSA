#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search for the root index in the Inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* root = newNode(preorder[(*preIndex)++]);

    // If this node has no children, return
    if (inStart == inEnd) return root;

    // Find the index of this node in Inorder traversal
    int inIndex = search(inorder, inStart, inEnd, root->data);

    // Using index in Inorder, construct left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Print Postorder traversal (Left, Right, Root)
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    return 0;
}
