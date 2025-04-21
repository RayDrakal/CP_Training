#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using namespace std;
long long N;
int func(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum++;
	return sum;
}
int main() {
	FASTIO;
	cin >> N;
	cout << (N * (N-1))/2 << '\n';
	if (!N) cout << 4;
	else cout << 2;
}