#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

void print(int val) {
	if (val % 3 == 0 && val % 5 == 0) cout << "FizzBuzz\n";
	else if (val % 3 == 0) cout << "Fizz\n";
	else if (val % 5 == 0) cout << "Buzz\n";
	else cout << val << '\n';
}

int main() {
	FASTIO;
	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	if (str3 != "FizzBuzz" && str3 != "Fizz" && str3 != "Buzz")
		print(stoi(str3) + 1);
	else if (str2 != "FizzBuzz" && str2 != "Fizz" && str2 != "Buzz")
		print(stoi(str2) + 2);
	else print(stoi(str1) + 3);
}