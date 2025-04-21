#include <iostream>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int main()
{
	int n, g;
	int min = 5;
	string str, t;
	cin >> n;
	while (n--) {
		cin >> str >> g;
		if (min > g) {
			min = g;
			t = str;
		}
	}
	cout << t;
}