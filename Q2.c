// WAP for queue in c using linked list [dynamic memory allocation].

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// ENQUEUE (Insert at rear)
void enqueue(int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {   // If queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

// DEQUEUE (Delete from front)
void dequeue()
{
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    printf("Dequeued %d\n", front->data);

    front = front->next;

    if (front == NULL)   // If queue becomes empty
        rear = NULL;

    free(temp);
}

// DISPLAY
void display()
{
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct node* temp = front;

    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    return 0;
}