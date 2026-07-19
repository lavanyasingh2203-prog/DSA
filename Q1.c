// A collage maintains a student re-evalutation request list. Each request contains SAP ID, Subjcet code, and marks obtained. Write a C program using a singly linked list to:
//1. insert a new request such that if marks are less than 20, the node is inserted at the beginning; otherwise it is inserted at the end.
//2. reject duplicate requests havinf the same SAP ID and Subject code.
//3. Display all valid requests.
//4. Display the total number of valid requests and duplicate requests rejected.
//5. Delete all requests where marks obtained are exactly 0.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Request {
    char sap_id[20];
    char subject_code[10];
    int marks;
    struct Request* next;
};

struct Request* head = NULL;
int total_valid_requests = 0;
int total_duplicate_requests = 0;

void insert_request(char* sap_id, char* subject_code, int marks) {
    
    struct Request* temp = head;

    // Check duplicate
    while (temp != NULL) {
        if (strcmp(temp->sap_id, sap_id) == 0 &&
            strcmp(temp->subject_code, subject_code) == 0) {
            total_duplicate_requests+= 1;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Request* new_request = (struct Request*)malloc(sizeof(struct Request));
    strcpy(new_request->sap_id, sap_id);
    strcpy(new_request->subject_code, subject_code);
    new_request->marks = marks;
    new_request->next = NULL;

    // Insert
    if (marks < 20) {
        new_request->next = head;
        head = new_request;
    } else {
        if (head == NULL) {
            head = new_request;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_request;
        }
    }
    total_valid_requests+= 1;
}

void display_requests() {
    struct Request* temp = head;
    while (temp != NULL) {
        printf("SAP ID: %s, Subject Code: %s, Marks: %d\n",
               temp->sap_id, temp->subject_code, temp->marks);
        temp = temp->next;
    }
}

void delete_zero_mark_requests() {
    struct Request* temp = head;
    struct Request* prev = NULL;

    while (temp != NULL) {
        if (temp->marks == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            temp = (prev == NULL) ? head : prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    char sap_id[20], subject_code[10];
    int marks;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter SAP ID, Subject Code, and Marks: ");
        scanf("%s %s %d", sap_id, subject_code, &marks);
        insert_request(sap_id, subject_code, marks);
    }

    printf("\nValid Requests:\n");
    display_requests();

    printf("\nTotal valid requests: %d\n", total_valid_requests);
    printf("Total duplicate requests rejected: %d\n", total_duplicate_requests);

    delete_zero_mark_requests();

    printf("\nRequests after deleting zero mark requests:\n");
    display_requests();

    return 0;
}




