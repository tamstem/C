/*
 Program to bubble sort a linked list.
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
void bubble_sort(Node *h) {
    Node *tmp;
    int n = 0, t;
    n = count_nodes(h);
    for (int i = 0; i < n - 1; i++) {
        tmp = h;
        for (int j = 0; j < n - i - 1; j++) {
            if (tmp->data < (tmp->next)->data) {
                t = tmp->data;
                tmp->data = (tmp->next)->data;
                (tmp->next)->data = t;
            }
            tmp = tmp->next;
        }
    }
}
int main(void) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    Node *head = make_list(n);
    printList(head);
    bubble_sort(head);
    printList(head);
    return 0;
}
