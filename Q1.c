// Enqueue, dequeue and display using arrays [static memory allocation].

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int queue[MAX];
int rear = -1;
int front = -1;

//ENQUEUE
void enqueue(int value)
{
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = rear + 1;

    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

//DEQUEUE
void dequeue()
{
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front = front + 1;

    if (front > rear)
        front = rear = -1;
}

//DISPLAY
void display()
{
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    display();
    return 0;
}