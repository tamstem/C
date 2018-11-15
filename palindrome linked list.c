/*
 Program that checks if a linked list (consider only letters) is a palindrome. (Invert list and compare it to the original one)
 */


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ch;
    struct node *next;
} Node;

Node *enter_sentence() {
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

Node *invert_sentence(Node *h) {
    Node *tmp = NULL, *new_node;
    char c;
    while (h != NULL) {
        c = h->ch;
        if (isalpha(c)) { // add to new list if c is a letter
            new_node = (Node *)malloc(sizeof(Node));
            new_node->ch = tolower(c);
            new_node->next = tmp;
            tmp = new_node;
        }
        h = h->next;
    }
    return tmp;
}

int compare_lists(Node *s1, Node *s2) {
    // return -1 if s1 < s2,+1 if s1 > s2, 0 if s1 = s2
    while (s1 != NULL) {
        if (s1->ch < s2->ch)
            return -1;
        else if (s1->ch > s2->ch)
            return 1;
        s1 = s1->next;
        s2 = s2->next;
    }
    return 0;
}

int main() {
    Node *head, *s1, *s2;
    printf("Type a sentence. To stop press 'Enter': ");
    head = enter_sentence();
    s1 = invert_sentence(head);
    s2 = invert_sentence(s1);
    if (compare_lists(s1, s2) == 0)
        printf("Is a palindrome\n");
    else
        printf("Isn't a palindrome\n");
    
}
