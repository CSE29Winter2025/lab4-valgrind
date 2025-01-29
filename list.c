#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void free_list(node *first) {
    node *it = first;
    while (it != NULL) {
      free(it);
      it = it->next;
    }
}

void print_list(node *first) {
    printf("{");
    for (node *it = first; it != NULL; it = it->next) {
        if (it != first) printf(",");
        printf("%d", it->data);
    }
    printf("}\n");
}

node *create_29_list(void) {
    node *first = malloc(sizeof(node));
    node *second = malloc(sizeof(node));

    first->data = 2;
    second->data = 9;
    first->next = second;
    second->next = NULL;

    return first;
}

int main(void) {
    node *ourlist = create_29_list();
    print_list(ourlist);
    ourlist = NULL;
}
