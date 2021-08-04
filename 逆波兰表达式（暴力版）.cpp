#include<iostream>
#include<string>
using namespace::std;

int i;
int main()
{
	string exp(string str, int para);

	string str, ans;
	int para = 0;

	cin >> str;
	i = str.size();
	ans = exp(str, para);
	cout << ans;

	return 0;
}

string exp(string str, int para)
{

	while (i >= 0)
	{
		i--;
		switch (str[i])
		{
		case '+':
			if (para <= 0)
			{
				return exp(str, 0) + '+' + exp(str, 1);
			}
			else
			{
				return '(' + exp(str, 0) + '+' + exp(str, 1) + ')';
			}
		case '-':
			if (para <= 0)
			{
				return exp(str, 0) + '-' + exp(str, 1);
			}
			else
			{
				return '(' + exp(str, 0) + '-' + exp(str, 1) + ')';
			}
		case '*':
			if (para <= 1)
			{
				return exp(str, 1) + '*' + exp(str, 2);
			}
			else
			{
				return '(' + exp(str, 1) + '*' + exp(str, 2) + ')';
			}
		case '/':
			if (para <= 1)
			{
				return exp(str, 1) + '/' + exp(str, 2);
			}
			else
			{
				return '(' + exp(str, 1) + '/' + exp(str, 2) + ')';
			}
		default: {
			string def;
			def.push_back(str[i]);
			return def;
		}
		}
	}
}
