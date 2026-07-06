// WAP to implement a binary search tree and display its preorder, inorder and postorder traversals.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

   if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return newNode;
    }
    newNode->data = data;
    newNode-> left = NULL;
    newNode->right = NULL;
    return newNode;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);

    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root-> data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root -> right);
}

void postorder(struct node* root){
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root -> right);
    printf("%d ", root -> data);

}

int main () {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

