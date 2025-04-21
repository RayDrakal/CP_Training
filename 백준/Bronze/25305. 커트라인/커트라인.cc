#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
vector<int> pt;
int n, k;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	FASTIO;
	cin >> n >> k;
	while (n--) {
		int a; cin >> a;
		pt.push_back(a);
	}
	sort(pt.begin(), pt.end(), cmp);
	cout << pt[k - 1];
}