/*
 Program to delete first element in a linked list.
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
        // if(h) {temp = temp->next = new_node;}
        // else  {temp = h = new_node;}
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

Node *delete_first(Node *h) {
    Node *to_del;
    if (h == NULL) {
        printf(" There are no nodes in the list.");
    } else {
        to_del = h;
        h = h->next;
        printf("Deleted:  %d\n", to_del->data);
        free(to_del); // Clears the memory occupied by first node
    }
    return h;
}

int main(void) {
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    head = delete_first(head);
    printList(head);
    return 0;
}
