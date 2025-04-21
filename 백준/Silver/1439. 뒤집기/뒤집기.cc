#include "bits/stdc++.h"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int sec[2];
string s;
int main() {
	FASTIO;
	cin >> s;
	bool chk = s[0] - '0';
	sec[chk]++;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			chk = !chk;
			sec[chk]++;
		}
	}
	cout << min(sec[0], sec[1]);
}