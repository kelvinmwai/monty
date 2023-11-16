#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number
 * Return: no return
 */
void _push(stack_t **hdouble, unsigned int nuline)
{
	int a, b;

	if (!globvar.arg)
	{
		dprintf(2, "L%u: ", nuline);
		dprintf(2, "usage: push integer\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}

	for (b = 0; globvar.arg[b] != '\0'; b++)
	{
		if (!isdigit(globvar.arg[b]) && globvar.arg[b] != '-')
		{
			dprintf(2, "L%u: ", nuline);
			dprintf(2, "usage: push integer\n");
			free_globvar();
			exit(EXIT_FAILURE);
		}
	}

	a = atoi(globvar.arg);

	if (globvar.lifo == 1)
		head_dnode(hdouble, a);
	else
		end_dnode(hdouble, a);
}

/**
 * _pall - prints all values on the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line numbers
 * Return: no return
 */
void _pall(stack_t **hdouble, unsigned int nuline)
{
	stack_t *new;
	(void)nuline;

	new = *hdouble;

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number
 * Return: no return
 */
void _pint(stack_t **hdouble, unsigned int nuline)
{
	(void)nuline;

	if (*hdouble == NULL)
	{
		dprintf(2, "L%u: ", nuline);
		dprintf(2, "can't pint, stack empty\n");
		free_globvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*hdouble)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number
 * Return: no return
 */
void _pop(stack_t **hdouble, unsigned int nuline)
{
	stack_t *new;

	if (hdouble == NULL || *hdouble == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}
	new = *hdouble;
	*hdouble = (*hdouble)->next;
	free(new);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number
 * Return: no return
 */
void _swap(stack_t **hdouble, unsigned int nuline)
{
	int n = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = *hdouble;
	*hdouble = (*hdouble)->next;
	new->next = (*hdouble)->next;
	new->prev = *hdouble;
	(*hdouble)->next = new;
	(*hdouble)->prev = NULL;
}

