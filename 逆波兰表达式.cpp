#include <iostream>
#include <string>
int len;
using namespace std;
//为便判断优先级，为运算符号赋值

//将逆波兰式转换为中缀表达式 
string remake(string s, int order) {
	while(len--&&len>=0) {
		if (s[len] == '+') {
			if (order <= 0) {
				return remake(s, 0) + '+' + remake(s, 1);
			}
			else {
				return '(' + remake(s, 0) + '+' + remake(s, 1) + ')';
			}
		}
		else if (s[len] == '-') {
			if (order <= 0) {
				return remake(s, 0) + '-' + remake(s, 1);
			}
			else {
				return '(' + remake(s, 0) + '-' + remake(s, 1) + ')';
			}
		}
		else if (s[len] == '*') {
			if (order <= 1) {
				return remake(s, 1) + '*' + remake(s, 2);
			}
			else {
				return '(' + remake(s, 1) + '*' + remake(s, 2) + ')';
			}
		}
		else if (s[len] == '/') {
			if (order <= 1) {
				return remake(s, 1) + '/' + remake(s, 2);
			}
			else {
				return '(' + remake(s, 1) + '/' + remake(s, 2) + ')';
			}
		}
		else {
			string ss;
			ss.push_back(s[len]);
			return ss;
		}
	}
}
int main() {
	string s;
	cin >> s;
	len = s.length();
	string sss;
	sss = remake(s, 0);
	cout << sss;
	return 0;
}
