#include <iostream>
#include <cmath>
#define rep(i,a,b) for(int i = a; i <= b; i++)

using namespace std;

typedef long long ll;

int main()
{
	ll x1, x2, y1, y2, r1, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	ll x = abs(x1 - x2), y = abs(y1 - y2), r = (r1 + r2);
	cout << (((x * x) + (y * y)) < (r * r) ? "YES" : "NO");
}