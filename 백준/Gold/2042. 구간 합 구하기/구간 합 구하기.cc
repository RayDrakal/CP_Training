#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, m, k;
class segment {
public:
	vector<ll> seg;
	ll n;
	segment(ll n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll update(ll node, ll left, ll right, ll target, ll val) {
		if (target < left || target > right) return seg[node];
		if (target == left && target == right) return seg[node] = val;
		ll mid = (left + right) / 2;
		return seg[node] = (update(node * 2, left, mid, target, val) +
			update(node * 2 + 1, mid + 1, right, target, val));
	}
	ll query(ll node, ll left, ll right, ll xleft, ll xright) {
		if (left > xright|| right < xleft) return 0;
		if (xleft <= left && right <= xright) return seg[node];
		ll mid = (left + right) / 2;
		return (query(node * 2, left, mid, xleft, xright) +
			query(node * 2 + 1, mid + 1, right, xleft, xright));
	}
};
int main() {
	FASTIO;
	cin >> n >> m >> k;
	segment s(n + 1);
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		s.update(1, 0, n - 1, i, a);
	}
	while (m || k) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			s.update(1, 0, n - 1, b - 1, c);
			m--;
		}
		else {
			cout << s.query(1, 0, n - 1, b - 1, c - 1) << '\n';
			k--;
		}
	}
}