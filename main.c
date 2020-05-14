#include "monty.h"

gralStruct *gs;

/**
 * initialize - Asign initial values to the elements of the general struct
 * @argv: Double pointer to arguments passed to the program
 * Return: a pointer to the initial gral Struct
 */
gralStruct *initialize(char **argv)
{
	gs = malloc(sizeof(gralStruct));
	if (!gs)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	gs->bufferSize = 0;
	gs->buffer = NULL;
	gs->args = malloc(sizeof(char *) * 3);
	if (!gs->args)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(gs->buffer), free(gs), exit(EXIT_FAILURE);
	}
	gs->argv = argv;
	gs->dicciop = dic_op();
	if (!gs->dicciop)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(gs->args), free(gs->buffer), free(gs), exit(EXIT_FAILURE);
	}
	gs->stack = NULL;
	gs->lineNumber = 1;
	gs->montyFile = NULL;
	return (gs);
}
/**
 * main - Main process of the program
 * @argc: Quantity of arguments passed to the program
 * @argv: Array of pointer to arguments passed to the program
 * Return: Ever 1.
 */
int main(int argc, char **argv)
{
	int res = 0;
/*Checks if user has passed 1 argument to the program*/
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
/*Initializes general struct of the program*/
	gs = initialize(argv);
/*Opens file passed to the program*/
	gs->montyFile = fopen(argv[1], "r");
	if (!gs->montyFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
/*Gets and deals with each line of the file*/
	while (getline(&gs->buffer, &gs->bufferSize, gs->montyFile) != EOF)
	{
		_strtok(gs);
		if (!gs->args[0])
			continue;
		res = executeOp(gs);
		if (isComment(gs) == 1)
		{
			nullargs(gs);
			gs->lineNumber++;
			continue;
		}
		if (res == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				gs->lineNumber, gs->args[0]);
			freeall(gs), exit(EXIT_FAILURE);
		}
		nullargs(gs);
		gs->lineNumber++;
	}
	freeall(gs);
	return (0);
}
