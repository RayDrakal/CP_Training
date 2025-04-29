#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
int n;
int ino[100001], poo[100001], idx[100001];
void preo(int ib, int ie, int pb, int pe) {
	if (ib > ie || pb > pe) return;
	int rtt = poo[pe];
	cout << poo[pe] << ' ';
	preo(ib, idx[rtt] - 1, pb, pb + (idx[rtt] - ib) - 1);
	preo(idx[rtt] + 1, ie, pb + (idx[rtt] - ib), pe - 1);
}
int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ino[i];
	for (int i = 0; i < n; i++) cin >> poo[i];
	for (int i = 0; i < n; i++) idx[ino[i]] = i;
	preo(0, n - 1, 0, n - 1);
}