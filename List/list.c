/*
 * In The Name Of God
 * ========================================
 * [] File Name : list.c
 *
 * [] Creation Date : 29-10-2016
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Tara Tandel.
*/
#include <stdlib.h>

#include "list.h"

struct list *list_new(void)
{
	struct list *l;

	l = malloc(sizeof(struct list));
	l->first = NULL;

	return l;
}

void list_push(struct list *l, const void *val)
{
	struct node *i = l->first;
	
	if (!i) {
		i = malloc(sizeof(struct node));
		l->first = i;
		i->next = NULL;
		i->data = val;
		return;
	}

	while (i->next != NULL) {
		i = i->next;
	}

	i->next = malloc(sizeof(struct node));
	i->next->next = NULL;
	i->next->data = val;
}

void list_reverse(struct list *l)
{
	struct node *node = l->first;
	struct node *next = NULL;
	struct node *previous = NULL;

	while (node) {
		next = node->next;
		node->next = previous;
		l->first = node;
		previous = node;
		node = next;
	}
}
