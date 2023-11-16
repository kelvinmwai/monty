#include "monty.h"

/**
 * get_opcode - selects the correct operator code
 *
 * @opr: operator code passed
 *
 * Return: pointer to the function that executes the code
 */
void (*get_opcode(char *opr))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int j;

	for (j = 0; instruct[j].opcode; j++)
	{
		if (_strcmp(instruct[j].opcode, opr) == 0)
			break;
	}

	return (instruct[j].f);
}
