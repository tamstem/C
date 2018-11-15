/*
 Program to search a linked list.
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

int search(Node *h, int x) {
    Node *temp = h; // Initialize temp
    while (temp != NULL) {
        if (temp->data == x)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main(void) {
    int n,x;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    Node *head = make_list(n);
    printList(head);
    printf("Number we search for: ");
    scanf("%d", &x);
    search(head, x) ? printf("Is in a list!"):printf("Is not in a list!");
    return 0;
}

