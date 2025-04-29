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
		seg.resize(4 * n + 5, 0);
		this->n = n;
	}
	ll min_update(int node, ll l, ll r, ll tg, ll val) {
		if (tg<l || tg>r) return seg[node];
		if (tg == l && tg == r) return seg[node] = val;
		ll mid = (l + r) / 2;
		return seg[node] = min(min_update(node * 2, l, mid, tg, val),
			min_update(node * 2 + 1, mid + 1, r, tg, val));
	}
	ll max_update(int node, ll l, ll r, ll tg, ll val) {
		if (tg<l || tg>r) return seg[node];
		if (tg == l && tg == r) return seg[node] = val;
		ll mid = (l + r) / 2;
		return seg[node] = max(max_update(node * 2, l, mid, tg, val),
			max_update(node * 2 + 1, mid + 1, r, tg, val));
	}
	ll min_qer(int node, ll l, ll r, ll xl, ll xr) {
		if (l > xr || r < xl) return 1e9 + 1;
		if (xl <= l && r <= xr) return seg[node];
		ll mid = (l + r) / 2;
		return min(min_qer(node * 2, l, mid, xl, xr),
			min_qer(node * 2 + 1, mid + 1, r, xl, xr));
	}
	ll max_qer(int node, ll l, ll r, ll xl, ll xr) {
		if (l > xr || r < xl) return 0;
		if (xl <= l && r <= xr) return seg[node];
		ll mid = (l + r) / 2;
		return max(max_qer(node * 2, l, mid, xl, xr),
			max_qer(node * 2 + 1, mid + 1, r, xl, xr));
	}
};
int main() {
	FASTIO;
	cin >> n >> k;
	segment s(n + 1);
	segment S(n + 1);
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		s.min_update(1, 0, n - 1, i, a);
		S.max_update(1, 0, n - 1, i, a);
	}
	while (k--) {
		ll a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		a--, b--;
		cout << s.min_qer(1, 0, n - 1, a, b) << ' ' << S.max_qer(1, 0, n - 1, a, b) << '\n';
	}
}