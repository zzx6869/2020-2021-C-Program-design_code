#include<stdio.h>
#include<math.h>
int main()
{
	int  M, n, t = 0, a = 0, b = 0,  i = 0;
	scanf_s("%d", &M);
	for (M; M > 0; M--)
	{
		n = M;
		for (M; i == 0;)
		{
			if ( M % 5 == 0)
			{
				a += 1;
				M /= 5;
			}
			else i = 1;
		}
		i = 0;
		M = n;
		for (M; i == 0;)
		{
			if ( M % 5 != 0 && M % 2 == 0)
			{
				b += 1;
				M /= 2;
			}
			else i = 1;
		}
		i = 0;
		M = n;
	}
	if (a >= b)
	{
		t += b;
	}
	else 
	{
		t += a;
	}
	printf("%d", t);
	return 0;
}
