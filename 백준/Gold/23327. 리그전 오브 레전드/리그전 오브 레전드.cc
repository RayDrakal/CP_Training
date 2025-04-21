#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
typedef long long ll;
int n, q;
ll ns, sns;
vector<ll> arr, sarr;
int main() {
	FASTIO;
	cin >> n >> q;
	arr.push_back(0);
	sarr.push_back(0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ns += a;
		sns += (a * a);
		arr.push_back(ns);
		sarr.push_back(sns);
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		ll x = arr[b] - arr[a - 1], y = sarr[b] - sarr[a - 1];
		cout << ((x * x) - y) / 2 << '\n';
	}
}