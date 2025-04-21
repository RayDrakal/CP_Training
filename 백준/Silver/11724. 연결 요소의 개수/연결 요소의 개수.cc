#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
int n, m, ans;
vector<int> vc[1001];
vector<bool> chk(1001);
void dfs(int k) {
	chk[k] = true;
	for (int i = 0; i < vc[k].size(); i++) {
		if (!chk[vc[k][i]]) dfs(vc[k][i]);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}