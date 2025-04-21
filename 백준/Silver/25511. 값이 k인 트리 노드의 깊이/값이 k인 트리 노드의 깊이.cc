#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define INF 0x3f3f3f3f
using namespace std;
int n, k, x, cnt;
vector<int> v;
int find(int z, int c) {
	if (v[z] == z) return c;
	return find(v[z], c + 1);
}
int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) v.push_back(i);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[b] = a;
	}
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == k) x = i;
	}
	cout << find(x, 0);
}