/*
 Program to invert a linked list.
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

Node *invert(Node *h) // reverse a linked list
{
    Node *prev = NULL;
    Node *current = h;
    Node *next_node = NULL;
    
    // until all nodes have reversed
    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    h = prev;
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
int main(void) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    Node *inverted = invert(head);
    printList(inverted);
    return 0;
}
