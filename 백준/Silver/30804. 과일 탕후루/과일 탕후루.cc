#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;
int n, types, cnt[10], result;
queue<int> q;

int main() {
	FASTIO;
	cin >> n;
	while (n--) {
		int fruit;
		cin >> fruit;
		q.push(fruit);
		if (cnt[fruit]++ == 0) ++types;
		while (types > 2) {
			fruit = q.front();
			q.pop();
			if (--cnt[fruit] == 0) --types;
		}
		result = max(result, static_cast<int>(q.size()));
	}
	cout << result;
}