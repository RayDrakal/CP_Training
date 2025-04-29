#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9+7
using namespace std;
int n, s;
long long ans = 0;
vector<int> arr;
map<int, int> cnt;
void lsearch(int left, int right, int sum) {
	if (left == right) {
		cnt[sum]++;
		return;
	}
	lsearch(left + 1, right, sum);
	lsearch(left + 1, right, sum + arr[left]);
}
void rsearch(int left, int right, int sum) {
	if (left == right) {
		if (cnt[s - sum]) ans += cnt[s - sum];
		else if (sum == s) ans++;
		return;
	}
	rsearch(left + 1, right, sum);
	rsearch(left + 1, right, sum + arr[left]);
}
int main() {
	FASTIO;
	cin >> n >> s;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	lsearch(0, n / 2, 0);
	rsearch(n / 2, n, 0);
	if (!s) ans--;
	cout << ans;
}