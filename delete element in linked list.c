/*
 Program that deletes certain element in a linked list.
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

Node *delete_element(Node *h, int x) { //x element to delete
    Node *temp;
    Node *to_del;
    if (!h)
        return h;        // empty list, NULL
    if (h->data == x) { // if first element is x
        to_del = h;
        h = h->next;
        free(to_del);
    } else {
        temp = h;
        while (temp->next != NULL && temp->next->data != x)
            temp = temp->next;
        if (temp->next) {
            to_del = temp->next;
            temp->next = to_del->next;
            free(to_del);
        }
    }
    return h;
}

int main(void) {
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    printf("Element to delete? ");
    scanf("%d", &x);
    head = delete_element(head, x);
    printList(head);
    return 0;
}
