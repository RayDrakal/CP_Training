#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x9f9f9f9f
using namespace std;
int n, x;
bool chk = false;
int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; n >= 0; i++) {
		x += i;
		n -= i;
		if (n >= 0) chk = !chk;
	}
	if (chk) cout << 0;
	else cout << -n;
}