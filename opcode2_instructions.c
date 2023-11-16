#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _queue(stack_t **hdouble, unsigned int nuline)
{
	(void)hdouble;
	(void)nuline;

	globvar.lifo = 0;
}

/**
 * _stack - sets the format of the data to a stack (LIFO)
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _stack(stack_t **hdouble, unsigned int nuline)
{
	(void)hdouble;
	(void)nuline;

	globvar.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _add(stack_t **hdouble, unsigned int nuline)
{
	int p = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = (*hdouble)->next;
	new->n += (*hdouble)->n;
	_pop(hdouble, nuline);
}

/**
 * _nop - doesn't do anythinhg
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _nop(stack_t **hdouble, unsigned int nuline)
{
	(void)hdouble;
	(void)nuline;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _sub(stack_t **hdouble, unsigned int nuline)
{
	int p = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = (*hdouble)->next;
	new->n -= (*hdouble)->n;
	_pop(hdouble, nuline);
}

