// Wap to implement a binary tree and display its preorder, inorder and postorder traversals.

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
    struct node* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('D');
    root->left->right = createNode('C');
    root->right->left = createNode('E');
    root->right->left->left = createNode('F');

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