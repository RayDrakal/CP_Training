#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
typedef long long ll;
int n, q;
set<int> st;
int main() {
	FASTIO;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x) st.insert(i);
	}
	int p = 1;
	for (int i = 0; i < q; i++) {
		int x, t;
		cin >> x;
		if (x == 3) {
			if (st.empty()) cout << -1 << '\n';
			else {
				if (st.lower_bound(p) != st.end()) {
					auto it = st.lower_bound(p);
					cout << *it - p << '\n';
				}
				else {
					cout << *st.lower_bound(1) + (n - p) << '\n';
				}
			}
		}
		else {
			cin >> t;
			if (x == 1) {
				if (st.count(t)) st.erase(t);
				else st.insert(t);
			}
			else {
				p = (p + t) % n;
				if (!p) p = n;
			}
		}
	}
}