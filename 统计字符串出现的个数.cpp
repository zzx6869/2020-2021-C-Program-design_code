#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	string a, b;
	cin >> a;
	int l = a.size();
	getchar();
	while (getline(cin, b))
	{
		int len = b.size(), num = 0, j;
		for (int i = 0; i + 1  <= len; i++)
		{
			int k = i;
			for (j = 0; j<l; j++, k++)
			{
				if (a[j] != b[k])
				{
					break;
				}
			}
			if (j == l)
			{
				num++;
			}
		}
		cout << num << endl;
	}
}
