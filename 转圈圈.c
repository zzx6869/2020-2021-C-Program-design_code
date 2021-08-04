#include<stdio.h>
char name[100000][11];
int q[100000], w[100000], x[100000],y[100000];
int main()
{
	
	int i, f=5, N, M, d=5, p=5, Q = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%d%s", &x[i],name[i]);
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &d, &p);
		q[i] = d;
		w[i] = p;
	}
	for (i = 0; i < N; i++)
	{
		if ((f == 0 && d == 1) || (f == 1 && d == 0))
			Q = Q + p;
		else
			Q = Q - p;
		if (Q < 0)
			Q = Q + N;
		if (Q > N)
			Q = Q - N;
	}
	printf("%s", name[Q]);
	return 0;
}
