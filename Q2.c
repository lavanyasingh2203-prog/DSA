// A Text Editor stores user actions such as type, delete, copy, paste. Write a C program using a stack to:
// 1. Push a new action onto the stack.
// 2. If the entered action is "undo" , remove the most recent action instead of storing "undo".
// 3. If the same action is entered twice, store it only once.
// 4. Display all the actions currently present in the stack.
// 5. Display the total number od stored actions and the topmost action.

#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX][20];
int top = -1;

// Function to check duplicate
int isDuplicate(char action[]) {
    for (int i = 0; i <= top; i++) {
        if (strcmp(stack[i], action) == 0) {
            return 1; // duplicate found
        }
    }
    return 0;
}

int main() {
    int n;
    char action[20];

    printf("Enter number of actions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter action: ");
        scanf("%s", action);

        // 1 & 2: Check for undo
        if (strcmp(action, "undo") == 0) {
            if (top >= 0) {
                top--;  // pop
            } else {
                printf("Nothing to undo!\n");
            }
        }

        // 3: Check duplicate
        else if (isDuplicate(action)) {
            printf("Duplicate action ignored!\n");
        }

        // 1: Push action
        else {
            if (top < MAX - 1) {
                top++;
                strcpy(stack[top], action);
            } else {
                printf("Stack Overflow!\n");
            }
        }
    }

    // 4: Display stack
    printf("\nActions in stack:\n");
    for (int i = 0; i <= top; i++) {
        printf("%s\n", stack[i]);
    }

    // 5: Total and top
    printf("\nTotal actions: %d\n", top + 1);

    if (top >= 0) {
        printf("Topmost action: %s\n", stack[top]);
    } else {
        printf("Stack is empty\n");
    }

    return 0;
}