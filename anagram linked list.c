/*
 Program that checks if linked lists are anagrams. (Bubble sorts both lists and compares them)
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    struct node *next;
} Node;

Node *enter_word() {
    Node *h = NULL, *tmp, *new_node;
    char c = getchar();
    while (c != '\n') {
        new_node = (Node *)malloc(sizeof(Node));
        new_node->ch = c;
        new_node->next = NULL;
        if (h == NULL)
            h = new_node;
        else
            tmp->next = new_node;
        tmp = new_node;
        c = getchar();
    }
    return h;
}

void printList(Node *h) {
    Node *temp = h;
    while (temp != NULL) {
        printf("%c  ", temp->ch);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node *node) {
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }
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
            if (tmp->ch > (tmp->next)->ch) {
                t = tmp->ch;
                tmp->ch = (tmp->next)->ch;
                (tmp->next)->ch = t;
            }
            tmp = tmp->next;
        }
    }
}

int compare_lists(Node *h1, Node *h2) {
    bubble_sort(h1);
    printList(h1);
    bubble_sort(h2);
    printList(h2);
    // return 0 if s1 < s2 or s1 > s2, and 1 if s1 = s2 anagram
    while (h1 != NULL) {
        if (h1->ch != h2->ch){
            return 0;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return 1;
}

int main() {
    Node *h1, *h2;
    printf("Enter first word: ");
    h1 = enter_word();
    printList(h1);
    printf("Enter second word: ");
    h2 = enter_word();
    printList(h2);
    
    if (compare_lists(h1,h2) == 1)
        printf("Is an anagram\n");
    else
        printf("Isn't an anagram\n");
    return 0;
}

