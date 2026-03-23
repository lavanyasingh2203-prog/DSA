#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int key) {
    
    // Base case: if tree is empty
    if (root == NULL) {
        return createNode(key);
    }

    // Insert in left subtree
    if (key < root->val) {
        root->left = insertIntoBST(root->left, key);
    }
    // Insert in right subtree
    else if (key > root->val) {
        root->right = insertIntoBST(root->right, key);
    }

    // Return unchanged root
    return root;
}