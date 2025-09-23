#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 *                            of a doubly linked list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starting from 0)
 *
 * Return: 1 if successful, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;

    /* Case: delete the first node */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Traverse the list until the given index */
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    if (current == NULL) /* Index is out of range */
        return (-1);

    /* Re-link the previous and next nodes */
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}

