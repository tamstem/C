/*
 Program to insert element in the beginning of a linked list.
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

Node *NodeInsertatBegin(Node *h, int num) {
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    
    new_node->data = num; // Links the data part
    new_node->next = h;   // Links the address part
    h = new_node;          // Makes new node as first node
    return h;
}

int main(void) {
    int n, x, p;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    printf("Enter an integer: ");
    scanf("%d", &x);
    head = NodeInsertatBegin(head, x);
    printList(head);
    return 0;
}
