#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll ans;
vector<int> v;
int n;
ll power(ll a, ll b) {
	ll ret;
	if (b == 0) return 1;
	if (b == 1) return a;
	ret = power(a, b / 2);
	ret = ret * ret;
	ret %= MOD;
	if (b % 2) ret *= a;
	return ret % MOD;
}
int main() {
	FASTIO;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));
	for (int i = 0; i < n; i++) {
		ans += v[i] * (power(2, i) + MOD - power(2, (ll)n - i - 1)) % MOD;
		ans %= MOD;
	}
	cout << ans;
}