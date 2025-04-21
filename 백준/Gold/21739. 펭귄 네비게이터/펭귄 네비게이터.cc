#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 999999999
#define mod 1000000007
using namespace std;
long long dp[10005] = { 1 };
int n;
int main() {
	FASTIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = (dp[i] + (dp[j] * dp[i - j - 1] % mod)) % mod;
		}
	}
	cout << dp[n];
}