/*
 Program that concatenates 2 linked lists.
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

Node *concat(Node *h1, Node *h2) {
    Node *temp = h1;
    if (h1 == NULL)
        return h2;
    for (; temp->next != NULL; temp = temp->next)
        ;
    temp->next = h2;
    return h1;
}
int main(void) {
    int n1, n2;
    printf("Enter number of nodes for list 1: ");
    scanf("%d", &n1);
    Node *head1 = make_list(n1);
    printList(head1);
    printf("Enter number of nodes for list 2: ");
    scanf("%d", &n2);
    Node *head2 = make_list(n2);
    printList(head2);
    Node *head3 = concat(head1, head2);
    printList(head3);
    return 0;
}
