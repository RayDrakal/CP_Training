#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n;
int main() {
	FASTIO;
	cin >> n;
	ll ans = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans -= ans / n;
	cout << ans;
}