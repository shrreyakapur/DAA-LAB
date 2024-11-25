#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void split(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* fast;
    struct Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void merge(struct Node* a, struct Node* b, struct Node** result) {
    if (a == NULL) {
        *result = b;
        return;
    } else if (b == NULL) {
        *result = a;
        return;
    }

    if (a->data <= b->data) {
        *result = a;
        merge(a->next, b, &((*result)->next));
    } else {
        *result = b;
        merge(a, b->next, &((*result)->next));
    }
}

void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    merge(a, b, headRef);
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* res = NULL;
    struct Node* a = NULL;

    push(&a, 38);
    push(&a, 22);
    push(&a, 15);
    push(&a, 40);
    push(&a, 29);

    printf("Unsorted Linked List: ");
    printList(a);

    mergeSort(&a);

    printf("Sorted Linked List: ");
    printList(a);
    return 0;
}
