#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
using namespace std;
int n, k, l, ans;
vector<int> vip;
int main() {
	FASTIO;
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
		bool chk = false;
		int a, b, c;
		cin >> a >> b >> c;
		if (a < l || b < l || c < l) chk = true;
		if (a + b + c < k) chk = true;
		if (!chk) {
			ans++;
			vip.push_back(a);
			vip.push_back(b);
			vip.push_back(c);
		}
	}
	cout << ans << '\n';
	for (auto x : vip) cout << x << ' ';
}