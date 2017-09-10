/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 29-10-2016
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Tara Tandel.
*/
#include <stdio.h>
#include <string.h>

#include "list.h"

int main(int argc, char *argv[])
{
	int i = 0;
	struct list *l;
	struct node *n;
	char *s = "Hello";

	l = list_new();

	for (i = 0; i < strlen(s); i++)
		list_push(l, s + i);

	n = l->first;
	while (n) {
		printf("%c\n", *((char *)n->data));
		n = n->next;
	}

	list_reverse(l);

	n = l->first;
	while (n) {
		printf("%c\n", *((char *)n->data));
		n = n->next;
	}
}
