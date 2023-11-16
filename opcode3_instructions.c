#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _div(stack_t **hdouble, unsigned int nuline)
{
	int p = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	if ((*hdouble)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = (*hdouble)->next;
	new->n /= (*hdouble)->n;
	_pop(hdouble, nuline);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _mul(stack_t **hdouble, unsigned int nuline)
{
	int p = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = (*hdouble)->next;
	new->n *= (*hdouble)->n;
	_pop(hdouble, nuline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _mod(stack_t **hdouble, unsigned int nuline)
{
	int p = 0;
	stack_t *new = NULL;

	new = *hdouble;

	for (; new != NULL; new = new->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	if ((*hdouble)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}

	new = (*hdouble)->next;
	new->n %= (*hdouble)->n;
	_pop(hdouble, nuline);
}
/**
 * _pchar - print the char value of the first element
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _pchar(stack_t **hdouble, unsigned int nuline)
{
	if (hdouble == NULL || *hdouble == NULL)
	{
		dprintf(2, "L%u: can't prchar, stack empty\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}
	if ((*hdouble)->n < 0 || (*hdouble)->n >= 128)
	{
		dprintf(2, "L%u: can't prchar, value out of range\n", nuline);
		free_globvar();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*hdouble)->n);
}

/**
 * _pstr - prints the string of the stack
 *
 * @hdouble: head of the linked list
 * @nuline: line number;
 * Return: no return
 */
void _pstr(stack_t **hdouble, unsigned int nuline)
{
	stack_t *new;
	(void)nuline;

	new = *hdouble;

	while (new && new->n > 0 && new->n < 128)
	{
		printf("%c", new->n);
		new = new->next;
	}

	printf("\n");
}

