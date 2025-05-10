#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
typedef long long ll;
int T, n, k, w, bt[1001], bc[1001], bd[1001], ans;
int main() {
	FASTIO;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		memset(bt, 0, sizeof(bt));
		memset(bc, 0, sizeof(bc));
		memset(bd, 0, sizeof(bd));
		vector<int> v[1001];
		for (int i = 1; i <= n; i++) cin >> bt[i];
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			bc[y]++;
			v[x].push_back(y);
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!bc[i]) q.push(i);
			bd[i] += bt[i];
		}
		for (int i = 1; i <= n; i++) {
			int x = q.front();
			q.pop();
			for (auto nx : v[x]) {
				bd[nx] = max(bd[nx], bd[x] + bt[nx]);
				if (--bc[nx] == 0) q.push(nx);
			}
		}
		cin >> w;
		cout << bd[w] << '\n';
	}
}