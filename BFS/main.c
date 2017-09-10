/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Tue 17 Mar 2015 12:34:36 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

void BFS(int root, int **const V, int *color, int n)
{
	int i;
	int *Q;
	int head = 0;
	int tail = 0;

	Q = malloc(n * sizeof(int));

	Q[tail] = root;
	tail = (tail + 1) % n;

	color[root] = 1;
	while(tail != head){
		int start = Q[head];
		head = (head + 1) % n;

		printf("%d\n", start + 1);

		for(i = 1; i <= V[start][0]; i++){
			if(color[V[start][i]] == 0) {
				color[V[start][i]] = 1;
				Q[tail] = V[start][i];
				tail = (tail + 1) % n;
			}
		}
		color[start] = 2;
	}
	free(Q);
}

int main(int argc, char* argv[])
{
	int n, m;
	int i;
	int **V;
	int *color;

	scanf("%d %d", &n, &m);
	
	V = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++) {
		V[i] = malloc(n * sizeof(int));
		V[i][0] = 0;
	}
	
	color = calloc(sizeof(int), n);
	
	for (i = 0; i < m; i++) {
		int v1, v2;
		
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		V[v1][V[v1][0] + 1] = v2;
		V[v1][0]++;
		V[v2][V[v2][0] + 1] = v1;
		V[v2][0]++;

	}

	for (i = 0; i < n; i++) {
		if (color[i] == 0) {
			printf("\x1b[0;%dm", 31 + (i % 10));
			BFS(i, V, color, n);
		}
	}
	printf("\x1b[0;0;0m");

	for (i = 0; i < n; i++)
		free(V[i]);
	free(V);

	free(color);
}
