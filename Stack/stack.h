/*
 * In The Name Of God
 * ========================================
 * [] File Name : stack.h
 *
 * [] Creation Date : 25-02-2015
 *
 * [] Last Modified : Wed 25 Feb 2015 08:29:10 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef STACK_H
#define STACK_H

struct stack {
	const void *data;
	struct stack *next;
};

struct stack *stack_new(void);
void stack_push(struct stack *s, const void *val);
struct stack *stack_pop(struct stack *s);
void *stack_pick(struct stack *s);
void stack_delete(struct stack *s);

#endif
