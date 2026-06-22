//Write a program to implement a circular linked list with the following operations:
//1. Insert a node at the beginning & delete.
//2. Insert a node at the end & delete.
//3. Insert a node at a specific position & delete.
//4. Display the linked list.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself to make it circular
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Update the last node's next to new node
        newNode->next = head; // Point new node to head
        head = newNode; // Update head to new node
    }
    printf("Inserted %d at the beginning\n", value);
}
// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next; // Update last node's next to second node
        head = head->next; // Update head to second node
    }
    printf("Deleted %d from the beginning\n", temp->data);
    free(temp);
}
// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Point to itself to make it circular
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Update the last node's next to new node
        newNode->next = head; // Point new node to head
    }
    printf("Inserted %d at the end\n", value);
}
// Function to delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node in the list
        head = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head; // Update second last node's next to head
    }
    printf("Deleted %d from the end\n", temp->data);
    free(temp);
}
// Function to insert a node at a specific position
void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next; // Point new node to the next node
    temp->next = newNode; // Update previous node's next to new node
    printf("Inserted %d at position %d\n", value, position);
}
// Function to delete a node from a specific position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds\n");
            return;
        }
    }
    prev->next = temp->next; // Update previous node's next to skip the deleted node
    printf("Deleted %d from position %d\n", temp->data, position);
    free(temp);
}
// Function to display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    deleteFromBeginning();
    display();
    insertAtBeginning(5);
    display();
    deleteFromEnd();
    display();
    insertAtPosition(15, 2);
    display();
    deleteFromPosition(2);
    display();
    return 0;
}