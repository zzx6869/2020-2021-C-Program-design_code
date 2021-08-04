#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string exchange(string str, int order);
int l;
int main()
{
	string str;
	cin >> str;
	l = str.size() ;
	string new_str;
	new_str = exchange(str, 0);
	cout << new_str;
	return 0;
}
string exchange(string str, int order)
{
	while ( l-- && l >= 0)
	{
		if (str[l] == '+')
		{
			if (order <= 0)
				return exchange(str, 0) + '+' + exchange(str, 1);
			else
				return '(' + exchange(str, 0) + '+' + exchange(str, 1) + ')';
		}
		else if (str[l] == '-')
		{
			if (order <= 0)
				return exchange(str, 0) + '-' + exchange(str, 1);
			else
				return '(' + exchange(str, 0) + '-' + exchange(str, 1) + ')';
		}
		else if (str[l] == '*')
		{
			if (order <= 1)
				return exchange(str, 1) + '*' + exchange(str, 2);
			else
				return '(' + exchange(str, 1) + '*' + exchange(str, 2) + ')';
		}
		else if (str[l] == '/')
		{
			if (order <= 1)
				return exchange(str, 1) + '/' + exchange(str, 2);
			else
				return '(' + exchange(str, 1) + '/' + exchange(str, 2) + ')';
		}
		else
		{
			string s;
			s.push_back(str[l]);
			return s;
		}
	}
}
