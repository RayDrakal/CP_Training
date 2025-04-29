#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
typedef long long ll;
int n, m;
ll dp[3000][3000];
char maps[3000][3000];
bool ijchk(int i, int j) {
	return maps[i][j] == maps[i - 1][j - 1] &&
		maps[i - 1][j] != maps[i][j] &&
		maps[i][j - 1] != maps[i][j];
}
int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
		}
	}
	fill_n(&dp[0][0], 3000 * 3000, 1LL);
	ll res = (ll)n * m;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (ijchk(i,j)) {
				ll x = min({ dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1] });
				res += x;
				dp[i][j] = x + 1;
			}
				
		}
	}
	cout << res;
}