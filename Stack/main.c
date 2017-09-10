/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 25-02-2015
 *
 * [] Last Modified : Wed 25 Feb 2015 08:27:31 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "stack.h"

int main(int argc, char *argv[])
{
	int i = 0;
	struct stack *s;
	
	s = stack_new();
	
	for (i = 0; i < 10; i++)
		stack_push(s, &i);
	
	for (i = 0; i < 10; i++) {
		printf("%d\n", *(int *)stack_pick(s));
		s = stack_pop(s);
	}

	stack_delete(s);
}
