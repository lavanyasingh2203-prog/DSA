//write a c program to implement a stack data structure using linked list. The program should support the following operations:

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50     // Define the maximum capacity of the stack

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;    // Global variables to track the stack 
int current_size = 0;

void push(int value);
int pop();
int peek();
void display();
int isFull();
int isEmpty();

int main() {
    int choice, value;

    printf("--- Stack Linked List Implementation (Max Size: %d) ---\n", MAX_SIZE);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1) printf("Top element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

int isFull() {
    return current_size >= MAX_SIZE;
}

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
    current_size++;
    printf("%d pushed to stack.\n", value);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }

    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    current_size--;
    return poppedValue;
}

// Look at the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

