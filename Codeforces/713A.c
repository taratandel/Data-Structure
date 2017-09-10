/*
 * In The Name Of God
 * ========================================
 * [] File Name : 713A.c
 *
 * [] Creation Date : 27-10-2016
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Tara Tandel.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i;
	int t;
	int c[1 << 19];

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		char op[2];
		char x[255];

		scanf("%s %s", op, x);

		int n = 0;
		int j = 0;

		for (j = 0; j < strlen(x); j++) {
			if (x[j] % 2 == 1) {
				n = (n << 1) + 1;
			} else {
				n = (n << 1);
			}
		}


		if (*op == '+') {
			c[n]++;
		} else if (*op == '-') {
			c[n]--;
		} else {
			printf("%d\n", c[n]);
		}
	}
}
