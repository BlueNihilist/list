#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list_t *lcreate(void *data)
{
    list_t *new_list = (list_t*)malloc(sizeof (list_t));
    *new_list = (struct lnode *)malloc(sizeof (struct lnode));
    (*new_list)->next = NULL;
    (*new_list)->data = data;

    return new_list;
}

void lfree(list_t *list)
{
    struct lnode *cur = *list;
    struct lnode *next;

    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }

    free(list);
}

int lpush(list_t *list, void *data)
{
    struct lnode *head;
    struct lnode *new_node;
    
    if (list == NULL || *list == NULL) {
        fprintf(stderr, "list is null\n");
        return -1;
    }

    head = *list;
    new_node = malloc(sizeof (struct lnode));
    new_node->data = data;
    new_node->next = head;
    *list = new_node;

    return 0;
}

void *lpop(list_t *list)
{
    void *popped;
    struct lnode *head = *list;

    if (list == NULL || *list == NULL) {
        return NULL;
    }
    
    popped = head->data;
    *list = head->next;

    free(head);

    return popped;
}