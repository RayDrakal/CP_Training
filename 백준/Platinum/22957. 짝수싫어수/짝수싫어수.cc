#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
typedef long long ll;
ll n, k, dp[31][8];
int arr[3] = { 3,5,7 };
int pp(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i++) ret *= a;
	return ret;
}
void fuc(int cur, ll r, int pre) {
	if (cur == 0) return;
	for (int i = 2; i >= 0; i--) {
		ll cnt = 0;
		for (int j = 0; j < 8; j++) if (pre ^ j ^ pp(2, i)) cnt += dp[cur - 1][j];
		if (cnt >= r) {
			cout << arr[i];
			return fuc(cur - 1, r, pre ^ pp(2, i));
		}
		r -= cnt;
	}
	fuc(cur - 1, r, pre);
}
int main() {
	FASTIO;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 3; k++) dp[i][j ^ pp(2, k)] += dp[i - 1][j];
		}
	}
	fuc(n, k, 0);
}