#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k;
class segment {
public:
	vector<ll> seg;
	int n;
	segment(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll update(int node, ll l, ll r, ll tg, ll val) {
		if (tg<l || tg>r) return seg[node];
		if (tg == l && tg == r) return seg[node] = val;
		ll mid = (l + r) / 2;
		return seg[node] = max(update(node * 2, l, mid, tg, val),
			update(node * 2 + 1, mid + 1, r, tg, val));
	}
	ll qer(int node, ll l, ll r, ll xl, ll xr) {
		if (l > xr || r < xl) return 0;
		if (xl <= l && r <= xr) return seg[node];
		ll mid = (l + r) / 2;
		return max(qer(node * 2, l, mid, xl, xr),
			qer(node * 2 + 1, mid + 1, r, xl, xr));
	}
};
int main() {
	FASTIO;
	cin >> n >> k;
	segment s(n + 1);
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		s.update(1, 1, n, i, a);
	}
	for (int i = k; i <= n - k + 1; i++) {
		cout << s.qer(1, 1, n, i - (k - 1), i + (k - 1)) << ' ';
	}
}