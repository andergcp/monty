#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void add(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = tmp->n + tmp->next->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
/**
 * nop - doesn’t do anything.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void nop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file*
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = tmp->n - tmp->next->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
/**
 * div_s - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void div_s(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	result = tmp->next->n / tmp->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = tmp->n * tmp->next->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
