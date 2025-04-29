#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1000000009
using namespace std;
int n, k, cnt, mct[101], arr[101], chk[101];
int ans;
int main() {
	FASTIO;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		mct[arr[i]]++;
	}
	for (int i = 0; i < k; i++) {
		if (chk[arr[i]]) mct[arr[i]]--;
		else {
			if (cnt < n) {
				chk[arr[i]] = 1;
				mct[arr[i]]--;
				cnt++;
			}
			else {
				int p = 0, last[101] = { 0 }, tmp = 0;
				for (int j = 0; j < i; j++) {
					if (chk[arr[j]]) if (mct[arr[j]] == 0)
						p = arr[j];
				}
				if (p == 0) {
					for (int j = i + 1; j < k; j++) {
						if (chk[arr[j]] && !last[arr[j]]) last[arr[j]] = j;
					}
					for (int j = 0; j < k; j++) {
						if (last[arr[j]]) tmp = max(tmp, last[arr[j]]);
					}
					p = arr[tmp];
				}
				chk[p] = 0;
				ans++;
				chk[arr[i]] = 1;
				mct[arr[i]]--;
			}
		}
	}
	cout << ans;
}