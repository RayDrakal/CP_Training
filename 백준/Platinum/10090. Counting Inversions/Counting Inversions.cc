#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, res;
vector<ll> tree;
ll upd(int node, ll st, ll ed, ll idx) {
	if (idx<st || idx>ed) return tree[node];
	if (st == ed) return tree[node] += 1;
	ll mid = (st + ed) / 2;
	return tree[node] = upd(node * 2, st, mid, idx) 
		+ upd(node * 2 + 1, mid + 1, ed, idx);
}
ll qer(int node, ll st, ll ed, ll xl, ll xr) {
	if (ed<xl || xr<st) return 0;
	if (xl <= st && ed <= xr) return tree[node];
	ll mid = (st + ed) / 2;
	return qer(node * 2, st, mid, xl, xr) + qer(node * 2 + 1, mid + 1, ed, xl, xr);
}
int main() {
	FASTIO;
	cin >> n;
	tree.resize(4 * n + 5);
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		res += (a - 1 - qer(1, 1, n, 1, a - 1));
		upd(1, 1, n, a);
	}
	cout << res;
}