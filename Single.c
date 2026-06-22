// Write a program to implement a singly linked list with the following operations:
//1. Insert a node at the beginning & delete.
//2. Insert a node at the end & delete.
//3. Insert a node at a specific position & delete.
//4. Display the linked list.

#include <stdio.h>
#include <stdlib.h>

int main();
                                                                                                                  
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;

// Function to insert a node at the beginning

void Lavanya_insertatbeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to delete a node from the beginning

void Lavanya_deletefrombeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to insert a node at the end

void Lavanya_insertatend(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete from the end

void Lavanya_deletefromend() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to insert a node at a specific position

void Lavanya_insertatposition(int value, int pos) {
    if (pos == 1) {
        Lavanya_insertatbeginning(value);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from a specific position

void Lavanya_deletefromposition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        Lavanya_deletefrombeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to display the linked list

void Lavanya_display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Lavanya_insertatend(10);
    Lavanya_insertatend(20);
    Lavanya_insertatend(30);
    Lavanya_display();

    Lavanya_insertatbeginning(5);
    Lavanya_display();

    Lavanya_insertatposition(15, 3);
    Lavanya_display();

    Lavanya_deletefrombeginning();
    Lavanya_display();

    Lavanya_deletefromend();
    Lavanya_display();

    Lavanya_deletefromposition(2);
    Lavanya_display();

    return 0;
}