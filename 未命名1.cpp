#include <iostream>
#include <string>
#include <stack>
#include <map> 
using namespace std;

void initial_map(map<char, int> &priority) {
	priority['*'] = 2;
	priority['/'] = 2;
	priority['%'] = 2;
	priority['+'] = 1;
	priority['-'] = 1;
	return ;
}
void changePostfix(string &s) {
	map<char, int> priority;
	initial_map(priority);
	string temp /*= "" */;
	stack<char> cha;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'z') temp+= s[i];
		else {
			while (!cha.empty() && priority[cha.top()] >= priority[s[i]]) {
				temp= temp + cha.top();
				cha.pop();
			}
			cha.push(s[i]);
		}
	}
	while (!cha.empty()) {
		temp= temp + cha.top();
		cha.pop();
	}
	s = temp;
	return ;
}

int main() {
	string s;
	cin >> s;
	changePostfix(s);
	cout << s;
}
