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
	gs->bufferSize = 1024;
	gs->buffer = malloc(gs->bufferSize);
	if (!gs->buffer)
		fprintf(stderr, "Error: malloc failed\n"), free(gs), exit(EXIT_FAILURE);
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
	gs->valueToPush = 0;
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
	FILE *montyFile;
	int res = 0;
/*Checks if user has passed 1 argument to the program*/
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
/*Opens file passed to the program*/
	montyFile = fopen(argv[1], "r");
	if (!montyFile)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	gs = initialize(argv);
/*Gets and deals with each line of the file*/
	while (fgets(gs->buffer, gs->bufferSize, montyFile))
	{
		_strtok(gs);
		if (!gs->args[0])
			continue;
		res = executeOp(gs);
		if (res == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				gs->lineNumber, gs->args[0]);
			freeall(gs), exit(EXIT_FAILURE);
		}
		nullargs(gs);
		gs->lineNumber++;
	}
	fclose(montyFile);
	freeall(gs);
	return (0);
}
