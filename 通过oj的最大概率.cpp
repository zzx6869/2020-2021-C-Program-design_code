#include<iostream>
#include<cstdio>
using namespace std;
int num[105], Max[105];
int main()
{
	int i = 1;
	while (scanf("%d", &num[i++]) != EOF)
	{
	}
	Max[1] = num[1];
	if (num[2] > num[1])
		Max[2] = num[2];
	else
		Max[2] = num[1];
	for (int k = 3; k < i; k++)
	{
		if (Max[k - 2] + num[k] > Max[k - 1])
			Max[k] = Max[k - 2] + num[k];
		else
			Max[k] = Max[k - 1];
	}
	cout << Max[i - 1];
	return 0;
}
