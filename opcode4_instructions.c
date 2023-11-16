#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and the second to the top
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _rotl(stack_t **hdouble, unsigned int nuline)
{
	stack_t *new1 = NULL;
	stack_t *new2 = NULL;
	(void)nuline;

	if (*hdouble == NULL)
		return;

	if ((*hdouble)->next == NULL)
		return;

	new1 = (*hdouble)->next;
	new2 = *hdouble;

	for (; new2->next != NULL; new2 = new2->next)
		;

	new1->prev = NULL;
	new2->next = *hdouble;
	(*hdouble)->next = NULL;
	(*hdouble)->prev = new2;
	*hdouble = new1;
}

/**
 * _rotr - reverse the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number
 * Return: no return
 */
void _rotr(stack_t **hdouble, unsigned int nuline)
{
	stack_t *new = NULL;
	(void)nuline;

	if (*hdouble == NULL)
		return;

	if ((*hdouble)->next == NULL)
		return;

	new = *hdouble;

	for (; new->next != NULL; new = new->next)
		;

	new->prev->next = NULL;
	new->next = *hdouble;
	new->prev = NULL;
	(*hdouble)->prev = new;
	*hdouble = new;
}

