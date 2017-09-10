/*
 * In The Name Of God
 * ========================================
 * [] File Name : stack.c
 *
 * [] Creation Date : 25-02-2015
 *
 * [] Last Modified : Wed 25 Feb 2015 08:28:57 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>

#include "stack.h"

struct stack *stack_new(void)
{
	struct stack *s;

	s = malloc(sizeof(struct stack));
	s->data = NULL;
	s->next = NULL;
	return s;
}

void stack_push(struct stack *s, const void *val)
{
	struct stack *new;
	
	new = malloc(sizeof(struct stack));
	new->data = NULL;
	new->next = NULL;

	while (s->next)
		s = s->next;
	s->data = val;
	s->next = new;
}

void *stack_pick(struct stack *s)
{
	return (void *) s->data;
}

struct stack *stack_pop(struct stack *s)
{
	struct stack *old;
	
	old = s->next;
	free(s);
	return old;
}

void stack_delete(struct stack *s)
{
	struct stack *old;

	while (s->next) {
		old = s->next;
		free(s);
		s = old;
	}
	free(s);
}
