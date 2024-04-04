#include "linkedlist.h"
#include <stdlib.h>

struct Node* create_node (int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}