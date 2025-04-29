#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll n, m, num[1000001];
bool chk[1000001];
int main() {
	FASTIO;
	cin >> n >> m;
	ll s = (ll)sqrt(m), cnt = 0;
	for (ll i = 2; i <= s; i++) {
		num[i] = i * i;
		cnt++;
	}
	int ret = 0;
	for (int i = 2; i < cnt + 2; i++) {
		ll dv = n;
		if (dv % num[i] != 0) {
			dv = (n / num[i] + 1) * num[i];
		}
		for (ll tmp = dv; tmp <= m; tmp += num[i]) {
			if (!chk[tmp - n]) {
				chk[tmp - n] = true;
				ret++;
			}
		}
	}
	cout << m - n - ret + 1;
}