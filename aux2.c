#include "monty.h"
/**
 * nullargs - sets to null values of args variable
 * @gs: General struct of the program
 */
void nullargs(gralStruct *gs)
{
	gs->args[0] = NULL;
	gs->args[1] = NULL;
}

/**
 * freestack - Frees each node in stack
 * @gs: General struct of the program
 */
void freestack(gralStruct *gs)
{
	if (gs->stack)
	{
		while (gs->stack->next)
		{
			gs->stack = gs->stack->next;
			free(gs->stack->prev);
		}
		free(gs->stack);
	}
}
