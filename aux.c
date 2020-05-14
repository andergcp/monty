#include "monty.h"
/**
 * _strtok - Tokenizes the line in buffer
 * @gs: General struct of the program
 */
void _strtok(gralStruct *gs)
{
	int counter = 0;
	char *tmp;
/*Tokenizes the buffer*/
	tmp = strtok(gs->buffer, " \n");
	while (tmp && counter < 2)
	{
		gs->args[counter] = tmp;
		tmp = strtok(NULL, " \n");
		counter++;
	}
	gs->args[counter] = NULL;
	return (0);
}
/**
 * executeOp - Looks for the opcode function and if it's found execute it
 * @gs: General struct of the program
 * Return: When success 1, if fails 0
 */
int executeOp(gralStruct *gs)
{
	int counter = 0;

	while (gs->dicciop[counter].opcode)
	{
		if (strcmp(gs->args[0], gs->dicciop[counter].opcode) == 0)
		{
			if (strcmp(gs->args[0], "push") == 0)
				checkNum(gs);
			gs->dicciop[counter].f(&(gs->stack), gs->lineNumber);
			return (1);
		}
		counter++;
	}
	return (0);
}
/**
 * dic_op - Creates an array of paires opcode-function
 * Return: A pointer to the array crated
 */
instruction_t *dic_op()
{
	instruction_t *arrayOp = malloc(sizeof(instruction_t) * 16);

	if (arrayOp)
	{
		arrayOp[0].opcode = "push";
		arrayOp[0].f = push;
		arrayOp[1].opcode = "pall";
		arrayOp[1].f = pall;
		arrayOp[2].opcode = "pint";
		arrayOp[2].f = pint;
		arrayOp[3].opcode = "pop";
		arrayOp[3].f = pop;
		arrayOp[4].opcode = "swap";
		arrayOp[4].f = swap;
		arrayOp[5].opcode = "add";
		arrayOp[5].f = add;
		arrayOp[6].opcode = "nop";
		arrayOp[6].f = nop;
		arrayOp[7].opcode = "sub";
		arrayOp[7].f = sub;
		arrayOp[8].opcode = "div";
		arrayOp[8].f = div_s;
		arrayOp[9].opcode = "mul";
		arrayOp[9].f = mul;
		arrayOp[10].opcode = "mod";
		arrayOp[10].f = mod;
		arrayOp[11].opcode = "pchar";
		arrayOp[11].f = pchar;
		arrayOp[12].opcode = "pstr";
		arrayOp[12].f = pstr;
		arrayOp[13].opcode = "rotl";
		arrayOp[13].f = rotl;
		arrayOp[14].opcode = "rotr";
		arrayOp[14].f = rotr;
		arrayOp[15].opcode = NULL;
		arrayOp[15].f = NULL;
		return (arrayOp);
	}
	return (NULL);
}
/**
 * checkNum - Check if the argument passed to push is valid
 * @gs: General struct of the program
 */
void checkNum(gralStruct *gs)
{
	int counter = 0;

	if (!gs->args[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", gs->lineNumber);
		freeall(gs), exit(EXIT_FAILURE);
	}
	if (gs->args[1][0] == '-')
		counter++;
	while (gs->args[1][counter])
	{
		if (!isdigit(gs->args[1][counter]))
		{
			fprintf(stderr, "L%i: usage: push integer\n", gs->lineNumber);
			freeall(gs), exit(EXIT_FAILURE);
		}
		counter++;
	}
	gs->valueToPush = atoi(gs->args[1]);
}
/**
 * freeall - Free all memory allocated in the program
 * @gs: General struct of the program
 */
void freeall(gralStruct *gs)
{
	free(gs->buffer);
	free(gs->args);
	free(gs->dicciop);
	freestack(gs);
	free(gs);
}
