#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	new_node->n = gs->valueToPush;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
	}
	else if (*stack)
	{
		new_node->next = *stack;
		*stack = new_node;
		new_node->next->prev = new_node;
	}
	new_node->prev = NULL;
}
/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%i\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pint(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{

}
/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void swap(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}
