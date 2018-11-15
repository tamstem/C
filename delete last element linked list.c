/*
 Program to delete last element in a linked list.
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *make_list(int n) {
    Node *h = NULL, *temp;
    
    for (int i = 1; i <= n; i++) {
        Node *new_node;
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = i;
        if (h) {
            temp->next = new_node;
            temp = new_node;
        } else {
            h = new_node;
            temp = new_node;
        }
        
    }
    if (n > 0) {
        temp->next = NULL;
    }
    return h;
}

void printList(Node *h) {
    Node *temp = h;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *delete_last(Node *h) {
    Node *to_del, *prev;
    if (h == NULL) {
        printf(" There is no element in the list.");
    } else {
        to_del = h;
        prev = h;
        //Traverse to the last node of the list
        while (to_del->next != NULL) {
            prev = to_del;
            to_del = to_del->next;
        }
        if (to_del == h) {
            h = NULL;
        } else {
            // Disconnects the link of second last node with last node
            prev->next = NULL;
        }
        
        // Delete the last node
        free(to_del);
    }
    return h;
}

int main(void) {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    head = delete_last(head);
    printList(head);
    return 0;
}
