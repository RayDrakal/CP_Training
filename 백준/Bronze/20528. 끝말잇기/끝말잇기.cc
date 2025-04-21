#include <bits/stdc++.h>
#pragma warning (disable:4996)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1987654321
using namespace std;
int n;
string s[100];
bool chk;
int main() {
	FASTIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i < n; i++) {
		if (s[i - 1][s[i - 1].size() - 1] != s[i][0]) {
			chk = true;
			break;
		}
	}
	if (chk) cout << 0;
	else cout << 1;
}