#include <iostream>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int x, y;

	cin >> a >> b >> c >> d >> e >> f;
	x = (c * e - b * f) / (a * e - b * d);
	y = (c * d - a * f) / (b * d - a * e);
	cout << x << " " << y << endl;
}