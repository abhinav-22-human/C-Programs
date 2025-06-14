#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *head) {
    struct node *ptr = head;
    if (head != NULL) {
        do {
            printf("Element is %d\n", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

struct node *insertAtFirst(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr;  
        return ptr;
    }

    struct node *p = head;
    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main() {
    struct node *head = NULL;
    struct node *sec = NULL;
    struct node *third = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    sec = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = sec;

    sec->data = 3;
    sec->next = third;

    third->data = 2;
    third->next = head;

    printf("Circular linked list before insertion:\n");
    linkedListTraversal(head);

    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 69);

    printf("After insertion, Circular linked list is:\n");
    linkedListTraversal(head);

    return 0;
}