#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteList(struct Node** head) {
    if (*head == NULL) return;
    deleteList(&(*head)->next);
    free(*head);
    *head = NULL;
}

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;

    deleteList(&head);
    if (head == NULL) {
        printf("Linked list deleted successfully.\n");
    }
    return 0;
}
