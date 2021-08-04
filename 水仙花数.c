#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0, v = 0, p;
	long long M, N, n, a = 0, sum = 0, j,t;
	long long x[13] = { 0 };
	scanf_s("%lld %lld", &M, &N);
	for (M; M <= N; M++) 
	{
		t = M;
		for (i = 0; i <= 12; i++)
		{
			n = M % 10;
			x[i] = n;
			M /= 10;
		}
		M = t;
		i = 0;
		for (p = 12; v == 0; p--)
		{
			j = p;
			if (x[p] == 0) {
				v = 0;
			}
			else {
				v = 1;
			}
		}
		for (i = 0; i <= j; i++)
		{
			a = a + pow(x[i], j + 1);
		}
		if (M == a)
			sum += a;
		a = 0;	
		v = 0;
	}
	printf("%lld", sum);
	return 0;
}
