#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n, k;
ll chk(ll a) {
	if (a > 0) return 1;
	else if (a < 0) return -1;
	return 0;
}
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
		if (tg == l && tg == r) return seg[node] = chk(val);
		ll mid = (l + r) / 2;
		return seg[node] = (update(node * 2, l, mid, tg, val) *
			update(node * 2 + 1, mid + 1, r, tg, val));
	}
	ll qer(int node, ll l, ll r, ll xl, ll xr) {
		if (l > xr || r < xl) return 1;
		if (xl <= l && r <= xr) return seg[node];
		ll mid = (l + r) / 2;
		return (qer(node * 2, l, mid, xl, xr) *
			qer(node * 2 + 1, mid + 1, r, xl, xr));
	}
};
int main() {
	FASTIO;
	while (cin >> n >> k) {
		segment s(n + 1);
		for (int i = 0; i < n; i++) {
			ll a; cin >> a;
			s.update(1, 0, n - 1, i, a);
		}
		for (int i = 0; i < k; i++) {
			char c; ll a, b;
			cin >> c >> a >> b;
			if (c == 'C') {
				s.update(1, 0, n - 1, a - 1, b);
			}
			else {
				ll tmp = s.qer(1, 0, n - 1, a - 1, b - 1);
				if (!tmp) cout << '0';
				else if (tmp > 0) cout << '+';
				else cout << '-';
			}
		}
		cout << '\n';
	}
}