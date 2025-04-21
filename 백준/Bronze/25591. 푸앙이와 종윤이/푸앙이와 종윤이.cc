#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x9f9f9f9f
using namespace std;
int n, m;
int a, b, c, d, q, r;
int main() {
	FASTIO;
	cin >> n >> m;
	a = 100 - n;
	cout << a << ' ';
	b = 100 - m;
	cout << b << ' ';
	c = 100 - (a + b);
	cout << c << ' ';
	d = a * b;
	if (d > 100) c = c + d / 100;
	cout << d << ' ';
	q = d / 100;
	cout << q << ' ';
	r = d % 100;
	cout << r << '\n';
	cout << c << ' ' << r;
}