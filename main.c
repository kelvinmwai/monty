#include "monty.h"

global_t globvar;

/**
 * free_globvar - frees the global variable
 *
 * Return: no return
 */
void free_globvar(void)
{
	free_dlist(globvar.head);
	free(globvar.buffer);
	fclose(globvar.fdr);
}

/**
 * start_globvar - function to initialize the global variables
 *
 * @fdr: file descriptor
 * Return: no return
 */
void start_globvar(FILE *fdr)
{
	globvar.lifo = 1;
	globvar.cont = 1;
	globvar.arg = NULL;
	globvar.head = NULL;
	globvar.fdr = fdr;
	globvar.buffer = NULL;
}

/**
 * check_file - checks if the file exists and can be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *fdr;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdr = fopen(argv[1], "r");

	if (fdr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fdr);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdr;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fdr = check_file(argc, argv);
	start_globvar(fdr);
	nlines = getline(&globvar.buffer, &size, fdr);
	while (nlines != -1)
	{
		lines[0] = _strtoky(globvar.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globvar.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_globvar();
				exit(EXIT_FAILURE);
			}
			globvar.arg = _strtoky(NULL, " \t\n");
			f(&globvar.head, globvar.cont);
		}
		nlines = getline(&globvar.buffer, &size, fdr);
		globvar.cont++;
	}

	free_globvar();

	return (0);
}
