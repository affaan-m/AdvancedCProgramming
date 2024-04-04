#include "linkedlist.h"
#include <stdlib.h>

struct Node* create_node (int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void b_insert (struct Node** head, int data)
{
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}
void n_insert (struct Node** head, int data, int pos)
{
    if (*head == NULL) {
        b_insert(head, data);
        return;
    }

    struct Node* new_node = create_node(data);

    struct Node* temp = *head;

    for (int i = 0; i < pos - 2; ++i)
        temp = temp->next;
    
    new_node->next = temp->next;
    temp->next = new_node;
}
void e_insert (struct Node** head, int data)
{
    if (*head == NULL) {
        b_insert(head, data);
        return;
    }

    struct Node* temp = *head;

    struct Node* new_node = create_node(data);

    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_node;
}