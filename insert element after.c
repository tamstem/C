/*
 Program to insert element in a linked list after some element.
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

int count_nodes(Node *h) {
    Node *temp = h;
    int n = 0;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }
    return n;
}

Node *NodeInsertAfter(Node *h, int num, int pos) {
    if (pos <= count_nodes(h)) {
        Node *new_node, *temp;
        new_node = (Node *)malloc(sizeof(Node));
        new_node->data = num;
        if (pos != 0) {
            temp = h;
            int n = 1;
            while (n != pos) {
                temp = temp->next;
                n++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        } else {
            new_node->next = h;
            h = new_node;
        }
    } else
        printf("Cannot insert!");
    return h;
}

int main(void) {
    int n, x, p;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    printf("Enter an integer to add: ");
    scanf("%d", &x);
    printf("After which node you want to add an integer? ");
    scanf("%d", &p);
    head = NodeInsertAfter(head, x, p);
    printList(head);
    return 0;
}
