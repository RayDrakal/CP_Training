#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9+7
using namespace std;
int n, m, k;
int par[4000001];
int findp(int x) {
	if (par[x] == x) return par[x];
	return findp(par[x]);
}
void unionp(int x, int y) {
	x = findp(x);
	y = findp(y);
	if (x < y) par[x] = y;
	else par[y] = x;
}
int main() {
	FASTIO;
	cin >> n >> m >> k;
	vector<int> nums;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		nums.push_back(a);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < m; i++) par[i] = i;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		int idx = lower_bound(nums.begin(), nums.end(), a + 1) - nums.begin();
		cout << nums[findp(idx)] << '\n';
		if (idx <= m - 1) unionp(findp(idx), findp(idx) + 1);
	}
}