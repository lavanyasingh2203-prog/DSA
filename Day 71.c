#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

// Initialize table
void init() {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

// Insert using quadratic probing
void insert(int key) {
    int index = key % m;

    if (table[index] == -1) {
        table[index] = key;
        return;
    }

    for (int i = 1; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }
}

// Search using quadratic probing
void search(int key) {
    int index = key % m;

    if (table[index] == key) {
        printf("FOUND\n");
        return;
    }

    for (int i = 1; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == -1) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int n;
    scanf("%d", &m);   // table size
    scanf("%d", &n);   // number of operations

    init();

    while (n--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}