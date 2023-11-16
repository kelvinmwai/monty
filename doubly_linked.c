#include "monty.h"

/**
 *end_dnode - add node to the end of the doubly link list
 *@head: pointer to first node of linked list
 *@n: data element to add
 *Return: a doubly linked list
 */
stack_t *end_dnode(stack_t **head, const int n)
{
	stack_t *temp, *new;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	new = *head;
	while (new->next)
		new = new->next;
	temp->next = new->next;
	temp->prev = new;
	new->next = temp;
	return (new->next);
}

/**
 *head_dnode - add new node to the head of the doubly link list
 *@head: first node of linked list
 *@n: data element to add
 *Return: a doubly linked list
 */
stack_t *head_dnode(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlist - frees the doubly linked list
 *
 * @head: head node of the linked list
 * Return: no return
 */
void free_dlist(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
