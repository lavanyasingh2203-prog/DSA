#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1;
int rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        front--;
    }

    dq[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    dq[rear] = x;
}

int pop_front() {
    if (empty()) return -1;

    int val = dq[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

int pop_back() {
    if (empty()) return -1;

    int val = dq[rear];

    if (front == rear)
        front = rear = -1;
    else
        rear--;

    return val;
}

int getFront() {
    if (empty()) return -1;
    return dq[front];
}

int getBack() {
    if (empty()) return -1;
    return dq[rear];
}

void printDeque() {
    if (empty()) {
        printf("Deque empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());

    printf("Pop Front: %d\n", pop_front());
    printf("Pop Back: %d\n", pop_back());

    printf("Size: %d\n", size());

    printDeque();

    return 0;
}