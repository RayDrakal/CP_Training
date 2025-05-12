#include<iostream>
#include<stack>

using namespace std;
stack<char> stk;
bool pairCheck(char toStack, char inStack) {
	if (toStack == ')' && inStack == '(') return true;
	else if (toStack == ']' && inStack == '[') return true;
	else if (toStack == '}' && inStack == '{') return true;
	else if (toStack == '>' && inStack == '<') return true;
	return false;
}
int main(int argc, char** argv)
{
	int len, test_case;
	for (test_case = 1; test_case < 11; test_case++) {
		string str;
		cin >> len >> str;
		int ans = 1;
		for (char c : str) {
			if (c == '(' || c == '{' || c == '[' || c == '<')
				stk.push(c);
			else {
				if (!pairCheck(c, stk.top())) {
					ans = 0;
					break;
				}
				stk.pop();
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
		while (!stk.empty()) {
			stk.pop();
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}