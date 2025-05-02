#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

int main() {
	FASTIO;
	int n, t, p;
	int size[6];
	int x = 0, y = 0, z = 0;

	cin >> n;
	for (int i = 0; i < 6; i++) cin >> size[i];
	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		x += size[i] / t + (size[i] % t ? 1 : 0);
	}
	y = n / p;
	z = n % p;
	cout << x << '\n' << y << ' ' << z;
}