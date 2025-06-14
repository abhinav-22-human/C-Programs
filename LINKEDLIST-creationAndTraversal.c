#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void LinkedListTraversal(struct Node* ptr) {  // Corrected struct name
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    // Declare head, second, and third nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory for the nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error code
    }

    // Assign data values and link the nodes
    head->data = 11;
    head->next = second;

    second->data = 22;
    second->next = third;

    third->data = 33;
    third->next = NULL;

    // Traverse and display the linked list
    LinkedListTraversal(head);

    return 0;
}