#include "monty.h"
/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	result = tmp->next->n % tmp->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	if (isascii(gs->stack->n) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	putchar(gs->stack->n);
	puts("");
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		puts("");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		if (!isascii(tmp->n) || tmp->n == 0)
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (*stack && gs->stack->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp->next->prev = NULL;
		*stack = tmp->next;
		tmp->prev = tmp2;
		tmp->next = NULL;
		tmp2->next = tmp;
	}
}
/**
 * rotr - rotates the stack to the bottom.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void rotr(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (*stack && gs->stack->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->prev->next = NULL;
		tmp2->prev = NULL;
		tmp2->next = tmp;
		tmp->prev = tmp2;
		*stack = tmp2;
	}
}
