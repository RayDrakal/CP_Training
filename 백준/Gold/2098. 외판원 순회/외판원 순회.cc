#include <bits/stdc++.h>
#pragma warning (disable : 4996)
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define INF 0x3f3f3f3f
using namespace std;
int n, cost[16][16], d[16][1 << 16];
int dp(int cur, int sts) {
	if (sts == (1 << n) - 1) {
		if (!cost[cur][0]) return INF;
		return cost[cur][0];
	}
	int& ret = d[cur][sts];
	if (ret != -1) return ret;
	ret = INF;
	for (int next = 0; next < n; next++) {
		if (!cost[cur][next]) continue;
		if ((sts & (1 << next)) == (1 << next)) continue;
		ret = min(ret, cost[cur][next] + dp(next, sts | 1 << next));
	}
	return ret;
}
int main() {
	FASTIO;
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> cost[i][j];
	}
	cout << dp(0, 1);
}