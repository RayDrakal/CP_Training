#include <iostream>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int main()
{
	int n;
	int a, b;
	cin >> n;
	a = n * 0.78;
	b = (n * 0.8) + ((n * 0.2) * 0.78);
	cout << a << " " << b;
}