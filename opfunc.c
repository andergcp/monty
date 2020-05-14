#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	checkNum(gs);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(gs->args[1]);
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
	}
	else
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
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%i\n", gs->stack->n);
	else
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		if (tmp->next)
			tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
	}
	else
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}

}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (!*stack || !gs->stack->next)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp2 = tmp->next;
	tmp->next->prev = NULL;
	if (tmp->next->next)
		tmp->next->next->prev = tmp;
	tmp->next = tmp->next->next;
	tmp2->next = tmp;
	gs->stack = tmp2;
}
